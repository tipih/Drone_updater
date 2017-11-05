#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtEndian>


#include <QDebug>
static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");
static const char update_message_id[] =("00,01");
bool robot_sel = 0;
#define dataSize 14

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    console = ui->uiConsole;


    status = new QLabel;
    ui->statusBar->addWidget(status);

    currentPid = new Pid_values();
    loggingWindow = new LogWindow();


    setup_connections();
    get_serial_ports();
    fillPortsParameters();
    ui->serialPortList->setCurrentIndex(0);

    loadSettings();
    ui->debugFrame->hide();
    loggingWindow->show();

    loggingWindow->raise();
    loggingWindow->activateWindow();
    setup_plot();




}

void   MainWindow::closeEvent(QCloseEvent*)
{
    saveSettings();
    qApp->quit();
}

MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::get_serial_ports()
{
    ui->serialPortList->clear();
    listOfPorts.clear();
    QString description;
    QString manufacturer;
    QString serialNumber;
    QStringList list;

    const auto infos = QSerialPortInfo::availablePorts();
        for (const QSerialPortInfo &info : infos) {

            list.clear();
            description = info.description();
            manufacturer = info.manufacturer();
            serialNumber = info.serialNumber();
            list << info.portName()
                 << (!description.isEmpty() ? description : blankString)
                 << (!manufacturer.isEmpty() ? manufacturer : blankString)
                 << (!serialNumber.isEmpty() ? serialNumber : blankString)
                 << info.systemLocation()
                 << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
                 << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

            listOfPorts.append(list);


            ui->serialPortList->addItem(info.portName());
        }


}

void MainWindow::setup_connections()
{
    connect(ui->Update_list,SIGNAL (released()),this,SLOT(update_comport_list()));
    connect(ui->serialPortList,SIGNAL(currentIndexChanged(int)),this,SLOT(new_port_selection(int)));
    connect(ui->ConnectBtn,SIGNAL(clicked(bool)),this,SLOT(open_serialport()));
    connect(ui->apply_settings,SIGNAL(clicked(bool)),this,SLOT(updateSettings()));

    //Connection for serial communication
    connect(console, SIGNAL(getData(QByteArray)), this, SLOT(writeData(QByteArray)));
    connect(serial,SIGNAL(readyRead()),this,SLOT(readData()));

    connect(ui->pitch_p_gain_spin,SIGNAL(valueChanged(double)),this,SLOT(updatePidValues()));
    connect(ui->pitch_i_gain_spin,SIGNAL(valueChanged(double)),this,SLOT(updatePidValues()));
    connect(ui->pitch_d_gain_spin,SIGNAL(valueChanged(double)),this,SLOT(updatePidValues()));

    connect(ui->roll_p_gain_spin,SIGNAL(valueChanged(double)),this,SLOT(updatePidValues()));
    connect(ui->roll_i_gain_spin,SIGNAL(valueChanged(double)),this,SLOT(updatePidValues()));
    connect(ui->roll_d_gain_spin,SIGNAL(valueChanged(double)),this,SLOT(updatePidValues()));

    connect(ui->yaw_p_gain_spin,SIGNAL(valueChanged(double)),this,SLOT(updatePidValues()));
    connect(ui->yaw_i_gain_spin,SIGNAL(valueChanged(double)),this,SLOT(updatePidValues()));
    connect(ui->yaw_d_gain_spin,SIGNAL(valueChanged(double)),this,SLOT(updatePidValues()));
}

QString MainWindow::convert_float_to_hex_to_string(float value)
{
qDebug()<<"Input Value" <<value;
QByteArray array(reinterpret_cast<const char*>(&value), sizeof(value));
QString return_string="";
int length = sizeof(value);

for (int a=0;a<length;a++){

    unsigned char myChar = array[a];
    QString myString = QString::number(myChar);


    if (length-a==1)
        return_string=return_string+myString;
    else
        return_string=return_string+myString+",";
    }

return return_string;
}

void MainWindow::update_comport_list()
{
    get_serial_ports();
    // fillPortsParameters(); //This is not needed
}

void MainWindow::new_port_selection(int index)
{
qDebug()<<index;
QStringList currentport;
currentport.clear();
if ((listOfPorts.count()<index) || (index==-1))
    return;
currentport = listOfPorts.at(index);
ui->description->setText(currentport.at(1));
ui->manufacturer->setText(currentport.at(2));
ui->serial_number->setText(currentport.at(3));
ui->location->setText(currentport.at(4));
currentSettings.name=currentport.at(0);


}



//Connect to selected serielport, with selected params
void MainWindow::open_serialport()
{
    updateSettings();

    serial->setPortName(currentSettings.name);
    serial->setBaudRate(currentSettings.baudRate);
    serial->setDataBits(currentSettings.dataBits);
    serial->setParity(currentSettings.parity);
    serial->setStopBits(currentSettings.stopBits);
    serial->setFlowControl(currentSettings.flowControl);

    if (serial->isOpen())
    {
        serial->close();
        ui->ConnectBtn->setText("Connect");
        status->setText("Not connected");
    }
    else
    {
    if (serial->open(QIODevice::ReadWrite)) {
        console->setEnabled(true);
        console->setLocalEchoEnabled(true);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6").arg(serial->portName()).arg(serial->baudRate()).arg(serial->flowControl()));
        ui->ConnectBtn->setText("Disconnect");
        ui->checkBox->setChecked(serial->isDataTerminalReady());


    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        showStatusMessage(tr("Open error"));
    }

  }
    serial->flush();
}




//Fill in the dropdownbox
void MainWindow::fillPortsParameters()
{

    ui->baudRateBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->baudRateBox->addItem(QStringLiteral("19200"),QSerialPort::Baud19200);
    ui->baudRateBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudRateBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);


    ui->dataBitsBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->dataBitsBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->dataBitsBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->dataBitsBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->dataBitsBox->setCurrentIndex(3);

    ui->parityBox->addItem(tr("None"),  QSerialPort::NoParity);
    ui->parityBox->addItem(tr("Even"),  QSerialPort::EvenParity);
    ui->parityBox->addItem(tr("Odd"),   QSerialPort::OddParity);
    ui->parityBox->addItem(tr("Mark"),  QSerialPort::MarkParity);
    ui->parityBox->addItem(tr("Space"), QSerialPort::SpaceParity);

    ui->stopBitsBox->addItem(QStringLiteral("1"), QSerialPort::OneStop);
#ifdef Q_OS_WIN
    ui->stopBitsBox->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
#endif
    ui->stopBitsBox->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    ui->flowControlBox->addItem(tr("None"),     QSerialPort::NoFlowControl);
    ui->flowControlBox->addItem(tr("RTS/CTS"),  QSerialPort::HardwareControl);
    ui->flowControlBox->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);
    updateSettings();
}

//Show what port we are connected to
void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}


//Slot for apply button
void MainWindow::updateSettings()
{
    currentSettings.name = ui->serialPortList->currentText();


    currentSettings.baudRate = static_cast<QSerialPort::BaudRate>(
                    ui->baudRateBox->itemData(ui->baudRateBox->currentIndex()).toInt());

    currentSettings.stringBaudRate = QString::number(currentSettings.baudRate);

    currentSettings.dataBits = static_cast<QSerialPort::DataBits>(
                ui->dataBitsBox->itemData(ui->dataBitsBox->currentIndex()).toInt());
    currentSettings.stringDataBits = ui->dataBitsBox->currentText();

    currentSettings.parity = static_cast<QSerialPort::Parity>(
                ui->parityBox->itemData(ui->parityBox->currentIndex()).toInt());
    currentSettings.stringParity = ui->parityBox->currentText();

    currentSettings.stopBits = static_cast<QSerialPort::StopBits>(
                ui->stopBitsBox->itemData(ui->stopBitsBox->currentIndex()).toInt());
    currentSettings.stringStopBits = ui->stopBitsBox->currentText();

    currentSettings.flowControl = static_cast<QSerialPort::FlowControl>(
                ui->flowControlBox->itemData(ui->flowControlBox->currentIndex()).toInt());
    currentSettings.stringFlowControl = ui->flowControlBox->currentText();

    currentSettings.localEchoEnabled = true;


}

//! [5]
void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
    console->setEnabled(false);
    ui->ConnectBtn->setText("Connect");
    showStatusMessage(tr("Disconnected"));
}
//! [5]

//! [6]
void MainWindow::writeData(const QByteArray &data)
{
    qDebug()<<"Data to send "<<data.toHex();
    if (serial->isOpen())
        serial->write(data);
}
//! [6]

//! [7]
void MainWindow::readData()
{

    //Wait ontil we have 14 bytes
    if (serial->bytesAvailable() < dataSize){
      //  qDebug()<<"Number of byte "<<  serial->bytesAvailable();
        //! If not, waiting for other bytes
           return;

}
    //Only readin 14 bytes
    //qDebug()<<"Data to read "<<serial->bytesAvailable();
    QByteArray data = serial->read(dataSize);
    //qDebug()<<" data "<<data.toHex();
    //Now check that the array has a start and the end data correct
    console->putData(data.toHex()+'\n');



    if((data[0]==(char)0x10) && (data[13]==(char)0xff)) //MIGHT BE AND ERROR HERE
    {

        //Do the convertion of the Data
       // qDebug()<<"Data 1 "<<converTofloat(data,1);
       // qDebug()<<"Data 2 "<<converTofloat(data,5);
        //qDebug()<<"Data 3 " <<converTofloat(data,9);
        emit updateLog(converTofloat(data,1),converTofloat(data,5),converTofloat(data,9));

    }
    else if((data[0]==(char)0x01) && (data[13]==(char)0xff)) //PID Data validation from Robot
    {
        //Do the convertion of the Data
        qDebug()<<"Data 1 "<<converTofloat(data,1);
        qDebug()<<"Data 2 "<<converTofloat(data,5);
        qDebug()<<"Data 3 " <<converTofloat(data,9);
        ui->pitch_p_gain_spin->setValue(converTofloat(data,1));
        ui->pitch_i_gain_spin->setValue(converTofloat(data,5));
        ui->pitch_d_gain_spin->setValue(converTofloat(data,9));

    }
    else if((data[0]==(char)0x02) && (data[13]==(char)0xff)) //PID Data validation from Robot
    {
    ui->balance_spin_box->setValue(converTofloat(data,1));
    }
    else
    {
     qDebug()<<"Error in data";
     serial->flush();
     serial->clear();
     data.clear();
    }
}
//! [7]

//! [8]
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}
//! [8]


void MainWindow::updatePidValues(){
    qDebug()<<"reading all PID values and updating the array";

    currentPid->pitch_p_value = (float)ui->pitch_p_gain_spin->value();
    currentPid->pitch_i_value = (float)ui->pitch_i_gain_spin->value();
    currentPid->pitch_d_value = (float)ui->pitch_d_gain_spin->value();

    currentPid->roll_p_value = (float)ui->roll_p_gain_spin->value();
    currentPid->roll_i_value = (float)ui->roll_i_gain_spin->value();
    currentPid->roll_d_value = (float)ui->roll_d_gain_spin->value();

    currentPid->yaw_p_value = (float)ui->yaw_p_gain_spin->value();
    currentPid->yaw_i_value = (float)ui->yaw_i_gain_spin->value();
    currentPid->yaw_d_value = (float)ui->yaw_d_gain_spin->value();

    //Send PID pitch value if this is Robot update
    if (ui->Robot_sel->isChecked())
        sendPidValue();


}







void MainWindow::sendPidValue(){
    QByteArray array;
    array.append((char)0x00);
    array.append( reinterpret_cast<const char*>(&currentPid->pitch_p_value), sizeof(currentPid->pitch_p_value) );
    array.append( reinterpret_cast<const char*>(&currentPid->pitch_i_value), sizeof(currentPid->pitch_i_value) );
    array.append( reinterpret_cast<const char*>(&currentPid->pitch_d_value), sizeof(currentPid->pitch_d_value) );
    array.append(0xff);

qDebug()<<array.count();
qDebug()<<"P "<<converTofloat(array,1);
qDebug()<<"I "<<converTofloat(array,5);
qDebug()<<"D" <<converTofloat(array,9);


writeData(array);

}



float MainWindow::converTofloat(QByteArray array, int index){

union UStuff
{
        float   f;
        unsigned char   c[0];
};

UStuff b;



for (int a=0; a<4;a++){
    b.c[a]=array.at(a+index);
}

return b.f;
}



void MainWindow::on_Robot_sel_clicked(bool checked)
{
    if (checked==true){
        ui->RollBox->hide();
        ui->YawBox->hide();
        ui->robot_balance_label->show();
        ui->balance_spin_box->show();
        this->setWindowTitle("Robot Updater");

        robot_sel=true;
    }
    else
    {
        ui->RollBox->show();
        ui->YawBox->show();
        ui->robot_balance_label->hide();
        ui->balance_spin_box->hide();

        this->setWindowTitle("Drone Updater");
        robot_sel=false;
    }
}


void MainWindow::on_checkBox_clicked(bool checked)
{

     serial->setDataTerminalReady(checked);
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString textToSend=ui->lineEdit->text();
    ui->lineEdit->clear();
    serial->write(textToSend.toUtf8());
}



void MainWindow::on_asc_show_clicked(bool checked)
{
    console->clear();
}

void MainWindow::setup_plot(){


    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer.start(0); // Interval 0 means to refresh as fast as possible


    connect(this,SIGNAL(updateLog(float,float,float)),loggingWindow,SLOT(updateLogs(float,float,float)));

}


void MainWindow::SetupLog1(){

}
void MainWindow::loadSettings(){
 QSettings settings;

QString comPort = settings.value    ("serial/comport","").toString();
QString baudRate = settings.value   ("serial/baudRate","9600").toString();
QString dataBit = settings.value    ("serial/dataBit","8").toString();
QString flowControl = settings.value("serial/flowControl","None").toString();
QString parity = settings.value     ("serial/parity","None").toString();
QString stopBits = settings.value   ("serial/stopBits","1").toString();

qDebug()<<comPort<<" "<<baudRate<<" "<<dataBit<<" "<<flowControl<<" "<<parity<<" "<<stopBits;


ui->serialPortList->setCurrentIndex(ui->serialPortList->findText(comPort));
ui->baudRateBox->setCurrentIndex(ui->baudRateBox->findText(baudRate));
ui->dataBitsBox->setCurrentIndex(ui->dataBitsBox->findText(dataBit));
ui->flowControlBox->setCurrentIndex(ui->flowControlBox->findText(flowControl));
ui->parityBox->setCurrentIndex(ui->parityBox->findText(parity));
ui->stopBitsBox->setCurrentIndex(ui->stopBitsBox->findText(stopBits));
ui->Robot_sel->setChecked(settings.value("serial/robot",true).toBool());

ui->pitch_p_gain_spin->setValue(settings.value("pidsettings/pitchP","1.30").toFloat());
ui->pitch_i_gain_spin->setValue(settings.value("pidsettings/pitchI","0.30").toFloat());
ui->pitch_d_gain_spin->setValue(settings.value("pidsettings/pitchD","15.0").toFloat());

ui->roll_p_gain_spin->setValue(settings.value("pidsettings/rollP","1.30").toFloat());
ui->roll_i_gain_spin->setValue(settings.value("pidsettings/rollI","0.00").toFloat());
ui->roll_d_gain_spin->setValue(settings.value("pidsettings/rollD","15.0").toFloat());

ui->yaw_p_gain_spin->setValue(settings.value("pidsettings/yawP","4.30").toFloat());
ui->yaw_i_gain_spin->setValue(settings.value("pidsettings/yawI","0.30").toFloat());
ui->yaw_d_gain_spin->setValue(settings.value("pidsettings/yawD","0.00").toFloat());


}

void MainWindow::saveSettings(){
    QSettings settings;
qDebug()<<"Save Settings "<< ui->serialPortList->currentText();
qDebug()<<"Baud Rate "<<ui->baudRateBox->currentText();




settings.setValue("serial/comport", ui->serialPortList->currentText());
settings.setValue("serial/baudRate",ui->baudRateBox->currentText());
settings.setValue("serial/dataBit", ui->dataBitsBox->currentText());
settings.setValue("serial/flowControl",ui->flowControlBox->currentText());
settings.setValue("serial/parity", ui->parityBox->currentText());
settings.setValue("serial/stopBits",ui->stopBitsBox->currentText());
settings.setValue("serial/robot",ui->Robot_sel->isChecked());

settings.setValue("pidsettings/pitchP",currentPid->pitch_p_value);
settings.setValue("pidsettings/pitchI",currentPid->pitch_i_value);
settings.setValue("pidsettings/pitchD",currentPid->pitch_d_value);
settings.setValue("pidsettings/rollP",currentPid->roll_p_value);
settings.setValue("pidsettings/rollI",currentPid->roll_i_value);
settings.setValue("pidsettings/rollD",currentPid->roll_d_value);
settings.setValue("pidsettings/yawP",currentPid->yaw_p_value);
settings.setValue("pidsettings/yawI",currentPid->yaw_i_value);
settings.setValue("pidsettings/yawD",currentPid->yaw_d_value);


settings.sync();
qDebug()<<"FlowControl "<<ui->flowControlBox->currentText();
qDebug()<<"parity "<<ui->parityBox->currentText();
qDebug()<<"DataBIts "<< ui->dataBitsBox->currentText();
qDebug()<<"Settings status "<<settings.status();

qDebug()<<settings.value("serial/baudRate").toString();
qDebug()<<settings.value("serial/dataBit").toString();
qDebug()<<settings.value("serial/flowControl").toString();
qDebug()<<settings.value("serial/parity").toString();
qDebug()<<settings.value("serial/stopBits").toString();

settings.sync();
}



void MainWindow::realtimeDataSlot()
{


#ifdef dummy_data

    static QTime time(QTime::currentTime());
  // calculate two new data points:
  double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
  static double lastPointKey = 0;
  emit updateLog(qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.2843),qSin(key)+qrand()/(double)RAND_MAX*0.7*qSin(key/0.4843),qSin(key)+qrand()/(double)RAND_MAX*0.5*qSin(key/0.5843));

  if (key-lastPointKey > 0.002) // at most add point every 2 ms
  {
    // add data to lines:
    ui->customPlot->graph(0)->addData(key, qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.3843));
    ui->customPlot->graph(1)->addData(key, qCos(key)+qrand()/(double)RAND_MAX*0.5*qSin(key/0.4364));
    // rescale value (vertical) axis to fit the current data:
    //ui->customPlot->graph(0)->rescaleValueAxis();
    //ui->customPlot->graph(1)->rescaleValueAxis(true);
    lastPointKey = key;
  }
  // make key axis range scroll with the data (at a constant range size of 8):
  ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
  ui->customPlot->replot();

  // calculate frames per second:
  static double lastFpsKey;
  static int frameCount;
  ++frameCount;
  if (key-lastFpsKey > 2) // average fps over 2 seconds
  {
    ui->statusBar->showMessage(
          QString("%1 FPS, Total Data points: %2")
          .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
          .arg(ui->customPlot->graph(0)->data()->size()+ui->customPlot->graph(1)->data()->size())
          , 0);
    lastFpsKey = key;
    frameCount = 0;
  }
#endif
}



void MainWindow::on_Robot_sel_stateChanged(int arg1)
{
   emit on_Robot_sel_clicked(arg1);
}



void MainWindow::on_ConnectBtn_clicked()
{

}

void MainWindow::on_sendData_clicked(bool checked)
{
    QByteArray array;
    array.append((char)0x02);
    if (checked==true){
    array.append((char)0x01);
    }
    else
   {
        array.append((char)0x00);
   }


    array.append((char)0x00);
    array.append((char)0x00);
    array.append((char)0x00);

    array.append((char)0x00);
    array.append((char)0x00);
    array.append((char)0x00);
    array.append((char)0x00);

    array.append((char)0x00);
    array.append((char)0x00);
    array.append((char)0x00);
    array.append((char)0x00);

    array.append(0xff);
qDebug()<<array.toHex();
writeData(array);
serial->flush();
}

void MainWindow::on_balance_spin_box_valueChanged(double arg1)
{

QByteArray spin_array;
float spin = ui->balance_spin_box->value();
spin_array.append((char)0x03);
spin_array.append( reinterpret_cast<const char*>(&spin), sizeof(spin) );
spin_array.append( reinterpret_cast<const char*>(&spin), sizeof(spin) );
spin_array.append( reinterpret_cast<const char*>(&spin), sizeof(spin) );
spin_array.append((char)0xff);
writeData(spin_array);
serial->flush();

}

void MainWindow::on_SendTest_clicked()
{


    quint32 a=1;
    quint32 b=2;
    quint32 c=3;
    float a1 = 1.1;
    unsigned char *ptr;
    unsigned char *ptr1;
    unsigned char mArray[4];
    unsigned char mArray1[4];
    ptr=mArray;
    ptr1=mArray1;

    qToBigEndian<float>(a1, ptr);
    qToLittleEndian<float>(a1,ptr1);

    QByteArray testSendLong;

    testSendLong.append((char)0x04);
    testSendLong.append(reinterpret_cast<const char*>(ptr1),sizeof(ptr1));
    testSendLong.append(reinterpret_cast<const char*>(ptr),sizeof(ptr));
    testSendLong.append(reinterpret_cast<const char*>(&c),sizeof(c));
    testSendLong.append((char)0xff);



    qDebug()<<"output of test="<<ptr;

    qDebug()<<testSendLong.size();
    writeData(testSendLong);
    serial->flush();


}

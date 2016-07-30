#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include <QDebug>
static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");
static const char update_message_id[] =("00,01");

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

    setup_connections();
    get_serial_ports();
    fillPortsParameters();
    ui->serialPortList->setCurrentIndex(0);
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
        console->setLocalEchoEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6").arg(serial->portName()).arg(serial->baudRate()).arg(serial->flowControl()));
        ui->ConnectBtn->setText("Disconnect");


    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        showStatusMessage(tr("Open error"));
    }

  }
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
    if (serial->isOpen())
        serial->write(data);
}
//! [6]

//! [7]
void MainWindow::readData()
{
    QByteArray data = serial->readAll();
    console->putData(data);
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

    qDebug()<<currentPid;
}


void MainWindow::on_pushButton_clicked()
{

updatePidValues();
//Build op the string for sending to the RFM2PI via seriel

QString serial_string="";
serial_string=update_message_id;

serial_string = serial_string+","+convert_float_to_hex_to_string(currentPid->pitch_p_value);
serial_string = serial_string+","+convert_float_to_hex_to_string(currentPid->pitch_i_value);
serial_string = serial_string+","+convert_float_to_hex_to_string(currentPid->pitch_d_value);

serial_string = serial_string+","+convert_float_to_hex_to_string(currentPid->roll_p_value);
serial_string = serial_string+","+convert_float_to_hex_to_string(currentPid->roll_i_value);
serial_string = serial_string+","+convert_float_to_hex_to_string(currentPid->roll_d_value);

serial_string = serial_string+","+convert_float_to_hex_to_string(currentPid->yaw_p_value);
serial_string = serial_string+","+convert_float_to_hex_to_string(currentPid->yaw_i_value);
serial_string = serial_string+","+convert_float_to_hex_to_string(currentPid->yaw_d_value);

serial_string=serial_string+","+"s";
qDebug()<<"String to send "<<serial_string;
QByteArray array (serial_string.toStdString().c_str());


QByteArray source = QString("3f8ccccd").toUtf8();
quint16 crc1 = qChecksum(source.data(), source.length());
qDebug()<<"Bytearray "<<source.data();
qDebug() <<"crc1" <<crc1;

//1,1 = 0x3f8ccccd
//float f = 1.1f;
//convert_float_to_hex_to_string(f);
//unsigned char *chptr;
//chptr = (unsigned char *) &f;
// qDebug() <<"1="<<*chptr++<<" 2="<<*chptr++<<"3="<<*chptr++<<"4="<<*chptr++;
// QByteArray array(reinterpret_cast<const char*>(&f), sizeof(f));
// qDebug() << array.size();
//float f2;
//f2 = *reinterpret_cast<const float*>(array.data());
//qDebug()<<f2;
//QString myString=QString::number(currentPid->pitch_p_value)+","+QString::number(currentPid->pitch_i_value)+","+QString::number(currentPid->pitch_d_value)+",s";
//QByteArray packet (myString.toStdString().c_str());

//char *p = (char*)currentPid; // cast it to char* to make a QByteArray
//QByteArray packet(p, sizeof(Pid_values));

writeData(array);

}

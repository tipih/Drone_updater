#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include <QDebug>
static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    console = ui->uiConsole;

    status = new QLabel;
    ui->statusBar->addWidget(status);

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

void MainWindow::on_pushButton_clicked()
{

currentPid = new Pid_values();
currentPid->p_value=10;
currentPid->i_value=20;
currentPid->d_value=30;

QString myString=QString::number(currentPid->p_value)+","+QString::number(currentPid->i_value)+","+QString::number(currentPid->d_value)+",s";
QByteArray packet (myString.toStdString().c_str());

//char *p = (char*)currentPid; // cast it to char* to make a QByteArray
//QByteArray packet(p, sizeof(Pid_values));

writeData(packet);
qDebug() << packet.size();
}

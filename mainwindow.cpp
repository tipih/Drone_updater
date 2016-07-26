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


            ui->serialPortList->addItem(description);
        }


}

void MainWindow::setup_connections()
{
    connect(ui->Update_list,SIGNAL (released()),this,SLOT(update_comport_list()));
    connect(ui->serialPortList,SIGNAL(currentIndexChanged(int)),this,SLOT(new_port_selection(int)));
    connect(ui->ConnectBtn,SIGNAL(clicked(bool)),this,SLOT(open_serialport()));
}

void MainWindow::update_comport_list()
{
    get_serial_ports();
    fillPortsParameters();
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
serial->setPortName(currentport.at(0));


}


void MainWindow::open_serialport()
{

    //serial->setPortName(p.name);
    //serial->setBaudRate(p.baudRate);
    //serial->setDataBits(p.dataBits);
    //serial->setParity(p.parity);
    //serial->setStopBits(p.stopBits);
    //serial->setFlowControl(p.flowControl);

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


    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        showStatusMessage(tr("Open error"));
    }

  }
}




void MainWindow::fillPortsParameters()
{
    ui->baudRateBox->addItem(QStringLiteral("9600"), serial->setBaudRate(QSerialPort::Baud9600));
    ui->baudRateBox->addItem(QStringLiteral("19200"),serial->setBaudRate(QSerialPort::Baud19200));
    ui->baudRateBox->addItem(QStringLiteral("38400"), serial->setBaudRate(QSerialPort::Baud38400));
    ui->baudRateBox->addItem(QStringLiteral("115200"), serial->setBaudRate(QSerialPort::Baud115200));


    ui->dataBitsBox->addItem(QStringLiteral("5"), serial->Data5);
    ui->dataBitsBox->addItem(QStringLiteral("6"), serial->Data6);
    ui->dataBitsBox->addItem(QStringLiteral("7"), serial->Data7);
    ui->dataBitsBox->addItem(QStringLiteral("8"), serial->Data8);
    ui->dataBitsBox->setCurrentIndex(3);

    ui->parityBox->addItem(tr("None"), serial->NoParity);
    ui->parityBox->addItem(tr("Even"), serial->EvenParity);
    ui->parityBox->addItem(tr("Odd"), serial->OddParity);
    ui->parityBox->addItem(tr("Mark"), serial->MarkParity);
    ui->parityBox->addItem(tr("Space"), serial->SpaceParity);

    ui->stopBitsBox->addItem(QStringLiteral("1"), serial->OneStop);
#ifdef Q_OS_WIN
    ui->stopBitsBox->addItem(tr("1.5"), serial->OneAndHalfStop);
#endif
    ui->stopBitsBox->addItem(QStringLiteral("2"), serial->TwoStop);

    ui->flowControlBox->addItem(tr("None"), serial->NoFlowControl);
    ui->flowControlBox->addItem(tr("RTS/CTS"), serial->HardwareControl);
    ui->flowControlBox->addItem(tr("XON/XOFF"), serial->SoftwareControl);
}

void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}

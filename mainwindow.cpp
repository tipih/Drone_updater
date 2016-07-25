#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QtSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_connections();
    get_serial_ports();
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
    //connect(ui->serialPortList, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
    //        this, SLOT(new_port_selection(int)));
}

void MainWindow::update_comport_list()
{
    get_serial_ports();
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


}

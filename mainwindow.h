#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>
#include <QSerialPortInfo>
#include "console.h"
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<QStringList> listOfPorts;
    bool connection_status;
    QSerialPort *serial;
    Console *console;
    QLabel *status;
    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
        bool localEchoEnabled;
    };

    //Private functions
    void get_serial_ports();
    void setup_connections();
    void fillPortsParameters();
    void showStatusMessage(const QString &message);

private slots:
 void update_comport_list();
 void new_port_selection(int index);
 void open_serialport();

};




#endif // MAINWINDOW_H

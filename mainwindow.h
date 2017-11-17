#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//Test
#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>
#include <QSerialPortInfo>
#include "console.h"
#include <QLabel>
#include "qcustomplot.h"
#include "logwindow.h"
#include <QSettings>

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
    LogWindow *loggingWindow;

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
    Settings currentSettings;

    struct Pid_values {
    float pitch_p_value;
    float pitch_i_value;
    float pitch_d_value;
    float roll_p_value;
    float roll_i_value;
    float roll_d_value;
    float yaw_p_value;
    float yaw_i_value;
    float yaw_d_value;
    };
    Pid_values *currentPid;

    //Private functions
    void get_serial_ports();
    void setup_connections();
    void fillPortsParameters();
    void showStatusMessage(const QString &message);
    QString convert_float_to_hex_to_string(float value);

private:
    float converTofloat(QByteArray array,int index);
    void setup_plot();
    void loadSettings();
    void saveSettings();
    QTimer dataTimer;
    QString m_sSettingsFile;



private slots:
 void update_comport_list();
 void new_port_selection(int index);
 void open_serialport();
 void closeSerialPort();
 void updateSettings();

 void writeData(const QByteArray &data);
 void readData();
 void handleError(QSerialPort::SerialPortError error);
 void updatePidValues();
 void sendPidValue();


 void on_Robot_sel_clicked(bool checked);
 void on_checkBox_clicked(bool checked);
 void on_lineEdit_returnPressed();
 void on_asc_show_clicked(bool checked);
 void realtimeDataSlot();


 void SetupLog1();

 void on_Robot_sel_stateChanged(int arg1);


 void on_ConnectBtn_clicked();

 void on_sendData_clicked(bool checked);

 void on_balance_spin_box_valueChanged(double arg1);

 void on_SendTest_clicked();

 void on_checkBox_clicked();

signals:
 void updateLog(float l1,float l2,float l3);

protected:
 void closeEvent(QCloseEvent *);
};




#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    //Private functions
    void get_serial_ports();
    void setup_connections();

private slots:
 void update_comport_list();
 void new_port_selection(int index);
};




#endif // MAINWINDOW_H

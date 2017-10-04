#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QWidget>

namespace Ui {
class LogWindow;
}

class LogWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LogWindow(QWidget *parent = 0);
    ~LogWindow();

public slots:
    void updateLogs(float lg1, float lg2, float lg3);
    void setupLogs();
private:
    Ui::LogWindow *ui;


};

#endif // LOGWINDOW_H

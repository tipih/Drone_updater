#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
  //QApplication::setGraphicsSystem("raster");
#endif
    QApplication a(argc, argv);
    a.setOrganizationName("Rahr Soft");
    a.setOrganizationDomain("Rahr_soft.com");
    a.setApplicationName("Drone Updater");
    MainWindow w;
    w.show();

    return a.exec();
}

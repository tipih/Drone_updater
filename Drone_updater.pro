#-------------------------------------------------
#
# Project created by QtCreator 2016-07-24T12:20:07
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Drone_updater
TEMPLATE = app
-Wno-inconsistent-missing-override

SOURCES += main.cpp\
        mainwindow.cpp \
    console.cpp \
    qcustomplot.cpp \
    logwindow.cpp


HEADERS  += mainwindow.h \
    console.h \
    qcustomplot.h \
    logwindow.h


FORMS    += mainwindow.ui \
    logwindow.ui

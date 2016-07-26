#-------------------------------------------------
#
# Project created by QtCreator 2016-07-24T12:20:07
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Drone_updater
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    console.cpp

HEADERS  += mainwindow.h \
    console.h

FORMS    += mainwindow.ui

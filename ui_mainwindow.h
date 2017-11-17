/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "console.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QComboBox *serialPortList;
    QPushButton *ConnectBtn;
    QComboBox *baudRateBox;
    QComboBox *dataBitsBox;
    QComboBox *parityBox;
    QComboBox *stopBitsBox;
    QFrame *debugFrame;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *description;
    QLabel *manufacturer;
    QLabel *serial_number;
    QLabel *location;
    QPushButton *Update_list;
    QComboBox *flowControlBox;
    QPushButton *apply_settings;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QCheckBox *Robot_sel;
    QCheckBox *checkBox;
    QCheckBox *asc_show;
    QCheckBox *sendData;
    Console *uiConsole;
    QFrame *frame_3;
    QGroupBox *PicthBox;
    QLabel *pitch_p_gain_label;
    QLabel *pitch_i_gain_label;
    QLabel *pitch_d_gain_label_2;
    QDoubleSpinBox *pitch_p_gain_spin;
    QDoubleSpinBox *pitch_i_gain_spin;
    QDoubleSpinBox *pitch_d_gain_spin;
    QGroupBox *RollBox;
    QLabel *roll_p_gain_label;
    QLabel *roll_i_gain_label;
    QLabel *roll_d_gain_label_3;
    QDoubleSpinBox *roll_p_gain_spin;
    QDoubleSpinBox *roll_i_gain_spin;
    QDoubleSpinBox *roll_d_gain_spin;
    QGroupBox *YawBox;
    QLabel *yaw_p_gain_label;
    QLabel *yaw_i_gain_label_2;
    QLabel *yaw_d_gain_label_4;
    QDoubleSpinBox *yaw_p_gain_spin;
    QDoubleSpinBox *yaw_i_gain_spin;
    QDoubleSpinBox *yaw_d_gain_spin;
    QLabel *robot_balance_label;
    QDoubleSpinBox *balance_spin_box;
    QLineEdit *lineEdit;
    QPushButton *SendTest;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(981, 714);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 0, 961, 151));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        serialPortList = new QComboBox(frame);
        serialPortList->setObjectName(QStringLiteral("serialPortList"));
        serialPortList->setGeometry(QRect(0, 0, 221, 31));
        ConnectBtn = new QPushButton(frame);
        ConnectBtn->setObjectName(QStringLiteral("ConnectBtn"));
        ConnectBtn->setGeometry(QRect(0, 50, 221, 31));
        baudRateBox = new QComboBox(frame);
        baudRateBox->setObjectName(QStringLiteral("baudRateBox"));
        baudRateBox->setGeometry(QRect(370, 0, 104, 31));
        dataBitsBox = new QComboBox(frame);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));
        dataBitsBox->setGeometry(QRect(370, 30, 104, 31));
        parityBox = new QComboBox(frame);
        parityBox->setObjectName(QStringLiteral("parityBox"));
        parityBox->setGeometry(QRect(370, 60, 104, 31));
        stopBitsBox = new QComboBox(frame);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));
        stopBitsBox->setGeometry(QRect(370, 90, 104, 31));
        debugFrame = new QFrame(frame);
        debugFrame->setObjectName(QStringLiteral("debugFrame"));
        debugFrame->setGeometry(QRect(650, 10, 301, 131));
        debugFrame->setMinimumSize(QSize(200, 100));
        debugFrame->setFrameShape(QFrame::StyledPanel);
        debugFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(debugFrame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        description = new QLabel(debugFrame);
        description->setObjectName(QStringLiteral("description"));

        verticalLayout->addWidget(description);

        manufacturer = new QLabel(debugFrame);
        manufacturer->setObjectName(QStringLiteral("manufacturer"));

        verticalLayout->addWidget(manufacturer);

        serial_number = new QLabel(debugFrame);
        serial_number->setObjectName(QStringLiteral("serial_number"));

        verticalLayout->addWidget(serial_number);

        location = new QLabel(debugFrame);
        location->setObjectName(QStringLiteral("location"));

        verticalLayout->addWidget(location);


        verticalLayout_2->addLayout(verticalLayout);

        Update_list = new QPushButton(frame);
        Update_list->setObjectName(QStringLiteral("Update_list"));
        Update_list->setGeometry(QRect(0, 80, 221, 31));
        flowControlBox = new QComboBox(frame);
        flowControlBox->setObjectName(QStringLiteral("flowControlBox"));
        flowControlBox->setGeometry(QRect(370, 120, 104, 31));
        apply_settings = new QPushButton(frame);
        apply_settings->setObjectName(QStringLiteral("apply_settings"));
        apply_settings->setGeometry(QRect(0, 110, 221, 31));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 5, 81, 20));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 36, 81, 20));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(290, 65, 81, 20));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(290, 93, 81, 20));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(290, 125, 81, 20));
        Robot_sel = new QCheckBox(frame);
        Robot_sel->setObjectName(QStringLiteral("Robot_sel"));
        Robot_sel->setGeometry(QRect(490, 50, 111, 20));
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(490, 10, 87, 20));
        asc_show = new QCheckBox(frame);
        asc_show->setObjectName(QStringLiteral("asc_show"));
        asc_show->setGeometry(QRect(490, 30, 87, 20));
        sendData = new QCheckBox(frame);
        sendData->setObjectName(QStringLiteral("sendData"));
        sendData->setGeometry(QRect(490, 70, 81, 20));
        uiConsole = new Console(centralWidget);
        uiConsole->setObjectName(QStringLiteral("uiConsole"));
        uiConsole->setGeometry(QRect(360, 220, 611, 381));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(10, 160, 331, 441));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        PicthBox = new QGroupBox(frame_3);
        PicthBox->setObjectName(QStringLiteral("PicthBox"));
        PicthBox->setGeometry(QRect(10, 10, 311, 111));
        pitch_p_gain_label = new QLabel(PicthBox);
        pitch_p_gain_label->setObjectName(QStringLiteral("pitch_p_gain_label"));
        pitch_p_gain_label->setGeometry(QRect(10, 30, 59, 16));
        pitch_i_gain_label = new QLabel(PicthBox);
        pitch_i_gain_label->setObjectName(QStringLiteral("pitch_i_gain_label"));
        pitch_i_gain_label->setGeometry(QRect(110, 30, 59, 16));
        pitch_d_gain_label_2 = new QLabel(PicthBox);
        pitch_d_gain_label_2->setObjectName(QStringLiteral("pitch_d_gain_label_2"));
        pitch_d_gain_label_2->setGeometry(QRect(210, 30, 59, 16));
        pitch_p_gain_spin = new QDoubleSpinBox(PicthBox);
        pitch_p_gain_spin->setObjectName(QStringLiteral("pitch_p_gain_spin"));
        pitch_p_gain_spin->setGeometry(QRect(10, 60, 81, 24));
        pitch_p_gain_spin->setAccelerated(true);
        pitch_p_gain_spin->setMaximum(30);
        pitch_p_gain_spin->setSingleStep(0.1);
        pitch_p_gain_spin->setValue(1.3);
        pitch_i_gain_spin = new QDoubleSpinBox(PicthBox);
        pitch_i_gain_spin->setObjectName(QStringLiteral("pitch_i_gain_spin"));
        pitch_i_gain_spin->setGeometry(QRect(110, 60, 81, 24));
        pitch_i_gain_spin->setAccelerated(true);
        pitch_i_gain_spin->setMaximum(30);
        pitch_i_gain_spin->setSingleStep(0.1);
        pitch_i_gain_spin->setValue(0.05);
        pitch_d_gain_spin = new QDoubleSpinBox(PicthBox);
        pitch_d_gain_spin->setObjectName(QStringLiteral("pitch_d_gain_spin"));
        pitch_d_gain_spin->setGeometry(QRect(210, 60, 81, 24));
        pitch_d_gain_spin->setAccelerated(true);
        pitch_d_gain_spin->setMaximum(50);
        pitch_d_gain_spin->setSingleStep(0.1);
        pitch_d_gain_spin->setValue(15);
        RollBox = new QGroupBox(frame_3);
        RollBox->setObjectName(QStringLiteral("RollBox"));
        RollBox->setGeometry(QRect(10, 130, 311, 111));
        roll_p_gain_label = new QLabel(RollBox);
        roll_p_gain_label->setObjectName(QStringLiteral("roll_p_gain_label"));
        roll_p_gain_label->setGeometry(QRect(10, 30, 59, 16));
        roll_i_gain_label = new QLabel(RollBox);
        roll_i_gain_label->setObjectName(QStringLiteral("roll_i_gain_label"));
        roll_i_gain_label->setGeometry(QRect(110, 30, 59, 16));
        roll_d_gain_label_3 = new QLabel(RollBox);
        roll_d_gain_label_3->setObjectName(QStringLiteral("roll_d_gain_label_3"));
        roll_d_gain_label_3->setGeometry(QRect(210, 30, 59, 16));
        roll_p_gain_spin = new QDoubleSpinBox(RollBox);
        roll_p_gain_spin->setObjectName(QStringLiteral("roll_p_gain_spin"));
        roll_p_gain_spin->setGeometry(QRect(10, 60, 81, 24));
        roll_p_gain_spin->setAccelerated(true);
        roll_p_gain_spin->setMaximum(30);
        roll_p_gain_spin->setSingleStep(0.1);
        roll_p_gain_spin->setValue(1.3);
        roll_i_gain_spin = new QDoubleSpinBox(RollBox);
        roll_i_gain_spin->setObjectName(QStringLiteral("roll_i_gain_spin"));
        roll_i_gain_spin->setGeometry(QRect(110, 60, 81, 24));
        roll_i_gain_spin->setAccelerated(true);
        roll_i_gain_spin->setMaximum(30);
        roll_i_gain_spin->setSingleStep(0.1);
        roll_i_gain_spin->setValue(0.05);
        roll_d_gain_spin = new QDoubleSpinBox(RollBox);
        roll_d_gain_spin->setObjectName(QStringLiteral("roll_d_gain_spin"));
        roll_d_gain_spin->setGeometry(QRect(210, 60, 81, 24));
        roll_d_gain_spin->setAccelerated(true);
        roll_d_gain_spin->setMaximum(50);
        roll_d_gain_spin->setSingleStep(0.1);
        roll_d_gain_spin->setValue(15);
        YawBox = new QGroupBox(frame_3);
        YawBox->setObjectName(QStringLiteral("YawBox"));
        YawBox->setGeometry(QRect(10, 250, 311, 111));
        yaw_p_gain_label = new QLabel(YawBox);
        yaw_p_gain_label->setObjectName(QStringLiteral("yaw_p_gain_label"));
        yaw_p_gain_label->setGeometry(QRect(10, 30, 59, 16));
        yaw_i_gain_label_2 = new QLabel(YawBox);
        yaw_i_gain_label_2->setObjectName(QStringLiteral("yaw_i_gain_label_2"));
        yaw_i_gain_label_2->setGeometry(QRect(110, 30, 59, 16));
        yaw_d_gain_label_4 = new QLabel(YawBox);
        yaw_d_gain_label_4->setObjectName(QStringLiteral("yaw_d_gain_label_4"));
        yaw_d_gain_label_4->setGeometry(QRect(210, 30, 59, 16));
        yaw_p_gain_spin = new QDoubleSpinBox(YawBox);
        yaw_p_gain_spin->setObjectName(QStringLiteral("yaw_p_gain_spin"));
        yaw_p_gain_spin->setGeometry(QRect(10, 60, 81, 24));
        yaw_p_gain_spin->setAccelerated(true);
        yaw_p_gain_spin->setMaximum(30);
        yaw_p_gain_spin->setSingleStep(0.1);
        yaw_p_gain_spin->setValue(4);
        yaw_i_gain_spin = new QDoubleSpinBox(YawBox);
        yaw_i_gain_spin->setObjectName(QStringLiteral("yaw_i_gain_spin"));
        yaw_i_gain_spin->setGeometry(QRect(110, 60, 81, 24));
        yaw_i_gain_spin->setAccelerated(true);
        yaw_i_gain_spin->setMaximum(30);
        yaw_i_gain_spin->setSingleStep(0.1);
        yaw_i_gain_spin->setValue(0.02);
        yaw_d_gain_spin = new QDoubleSpinBox(YawBox);
        yaw_d_gain_spin->setObjectName(QStringLiteral("yaw_d_gain_spin"));
        yaw_d_gain_spin->setGeometry(QRect(210, 60, 81, 24));
        yaw_d_gain_spin->setAccelerated(true);
        yaw_d_gain_spin->setMaximum(50);
        yaw_d_gain_spin->setSingleStep(0.1);
        yaw_d_gain_spin->setValue(0);
        robot_balance_label = new QLabel(frame_3);
        robot_balance_label->setObjectName(QStringLiteral("robot_balance_label"));
        robot_balance_label->setGeometry(QRect(20, 380, 91, 16));
        balance_spin_box = new QDoubleSpinBox(frame_3);
        balance_spin_box->setObjectName(QStringLiteral("balance_spin_box"));
        balance_spin_box->setGeometry(QRect(20, 400, 291, 22));
        balance_spin_box->setMinimum(-5);
        balance_spin_box->setMaximum(5);
        balance_spin_box->setSingleStep(0.1);
        balance_spin_box->setValue(1.6);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(360, 160, 611, 31));
        SendTest = new QPushButton(centralWidget);
        SendTest->setObjectName(QStringLiteral("SendTest"));
        SendTest->setGeometry(QRect(30, 610, 291, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 981, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Drone Updater", Q_NULLPTR));
        ConnectBtn->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        description->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        manufacturer->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        serial_number->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        location->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        Update_list->setText(QApplication::translate("MainWindow", "Refress comport list", Q_NULLPTR));
        apply_settings->setText(QApplication::translate("MainWindow", "Apply settings", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Baudrate", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Databit", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Parity", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Stopbit", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Flowcontrol", Q_NULLPTR));
        Robot_sel->setText(QApplication::translate("MainWindow", "Robot / Drone", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "DTR", Q_NULLPTR));
        asc_show->setText(QApplication::translate("MainWindow", "Show Hex", Q_NULLPTR));
        sendData->setText(QApplication::translate("MainWindow", "Send data", Q_NULLPTR));
        PicthBox->setTitle(QApplication::translate("MainWindow", "Pitch Gain Box", Q_NULLPTR));
        pitch_p_gain_label->setText(QApplication::translate("MainWindow", "P-Gain", Q_NULLPTR));
        pitch_i_gain_label->setText(QApplication::translate("MainWindow", "I-Gain", Q_NULLPTR));
        pitch_d_gain_label_2->setText(QApplication::translate("MainWindow", "D-Gain", Q_NULLPTR));
        RollBox->setTitle(QApplication::translate("MainWindow", "Roll Gain Box", Q_NULLPTR));
        roll_p_gain_label->setText(QApplication::translate("MainWindow", "P-Gain", Q_NULLPTR));
        roll_i_gain_label->setText(QApplication::translate("MainWindow", "I-Gain", Q_NULLPTR));
        roll_d_gain_label_3->setText(QApplication::translate("MainWindow", "D-Gain", Q_NULLPTR));
        YawBox->setTitle(QApplication::translate("MainWindow", "Yaw Gain Box", Q_NULLPTR));
        yaw_p_gain_label->setText(QApplication::translate("MainWindow", "P-Gain", Q_NULLPTR));
        yaw_i_gain_label_2->setText(QApplication::translate("MainWindow", "I-Gain", Q_NULLPTR));
        yaw_d_gain_label_4->setText(QApplication::translate("MainWindow", "D-Gain", Q_NULLPTR));
        robot_balance_label->setText(QApplication::translate("MainWindow", "Balance Point", Q_NULLPTR));
        SendTest->setText(QApplication::translate("MainWindow", "Save To EEprom", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
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
#include <console.h>

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
    QFrame *frame_2;
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
    QPushButton *pushButton;
    QCheckBox *Robot_sel;
    QCheckBox *checkBox;
    QCheckBox *asc_show;
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
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(981, 608);
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
        ConnectBtn->setGeometry(QRect(0, 30, 221, 51));
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
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(650, 10, 301, 131));
        frame_2->setMinimumSize(QSize(200, 100));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        description = new QLabel(frame_2);
        description->setObjectName(QStringLiteral("description"));

        verticalLayout->addWidget(description);

        manufacturer = new QLabel(frame_2);
        manufacturer->setObjectName(QStringLiteral("manufacturer"));

        verticalLayout->addWidget(manufacturer);

        serial_number = new QLabel(frame_2);
        serial_number->setObjectName(QStringLiteral("serial_number"));

        verticalLayout->addWidget(serial_number);

        location = new QLabel(frame_2);
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
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(490, 0, 113, 32));
        Robot_sel = new QCheckBox(frame);
        Robot_sel->setObjectName(QStringLiteral("Robot_sel"));
        Robot_sel->setGeometry(QRect(490, 120, 111, 20));
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(490, 80, 87, 20));
        asc_show = new QCheckBox(frame);
        asc_show->setObjectName(QStringLiteral("asc_show"));
        asc_show->setGeometry(QRect(490, 100, 87, 20));
        uiConsole = new Console(centralWidget);
        uiConsole->setObjectName(QStringLiteral("uiConsole"));
        uiConsole->setGeometry(QRect(360, 220, 611, 321));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(10, 160, 331, 371));
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
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(360, 160, 611, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 981, 22));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Drone Updater", nullptr));
        ConnectBtn->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        description->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        manufacturer->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        serial_number->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        location->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        Update_list->setText(QApplication::translate("MainWindow", "Refress comport list", nullptr));
        apply_settings->setText(QApplication::translate("MainWindow", "Apply settings", nullptr));
        label->setText(QApplication::translate("MainWindow", "Baudrate", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Databit", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Parity", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Stopbit", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Flowcontrol", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Send Update", nullptr));
        Robot_sel->setText(QApplication::translate("MainWindow", "Robot / Drone", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "DTR", nullptr));
        asc_show->setText(QApplication::translate("MainWindow", "Show Hex", nullptr));
        PicthBox->setTitle(QApplication::translate("MainWindow", "Pitch Gain Box", nullptr));
        pitch_p_gain_label->setText(QApplication::translate("MainWindow", "P-Gain", nullptr));
        pitch_i_gain_label->setText(QApplication::translate("MainWindow", "I-Gain", nullptr));
        pitch_d_gain_label_2->setText(QApplication::translate("MainWindow", "D-Gain", nullptr));
        RollBox->setTitle(QApplication::translate("MainWindow", "Roll Gain Box", nullptr));
        roll_p_gain_label->setText(QApplication::translate("MainWindow", "P-Gain", nullptr));
        roll_i_gain_label->setText(QApplication::translate("MainWindow", "I-Gain", nullptr));
        roll_d_gain_label_3->setText(QApplication::translate("MainWindow", "D-Gain", nullptr));
        YawBox->setTitle(QApplication::translate("MainWindow", "Yaw Gain Box", nullptr));
        yaw_p_gain_label->setText(QApplication::translate("MainWindow", "P-Gain", nullptr));
        yaw_i_gain_label_2->setText(QApplication::translate("MainWindow", "I-Gain", nullptr));
        yaw_d_gain_label_4->setText(QApplication::translate("MainWindow", "D-Gain", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

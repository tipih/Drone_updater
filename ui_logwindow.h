/********************************************************************************
** Form generated from reading UI file 'logwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWINDOW_H
#define UI_LOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_LogWindow
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *log1;
    QCustomPlot *log2;
    QCustomPlot *log3;

    void setupUi(QWidget *LogWindow)
    {
        if (LogWindow->objectName().isEmpty())
            LogWindow->setObjectName(QStringLiteral("LogWindow"));
        LogWindow->resize(719, 464);
        verticalLayout = new QVBoxLayout(LogWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        log1 = new QCustomPlot(LogWindow);
        log1->setObjectName(QStringLiteral("log1"));

        verticalLayout->addWidget(log1);

        log2 = new QCustomPlot(LogWindow);
        log2->setObjectName(QStringLiteral("log2"));

        verticalLayout->addWidget(log2);

        log3 = new QCustomPlot(LogWindow);
        log3->setObjectName(QStringLiteral("log3"));

        verticalLayout->addWidget(log3);


        retranslateUi(LogWindow);

        QMetaObject::connectSlotsByName(LogWindow);
    } // setupUi

    void retranslateUi(QWidget *LogWindow)
    {
        LogWindow->setWindowTitle(QApplication::translate("LogWindow", "Logging Window", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LogWindow: public Ui_LogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWINDOW_H

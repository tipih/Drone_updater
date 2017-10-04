#include "logwindow.h"
#include "ui_logwindow.h"

LogWindow::LogWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogWindow)
{
    ui->setupUi(this);
    setupLogs();

}

LogWindow::~LogWindow()
{
    delete ui;
}


void LogWindow::updateLogs(float lg1,float lg2,float lg3){
#ifdef debug
    qDebug()<<lg1<<" "<<lg2<<" "<<lg3;
#endif
    static QTime time(QTime::currentTime());
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey = 0;

    if (key-lastPointKey > 0.002) // at most add point every 2 ms
    {
      // add data to lines:
      ui->log1->graph(0)->addData(key, lg1);
      ui->log2->graph(0)->addData(key, lg2);
      ui->log3->graph(0)->addData(key, lg3);

      // rescale value (vertical) axis to fit the current data:
      //ui->customPlot->graph(0)->rescaleValueAxis();
      //ui->customPlot->graph(1)->rescaleValueAxis(true);
      lastPointKey = key;
    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->log1->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->log2->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->log3->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->log1->replot();
    ui->log2->replot();
    ui->log3->replot();
}


void LogWindow::setupLogs(){

    /*Setup Grapf 1*/
    ui->log1->addGraph(); // blue line
    ui->log1->graph(0)->setPen(QPen(QColor(40, 110, 255)));
    ui->log1->addGraph(); // red line
    ui->log1->graph(1)->setPen(QPen(QColor(255, 110, 40)));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->log1->xAxis->setTicker(timeTicker);
    ui->log1->axisRect()->setupFullAxesBox();
    ui->log1->yAxis->setRange(-1.2, 1.2);

    /*Setup Grapf 2*/
    ui->log2->addGraph(); // blue line
    ui->log2->graph(0)->setPen(QPen(QColor(255, 20, 0)));
    ui->log2->addGraph(); // red line
    ui->log2->graph(1)->setPen(QPen(QColor(200, 110, 40)));


    timeTicker->setTimeFormat("%h:%m:%s");
    ui->log2->xAxis->setTicker(timeTicker);
    ui->log2->axisRect()->setupFullAxesBox();
    ui->log2->yAxis->setRange(-1.2, 1.2);

    /*Setup Grapf 3*/
    ui->log3->addGraph(); // blue line
    ui->log3->graph(0)->setPen(QPen(QColor(255, 110, 255)));
    ui->log3->addGraph(); // red line
    ui->log3->graph(1)->setPen(QPen(QColor(100, 110, 40)));


    timeTicker->setTimeFormat("%h:%m:%s");
    ui->log3->xAxis->setTicker(timeTicker);
    ui->log3->axisRect()->setupFullAxesBox();
    ui->log3->yAxis->setRange(-1.2, 1.2);


}

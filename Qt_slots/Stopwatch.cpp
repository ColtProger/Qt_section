#include"Stopwatch.h"
#include<QTimer>
#include<QDebug>

Stopwatch::Stopwatch(QObject *parent):QTimer{parent}
{
    ms = ms;
    s = s;
    min = min;
    hh = hh;

    timer = new QTimer();
    //timer->start(1);

   // connect(timer, &QTimer::timeout, this, &MainWindow::slotTimerAlarm);
}
Stopwatch::~Stopwatch()
{

}

void Stopwatch::start_timer(int pause)
{
    //timer->start(pause);
    //qDebug()<<"start_timer";
     ms++;
     if (ms>=1000){
        ms = 0;
         s++;
     }
     if (s>=60){
        s = 0;
        min++;
     }
     if (min>=60){
        min = 0;
        hh++;
     }

}

void Stopwatch::reset_timer(){
    ms = 0;
    s = 0;
    min = 0;
    hh = 0;
    ms1 = 0;
}

void Stopwatch::stop_timer(){

     timer->stop();
}

QString  Stopwatch::get_time(){
    QString line = QString::number(hh) + ":" + QString::number(min) + ":" +QString::number(s)+"."+QString::number(ms);
    return line;

}

QString  Stopwatch::get_round_time(){
    ms2 =min*60000 + s*1000 + ms;
    round = ms2 - ms1;
    int sec = round/1000;
    int min = sec/60;
    int hh = min/60;
    QString line =QString::number(hh) + ":" + QString::number(min%60) + ":" +QString::number(sec%60)+"."+QString::number(round%1000);
    ms1 = ms2;
    return line;

}
void Stopwatch::SendSignal(){

   emit sig_send_current_time();
}
//QTime::currentTime()

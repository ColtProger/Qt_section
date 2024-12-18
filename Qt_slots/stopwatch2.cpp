#include "stopwatch2.h"

Stopwatch2::Stopwatch2(QObject *parent):QTimer{parent}
{
    ms = ms;
    s = s;
    min = min;
    hh = hh;


    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Stopwatch2::timeoutLogic);
}

Stopwatch2::~Stopwatch2()
{

}

void Stopwatch2::start_timer(int pause) //(int pause)
{
    pause =pause;
    timer->start(pause);
}


void Stopwatch2::timeoutLogic() //(int pause)
{
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
     emit sig_start_pause(pause);
}

void Stopwatch2::reset_timer(){
    ms = 0;
    s = 0;
    min = 0;
    hh = 0;
    ms1 = 0;
}

void Stopwatch2::stop_timer(){
    timer->stop();
}

QString  Stopwatch2::get_time(){
    QString line = QString::number(hh) + ":" + QString::number(min) + ":" +QString::number(s)+"."+QString::number(ms);
    return line;

}

QString  Stopwatch2::get_round_time(){
    ms2 =min*60000 + s*1000 + ms;
    round = ms2 - ms1;
    int sec = round/1000;
    int min = sec/60;
    int hh = min/60;
    QString line =QString::number(hh) + ":" + QString::number(min%60) + ":" +QString::number(sec%60)+"."+QString::number(round%1000);
    ms1 = ms2;
    return line;

}

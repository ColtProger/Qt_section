#ifndef STOPWATCH2_H
#define STOPWATCH2_H
#include<QObject>
#include <QTimer>
#include<QString>

class Stopwatch2: public QTimer
{
    Q_OBJECT

public:
    Stopwatch2(QObject *parent = nullptr);

    ~Stopwatch2();


    void stop_timer();
    QString get_time();
    void reset_timer();
    QString get_round_time();
    void start_timer(int pause);

public slots:
    void timeoutLogic();


signals:

    void sig_start();
    void sig_start_pause(int pause);
    void sig_stop();

private:
    QTimer *timer;

    int ms = 0;
    int s = 0;
    int min = 0;
    int hh = 0;
    int ms1 = 0;
    int ms2 = 0;
    int round = 0;
    int pause = 1;
   // bool flag = true;
};

#endif // STOPWATCH2_H




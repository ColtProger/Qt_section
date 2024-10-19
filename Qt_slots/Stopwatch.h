#ifndef STOPWATCH_H
#define STOPWATCH_H
#include<QObject>
#include <QTimer>
#include<QString>

class Stopwatch : public QTimer
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();

    void start_timer(int pause);
    void SendSignal();
    void stop_timer();
    QString get_time();
    void reset_timer();
    QString get_round_time();

signals:

    void sig_send_current_time();

private:
    QTimer *timer;

    int ms = 0;
    int s = 0;
    int min = 0;
    int hh = 0;
    int ms1 = 0;
    int ms2 = 0;
    int round = 0;
   // bool flag = true;

};

#endif // STOPWATCH_H

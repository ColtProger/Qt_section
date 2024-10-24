#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include<QTime>
#include<QFont>
#include "Stopwatch2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void ReceiveSignalP(int pause);
    void ReceiveSignal();

private slots:


    void on_StartButton_clicked();

    void on_ResetButton_clicked();

    void on_RoundButton_clicked();

private:
    Ui::MainWindow *ui;

    Stopwatch2 *timer_s;
    int round_number = 0;
    bool flag = false;
    int pause = 1;
};
#endif // MAINWINDOW_H

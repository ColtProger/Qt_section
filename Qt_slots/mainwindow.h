#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include<QTime>
#include<QFont>
#include "Stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ReceiveSignal();

    void on_StartButton_clicked();

    void on_ResetButton_clicked();

    void on_RoundButton_clicked();

private:
    Ui::MainWindow *ui;
    Stopwatch *timer_s;
    int round_number = 0;
    bool flag = false;
};
#endif // MAINWINDOW_H

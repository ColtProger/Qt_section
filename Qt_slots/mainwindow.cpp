#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font("Times", 38, QFont::Bold);
    ui->TimeLabel->setFont(font);

    ui->StartButton->setText("START");
    ui->ResetButton->setText("RESET");

    ui->TimeLabel->setText(QString::number(0) + ":" + QString::number(0) + ":" +QString::number(0)+"."+QString::number(00) );

    timer_s = new Stopwatch2(this);

     connect(timer_s, &Stopwatch2::sig_start_pause, this, &MainWindow::displayTime);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayTime(int pause)
{
   //pause = 1;
   //timer_s->start_timer(pause);
   ui->TimeLabel->setText(timer_s->get_time());
}


void MainWindow::on_StartButton_clicked()
{
    if (flag){
       timer_s->stop_timer();
       ui->StartButton->setText("START");

    }
    else {
       ui->StartButton->setText("STOP");
       pause = 1;
       timer_s->start_timer(pause);
    }
    flag = !flag;
}


void MainWindow::on_ResetButton_clicked()
{
    timer_s->reset_timer();
    ui->TimeLabel->setText(timer_s->get_time());
}


void MainWindow::on_RoundButton_clicked()
{
    round_number++;

    ui->textBrowser->append(QString("Round: ") + QString::number(round_number) + QString(" time: ") +timer_s->get_round_time() );
}


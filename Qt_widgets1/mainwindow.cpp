#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QDebug>
#include<QPushButton>
#include<QRadioButton>
#include<QComboBox>
#include <QStringList>
#include <QProgressBar>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lst<<"Item 1"<<"Item 2"<<"Item 3"<<"Item 4"<<"Item 5";
    ui -> comboBox->addItems(lst);

    ui -> radioButton1->setText("Choice number 1");
    ui -> radioButton2->setText("Choice number 2");

    ui -> pushButton->setText("Add 10%");

    ui -> progressBar->setMinimum(0);
    ui -> progressBar->setMaximum(100);
    current_value_bar = 0;
    ui -> progressBar->setValue(current_value_bar);

    QObject::connect(ui -> pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_toggled);

    //ui->pushButtonTog->setDown(true);
    QObject::connect(ui -> pushButtonTog, &QPushButton::clicked, this, &MainWindow::on_pushButtonTog_toggled);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_toggled(bool checked)
{
     if (current_value_bar<100){
         current_value_bar += 10;
         ui -> progressBar->setValue(current_value_bar);
     } else {
         current_value_bar = 0;
         ui -> progressBar->setValue(current_value_bar);
     }
}


void MainWindow::on_pushButtonTog_toggled(bool checked)
{
    if(status ==true)
    {
        status = false;
        qDebug()<<"setDown(false)";
    }
   else
    {
        status = true;
        qDebug()<<"setDown(true)";
    }
    ui->pushButtonTog->setDown(status);
}

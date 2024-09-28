#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QPushButton>
#include<QDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    d = new Dialog(this);

    connect(ui -> DBconnection,&QPushButton::clicked, [this](){
         d->exec();
    });

   // layout()->addWidget(d);

}

MainWindow::~MainWindow()
{
    delete ui;
}


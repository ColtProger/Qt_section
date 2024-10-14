#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private Q_SLOTS:
    void on_pushButton_toggled(bool checked);
    void on_pushButtonTog_toggled(bool checked);

private:
     QStringList lst;
     int current_value_bar;
     bool status;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

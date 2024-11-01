#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "formplot.h"
#include "graphicchart.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QDataStream>
#include <QMessageBox>
#include <QtGlobal>
#include <QtConcurrent>
#include <algorithm>

//Подключаем все что нужно для графиков
#include <QLineSeries>
#include <QtCharts>
#include <QChartView>

#define FD 1000.0 //частота дискретизации
#define NUM_GRAPHS 2

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Метод считывает данные из исходного файла
    QVector<uint32_t> ReadFile(QString path, uint8_t numberChannel);
    //Метод преобразует данные физические величины, В?
    QVector<double> ProcessFile(QVector<uint32_t> dataFile);
    //Метод ищет Максимумы
    QVector<double> FindMax(QVector<double> resultData);
    //Метод ищет минимумы
    QVector<double> FindMin(QVector<double> resultData);
    //Метод отображает результаты
    void DisplayResult(QVector<double> mins, QVector<double> maxs);

signals:

    void sig_graph_ready();
    void sig_ready();

private slots:
    void on_pb_path_clicked();
    void on_pb_start_clicked();



    void plotGraph();

private:
 //   FormPlot *Graphform;
    Ui::MainWindow *ui;
    QString pathToFile = "";
    uint8_t numberSelectChannel = 0xEA;

    QVector<uint32_t> readData;
    QVector<double> procesData;
    QVector<double> mins, maxs;

    void ViewGraph(void);
    void DataGraph(QVector<double> resultData);

    GraphicChart* graphClass;
    QChart* chart;
    QChartView* chartView;
    QGridLayout *layout;

};
#endif // MAINWINDOW_H
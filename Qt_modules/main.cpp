#include <QCoreApplication>
#include <QSqlDatabase>
#include <QUdpSocket>
#include<QDtls>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    QUdpSocket clientSocket;
    QDtls clientDtls;

    return a.exec();
}

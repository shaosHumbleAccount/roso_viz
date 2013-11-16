#include <QtCore/QCoreApplication>
#include <iostream>
#include <QtNetwork>
#include "rosoviz.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for(int i = 1; i < 100; i ++)
    {
        qDebug(QString("%1").arg(i).toAscii());
        Rosoviz::setRobotPos(Rosoviz::RED, 1, 250 - i*5, 100);
        Rosoviz::setRobotPos(Rosoviz::BLUE, 1, -250 + i*5, 150);
        Rosoviz::setRobotPos(Rosoviz::BLUE, 0, 250 - i*5, -100);
        Rosoviz::setRobotPos(Rosoviz::RED, 0, -250 + i*5, -150);
        usleep(50000);
    }

    //return a.exec();
}

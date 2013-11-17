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
        Rosoviz::setRobotPos(Rosoviz::BLUE, 0, 0.250 - i*0.01, -0.100, 3.1416);
        Rosoviz::setRobotPos(Rosoviz::RED, 0, -0.250 + i*0.01, -0.150, -3.1416/2);
        Rosoviz::setRobotPos(Rosoviz::RED, 1, 0.250 - i*0.01, 0.100, 0);
        Rosoviz::setRobotPos(Rosoviz::BLUE, 1, -0.250 + i*0.01, 0.150, 3.1416/2);

        Rosoviz::setRobotTarget(Rosoviz::BLUE, 1, -0.250 + i*0.01, 0.30);

        Rosoviz::setBallPos(-0.5 + i*0.01 ,-0.5);

        usleep(50000);
    }

    //return a.exec();
}

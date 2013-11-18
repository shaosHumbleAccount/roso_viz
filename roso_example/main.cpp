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
        //setRobotPos(RobotType type, int robotID, double x, double y, double rad = 0)
        //To draw the current position of a robot.
        Rosoviz::setRobotPos(Rosoviz::BLUE, 0, 0.250 - i*0.01, -0.100, 3.1416);

        //setRobotTarget(RobotType type, int robotID, double x, double y, double rad = 0)
        //To draw the current target of a robot
        Rosoviz::setRobotTarget(Rosoviz::BLUE, 1, -0.250 + i*0.01, 0.30);

        //setBallPos(double x, double y)
        //To draw the position of the ball.
        Rosoviz::setBallPos(-0.5 + i*0.01 ,-0.5);

        Rosoviz::setRobotPos(Rosoviz::RED, 0, -0.250 + i*0.01, -0.150, -3.1416/2);


        Rosoviz::setRobotPos(Rosoviz::RED, 1, 0.250 - i*0.01, 0.100, 0);


        Rosoviz::setRobotPos(Rosoviz::BLUE, 1, -0.250 + i*0.01, 0.150, 3.1416/2);

        usleep(50000);
    }

    //return a.exec();
}

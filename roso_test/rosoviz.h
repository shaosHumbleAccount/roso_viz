/*
* ROSO_VIZ 0.1, by Tianlan Shao (shaotianlan.de@gmail.com)
*
* Include this header to communicate with Roso_viz.
*
* Example:
*       Rosoviz::setRobotPos(Rosoviz::RED, 2, 10.11, 20.5);
*
* The line above tells Roso_viz that a red robot, whose ID is 2, currently
* locates at x = 10.11, y = 20.5.
*
*
*
* NOTE:
* 1. Currently Roso_viz is just a visualization tool, which means you have
*    to tell it everything you want to see, e.g. position of the ball, positions
*    of your rival, etc.
*
* 2. Make sure ROSO_VIZ_IP and ROSO_VIZ_PORT are the same as the setting of Roso_viz
*
*/

#define ROSO_VIZ_IP  "127.0.0.1"
#define ROSO_VIZ_PORT  7086



#ifndef ROSOVIZ_H
#define ROSOVIZ_H

#include <QObject>
#include <QtNetwork>


class Rosoviz : public QObject
{
    Q_OBJECT
public:
    explicit Rosoviz(QObject *parent = 0){}

    enum RobotType {RED=0,BLUE=1};

public slots:
    //Set a robot's current position
    static void setRobotPos(RobotType type, int robotID, double x, double y, double rad)
    {
        sendMsg(QString("roboPos %1 %2 %3 %4 %5").arg(type).arg(robotID).arg(x).arg(y).arg(rad));
    }

    //Set a robot's current target
    static void setRobotTarget(RobotType type, int robotID, double x, double y)
    {
        sendMsg(QString("roboTar %1 %2 %3 %4").arg(type).arg(robotID).arg(x).arg(y));
    }

    //Set the ball's current position
    static void setBallPos(double x, double y)
    {
        sendMsg(QString("ballPos %1 %2").arg(x).arg(y));
    }

private:
    static void sendMsg(QString msg){
        QUdpSocket* socket = new QUdpSocket();
        socket->writeDatagram(msg.toAscii(), QHostAddress(ROSO_VIZ_IP), ROSO_VIZ_PORT);
    }
};

#endif // ROSOVIZ_H

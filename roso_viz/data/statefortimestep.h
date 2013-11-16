#ifndef DATAFORTIMESTEP_H
#define DATAFORTIMESTEP_H

#include <QtCore>
#include "robopos.h"

class StateForTimestep : public QObject
{
    Q_OBJECT
public:
    explicit StateForTimestep(QObject *parent = 0);
    
    QVector<RoboPos> red_RobotPoses;
    QVector<RoboPos> blue_RobotPoses;

    QVector<RoboPos> red_robotTargets;
    QVector<RoboPos> blue_robotTargets;

    QPointF ballPos;

    QTime time;
signals:
    
public slots:
    
};

#endif // DATAFORTIMESTEP_H

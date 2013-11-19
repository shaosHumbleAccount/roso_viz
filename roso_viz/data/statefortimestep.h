#ifndef DATAFORTIMESTEP_H
#define DATAFORTIMESTEP_H

#include <QtCore>
#include "robopos.h"
#include <QDateTime>

class StateForTimestep
{
public:
    explicit StateForTimestep();
    StateForTimestep(const StateForTimestep&);

    QVector<RoboPos> red_RobotPoses;
    QVector<RoboPos> blue_RobotPoses;

    QVector<RoboPos> red_robotTargets;
    QVector<RoboPos> blue_robotTargets;

    QPointF ballPos;

    QDateTime timestamp;
signals:
    
public slots:
    
};

#endif // DATAFORTIMESTEP_H

#include "statefortimestep.h".h"

StateForTimestep::StateForTimestep()
{
    ballPos.setX(-1000);
    ballPos.setY(-1000);
    timestamp = QDateTime::currentDateTime();
}

StateForTimestep::StateForTimestep(const StateForTimestep& old)
{
    foreach(RoboPos pos, old.red_RobotPoses)
    {
        red_RobotPoses.append(pos);
    }
    foreach(RoboPos pos, old.blue_RobotPoses)
    {
        blue_RobotPoses.append(pos);
    }
    foreach(RoboPos pos, old.red_robotTargets)
    {
        red_robotTargets.append(pos);
    }
    foreach(RoboPos pos, old.blue_robotTargets)
    {
        blue_robotTargets.append(pos);
    }

    ballPos = old.ballPos;

    timestamp = old.timestamp;
}

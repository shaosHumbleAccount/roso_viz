#include "fieldmodelcontroller.h"
#include "util/logger.h"

FieldModelController::FieldModelController(QObject *parent) :
    QObject(parent)
{
    for(int i = 0;i < 3;i ++)
    {
        currentState.red_RobotPoses.push_back(RoboPos(RED_ROBOT,i));
        currentState.red_robotTargets.push_back(RoboPos(RED_ROBOT,i));

        currentState.blue_RobotPoses.push_back(RoboPos(BLUE_ROBOT,i));
        currentState.blue_robotTargets.push_back(RoboPos(BLUE_ROBOT,i));
    }
}

void FieldModelController::updateState(QString msg)
{
    Logger::singleton()->printLog("updateState: " + msg);
    try
    {
        if(msg.startsWith("roboPos"))
        {
            updateRoboPos(msg);
        }
    }
    catch(...)
    {

    }
    emit updateScene(currentState);
}

void FieldModelController::updateRoboPos(const QString& msg)
{
    QStringList list = msg.split(" ", QString::SkipEmptyParts);
    if(list.size() != 5)
    {
        return;
    }
    bool success = true;
    bool tmpSucess;
    int type = list.at(1).toInt(&tmpSucess);
    if(type != RED_ROBOT && type != BLUE_ROBOT)
    {
        success = false;
    }
    success &= tmpSucess;
    int id = list.at(2).toInt(&tmpSucess);
    success &= tmpSucess;
    if(id < 0 || id >= 3)
    {
        success = false;
    }
    double x = list.at(3).toDouble(&tmpSucess);
    success &= tmpSucess;
    double y = list.at(4).toDouble(&tmpSucess);
    success &= tmpSucess;
    if(!success)
    {
        return;
    }
    if(type == RED_ROBOT)
    {
        currentState.red_RobotPoses[id].isKnown = true;
        currentState.red_RobotPoses[id].x = x;
        currentState.red_RobotPoses[id].y = y;
        Logger::singleton()->printLog(QString("update Red Robot %1 Pos: x = %2, y = %3")
                                      .arg(id).arg(currentState.red_RobotPoses[id].x)
                                      .arg(currentState.red_RobotPoses[id].y));
    }
    else if(type == BLUE_ROBOT)
    {
        currentState.blue_RobotPoses[id].isKnown = true;

        currentState.blue_RobotPoses[id].x = x;
        currentState.blue_RobotPoses[id].y = y;
        Logger::singleton()->printLog(QString("update Blue Robot %1 Pos: x = %2, y = %3")
                                      .arg(id).arg(currentState.blue_RobotPoses[id].x)
                                      .arg(currentState.blue_RobotPoses[id].y));
    }
}

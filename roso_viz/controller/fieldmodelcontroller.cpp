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
        currentState.timestamp = QDateTime::currentDateTime();

        qint64 tmp  = currentState.timestamp.toMSecsSinceEpoch();
        if(msg.startsWith("roboPos"))
        {
            updateRoboPos(msg);
        }
        if(msg.startsWith("ballPos"))
        {
            updateBallPos(msg);
        }
        if(msg.startsWith("roboTar"))
        {
            updateRoboTar(msg);
        }
    }
    catch(...)
    {

    }
    emit updateScene(currentState);
}

void FieldModelController::updateBallPos(const QString& msg)
{
    QStringList list = msg.split(" ", QString::SkipEmptyParts);
    if(list.size() != 3)
    {
        return;
    }
    bool success = true;
    bool tmpSucess;
    double x = list.at(1).toDouble(&tmpSucess);
    success &= tmpSucess;
    double y = list.at(2).toDouble(&tmpSucess);
    success &= tmpSucess;
    if(!success)
    {
        return;
    }
    currentState.ballPos.setX(x);
    currentState.ballPos.setY(y);
    Logger::singleton()->printLog(QString("update BallPos: x = %1, y = %2")
                                  .arg(currentState.ballPos.x())
                                  .arg(currentState.ballPos.y()));
}


void FieldModelController::updateRoboPos(const QString& msg)
{
    QStringList list = msg.split(" ", QString::SkipEmptyParts);
    if(list.size() != 6)
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
    double rad = list.at(5).toDouble(&tmpSucess);
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
        currentState.red_RobotPoses[id].rad = rad;
        Logger::singleton()->printLog(QString("update Red Robot %1 Pos: x = %2, y = %3")
                                      .arg(id).arg(currentState.red_RobotPoses[id].x)
                                      .arg(currentState.red_RobotPoses[id].y));
    }
    else if(type == BLUE_ROBOT)
    {
        currentState.blue_RobotPoses[id].isKnown = true;
        currentState.blue_RobotPoses[id].x = x;
        currentState.blue_RobotPoses[id].y = y;
        currentState.blue_RobotPoses[id].rad = rad;
        Logger::singleton()->printLog(QString("update Blue Robot %1 Pos: x = %2, y = %3")
                                      .arg(id).arg(currentState.blue_RobotPoses[id].x)
                                      .arg(currentState.blue_RobotPoses[id].y));
    }
}


void FieldModelController::updateRoboTar(const QString& msg)
{
    Logger::singleton()->printLog(QString("updateRoboTar") + msg);

    QStringList list = msg.split(" ", QString::SkipEmptyParts);
    if(list.size() != 6)
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
    double rad = list.at(5).toDouble(&tmpSucess);
    success &= tmpSucess;

    if(!success)
    {
        return;
    }
    if(type == RED_ROBOT)
    {
        currentState.red_robotTargets[id].isKnown = true;
        currentState.red_robotTargets[id].x = x;
        currentState.red_robotTargets[id].y = y;
        currentState.red_robotTargets[id].rad = rad;
    }
    else if(type == BLUE_ROBOT)
    {
        currentState.blue_robotTargets[id].isKnown = true;
        currentState.blue_robotTargets[id].x = x;
        currentState.blue_robotTargets[id].y = y;
        currentState.blue_robotTargets[id].rad = rad;
    }
}

void FieldModelController::clearScene()
{
    for(int i = 0;i < 3;i ++)
    {
        currentState.red_RobotPoses[i].isKnown = false;
        currentState.blue_RobotPoses[i].isKnown = false;
        currentState.red_robotTargets[i].isKnown = false;
        currentState.blue_robotTargets[i].isKnown = false;
        currentState.ballPos.setX(-1000);
        currentState.ballPos.setY(-1000);
    }
    emit updateScene(currentState);
}

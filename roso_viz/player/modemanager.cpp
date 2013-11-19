#include "modemanager.h"
#include "util/logger.h"

ModeManager::ModeManager(QObject *parent) :
    QObject(parent)
{
    currentMode = LIVE;
}

void ModeManager::on_updateScene_live(StateForTimestep& data)
{
    if(currentMode == LIVE)
    {
        emit updateScene(data);
    }
}

void ModeManager::on_updateScene_replay(StateForTimestep& data)
{
    Logger::singleton()->printLog("on_updateScene_replay");
    if(currentMode == REPLAY)
    {
        emit updateScene(data);
    }
}

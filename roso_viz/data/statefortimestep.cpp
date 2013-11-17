#include "statefortimestep.h".h"

StateForTimestep::StateForTimestep(QObject *parent) :
    QObject(parent)
{
    ballPos.setX(-1000);
    ballPos.setY(-1000);
}

#include "staterecord.h"

StateRecord::StateRecord( QDateTime start)
{
    startTime = start;
    endTime = start;
    name = start.toString("MMM.dd_hh:mm:ss");
}

void StateRecord::getTimeStamps(QVector<qint64>& stamps)
{
    stamps.clear();
    foreach(StateForTimestep data, states)
    {
        stamps.append(data.timestamp.toMSecsSinceEpoch());
    }
}

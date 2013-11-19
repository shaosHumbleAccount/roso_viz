#include "recordplayer.h"
#include "commonDefs.h"
#include "util/logger.h"

RecordPlayer::RecordPlayer(QObject *parent) :
    QThread(parent),
    speed(1),
    currentTime(0),
    record(NULL),
    isPlaying(false)
{
}

RecordPlayer::~RecordPlayer()
{
}

bool RecordPlayer::setRecord(StateRecord* _record)
{
    QMutexLocker(&(this->mutex));
    this->stopPlaying();
    record = _record;
    currentTime = 0;
    if(NULL == record)
    {
        timestamps.clear();
        return false;
    }
    else
    {
        _record->getTimeStamps(timestamps);
    }
    return true;
}


qint64 RecordPlayer::getRecordTimeLength()
{
    QMutexLocker(&this->mutex);
    if(NULL == record || timestamps.size() <= 0)
    {
        return 0;
    }
    else
    {
        return (timestamps[timestamps.size() - 1] - timestamps[0]);
    }
}


bool RecordPlayer::startPlaying(qint64 startTime)
{
    QMutexLocker(&(this->mutex));

    stopPlaying();

    if(NULL == record)
    {
        return false;
    }
    startSystemTime = QTime::currentTime();
    startSystemTime.start();

    isPlaying = true;
    startTrajTime = getClosestTimestamp(startTime);

    currentTime = startTrajTime;

    emit recordPlayingStarted();

    this->start();
    return true;
}

bool RecordPlayer::gotoTime(qint64 time)
{
    QMutexLocker(&(this->mutex));
    stopPlaying();

    int closestIdx = getClosestTimestampIndex(time);
    if(NULL != record  && record->states.size() >= (closestIdx + 1) )
    {
        emit updateScene(record->states[closestIdx]);
    }
    return false;
}


int RecordPlayer::getClosestTimestampIndex(qint64 time)
{
    QMutexLocker(&(this->mutex));
    if(NULL == record || time <= 0)
    {
        return 0;
    }
    qint64 max_time;
    if(timestamps.size() <= 0)
    {
        max_time = 0;
    }
    else
    {
        max_time = timestamps[timestamps.size() - 1];
    }
    if(time >= max_time)
    {
        return timestamps.size() - 1;
    }
    int low_idx = 0;
    int up_idx = timestamps.size() - 1;
    int currentIdx = (low_idx + up_idx)/2;
    double currentValue = timestamps[currentIdx];

    while((up_idx - low_idx) > 1)
    {
        if(currentValue == time)
        {
            return currentIdx;
        }
        else if(currentValue > time)
        {
            up_idx = currentIdx;
        }
        else if(currentValue < time)
        {
            low_idx = currentIdx;
        }
        currentIdx = floor((low_idx + up_idx)/2);
        currentValue = timestamps[currentIdx];
    }
    if(fabs(timestamps[up_idx]) <= fabs(timestamps[low_idx]))
    {
        return up_idx;
    }
    else
    {
        return low_idx;
    }
}

qint64 RecordPlayer::getClosestTimestamp(qint64 time, int* idx)
{
    QMutexLocker(&(this->mutex));

    if(NULL == record || time < 0 || timestamps.size() <= 0)
    {
        if(idx)
        {
            *idx = -1;
        }
        return 0;
    }
    else
    {
        int closestIdx = getClosestTimestampIndex(time);
        if(idx)
        {
            *idx = closestIdx;
        }
        return timestamps[closestIdx];
    }
}


void RecordPlayer::run()
{
    QMutexLocker(&(this->mutex));

    while(isPlaying)
    {
        int closestIdx;
        currentTime = getClosestTimestamp(speed*startSystemTime.elapsed() + startTrajTime, &closestIdx);

        if(closestIdx >= 0)
        {
            StateForTimestep pos = record->states[closestIdx];

           // Logger::singleton()->printLog(QString("closestIdx = %1").arg(closestIdx));
            emit updateScene(pos);
        }
        qint64 max_time;
        if(timestamps.size() <= 0)
        {
            max_time = 0;
        }
        else
        {
            max_time = timestamps[timestamps.size() - 1];
        }
        if(currentTime >= max_time)
        {
            break;
        }
        this->msleep(20);
    }

    stopPlaying();
}

void RecordPlayer::stopPlaying()
{
    QMutexLocker(&(this->mutex));
    emit recordPlayingFinished();
    isPlaying = false;
}

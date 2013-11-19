#ifndef RECORDPLAYER_H
#define RECORDPLAYER_H

#include <QtCore>
#include <QThread>
#include "data/staterecord.h"

class RecordPlayer : public QThread
{
    Q_OBJECT
public:
    explicit RecordPlayer(QObject *parent = 0);
    ~RecordPlayer();

    bool startPlaying(qint64 startTime = 0);
    bool gotoTime(qint64 time);
    void stopPlaying();

    bool setRecord(StateRecord* traj);

    qint64 getRecordTimeLength();

    qint64 getClosestTimestamp(qint64 time, int* idx = NULL);
    int getClosestTimestampIndex(qint64 time);


    double getSpeed() const{return speed;}
    void setSpeed(double value){speed = value;}

    double getCurrentTime() const{return currentTime;}
    void setCurrentTime(double value){currentTime = value;}

    bool getIsPlaying() const{return isPlaying;}

signals:
    void updateScene(StateForTimestep&);

    void recordPlayingFinished();
    void recordPlayingStarted();

public slots:


private:
    QMutex mutex;
    void run();

    qint64 speed;
    qint64 currentTime;

    StateRecord* record;
    QVector<qint64> timestamps;

    QTime startSystemTime;
    qint64 startTrajTime;

    bool isPlaying;
};

#endif // RECORDPLAYER_H

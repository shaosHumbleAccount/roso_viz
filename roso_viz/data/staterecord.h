#ifndef STATERECORD_H
#define STATERECORD_H

#include <QObject>
#include <QDateTime>
#include "statefortimestep.h"

class StateRecord
{
public:
    explicit StateRecord(QDateTime start = QDateTime::currentDateTime());

    void getTimeStamps(QVector<qint64>&);

    QDateTime startTime;
    QDateTime endTime;

    QVector<StateForTimestep> states;
    QString name;
signals:
    
public slots:

};

#endif // STATERECORD_H

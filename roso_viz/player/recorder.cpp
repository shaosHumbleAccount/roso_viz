#include "recorder.h"

Recorder::Recorder(QObject *parent) :
    QObject(parent)
{
    isRecording = false;
}

QStringList Recorder::getRecordNames()
{
    QStringList list;
    foreach(QString key, records.keys())
    {
        list.append(records[key]->name);
    }

    return list;
}

StateRecord* Recorder::getRecordByName(QString name)
{
    return records[name];
}

void Recorder::on_updateScene(StateForTimestep& data)
{
    if(isRecording)
    {
        currentRecord->states.append(data);
    }
}

void Recorder::on_startRecording()
{
    if(!isRecording)
    {
        currentRecord = new StateRecord();
        isRecording = true;
    }
}

void Recorder::on_stopRecording()
{
    if(isRecording)
    {
        currentRecord->endTime = QDateTime::currentDateTime();
        records[currentRecord->name] = currentRecord;
        isRecording = false;
        emit recordsUpdated();
    }
}

void Recorder::removeRecord(QString name)
{
    records.remove(name);
    emit recordsUpdated();
}

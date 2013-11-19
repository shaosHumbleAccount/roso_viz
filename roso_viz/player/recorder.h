#ifndef RECORDER_H
#define RECORDER_H

#include <QObject>
#include "data/staterecord.h"

class Recorder : public QObject
{
    Q_OBJECT
public:
    explicit Recorder(QObject *parent = 0);

    QStringList getRecordNames();

    StateRecord* getRecordByName(QString name);
    bool getIsRecording(){return isRecording;}

signals:
    void recordsUpdated();

public slots:
    void on_updateScene(StateForTimestep&);
    void on_startRecording();
    void on_stopRecording();
    void removeRecord(QString);
private:
    QMap<QString, StateRecord*> records;
    StateRecord* currentRecord;
    bool isRecording;
};

#endif // RECORDER_H

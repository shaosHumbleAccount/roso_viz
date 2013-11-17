#ifndef FIELDMODELCONTROLLER_H
#define FIELDMODELCONTROLLER_H

#include <QObject>
#include "data/statefortimestep.h"
#include "commonDefs.h"

class FieldModelController : public QObject
{
    Q_OBJECT
public:
    explicit FieldModelController(QObject *parent = 0);
    
signals:
    void updateScene(StateForTimestep&);

public slots:
    void updateState(QString msg);

private:
    void updateRoboPos(const QString& msg);
    void updateBallPos(const QString& msg);
    void updateRoboTar(const QString& msg);

    StateForTimestep currentState;
};

#endif // FIELDMODELCONTROLLER_H

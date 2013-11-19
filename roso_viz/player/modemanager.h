#ifndef MODEMANAGER_H
#define MODEMANAGER_H

#include <QObject>
#include "data/statefortimestep.h"

class ModeManager : public QObject
{
    Q_OBJECT
public:
    explicit ModeManager(QObject *parent = 0);

    enum CurrentMode{
        LIVE = 0,
        REPLAY = 1
    };

    void setMode(CurrentMode mode){currentMode = mode;}
signals:
    void updateScene(StateForTimestep&);

public slots:
    void on_updateScene_live(StateForTimestep&);
    void on_updateScene_replay(StateForTimestep&);

private:
    CurrentMode currentMode;
};

#endif // MODEMANAGER_H

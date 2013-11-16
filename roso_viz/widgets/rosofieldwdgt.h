#ifndef ROSOFIELDWDGT_H
#define ROSOFIELDWDGT_H

#include <QWidget>
#include <QGraphicsScene>
#include "data/statefortimestep.h"
#include "drawing/robotgraphicitem.h"

namespace Ui {
class RosoFieldWdgt;
}

class RosoFieldWdgt : public QWidget
{
    Q_OBJECT
    
public:
    explicit RosoFieldWdgt(QWidget *parent = 0);
    ~RosoFieldWdgt();
    
public slots:
    void on_updateScene(StateForTimestep&);

private:
    Ui::RosoFieldWdgt *ui;
    QGraphicsScene scene;

    RobotGraphicItem* blue_robots[3];
    RobotGraphicItem* red_robots[3];
};

#endif // ROSOFIELDWDGT_H

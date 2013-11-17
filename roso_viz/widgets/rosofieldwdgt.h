#ifndef ROSOFIELDWDGT_H
#define ROSOFIELDWDGT_H

#include <QWidget>
#include <QGraphicsScene>
#include "data/statefortimestep.h"
#include "drawing/robotgraphicitem.h"
#include "drawing/ballgraphicitem.h"
#include "drawing/fieldgraphicitem.h"
#include "drawing/robottargetgraphicitem.h"

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

    RobotGraphicItem* red_robots[3];
    RobotGraphicItem* blue_robots[3];

    robotTargetGraphicItem* red_targets[3];
    robotTargetGraphicItem* blue_targets[3];

    BallGraphicItem* ball;
    FieldGraphicItem* fieldItem;

    QPointF mapPosFromRosoToScene(const QPointF& pos) const;
    QPointF mapPosFromRosoToScene(double x, double y) const;

    double mapRotFromRosoToScene(double rads) const;//!return degree!!

};

#endif // ROSOFIELDWDGT_H

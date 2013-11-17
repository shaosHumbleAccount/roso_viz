#ifndef ROBOTTARGETGRAPHICITEM_H
#define ROBOTTARGETGRAPHICITEM_H

#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include "commonDefs.h"

class robotTargetGraphicItem : public QGraphicsItem
{
public:
    robotTargetGraphicItem(RobotType _type = RED_ROBOT, int _id = 0);
    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    RobotType type;
    int id;
};

#endif // ROBOTTARGETGRAPHICITEM_H

#ifndef ROBOTGRAPHICITEM_H
#define ROBOTGRAPHICITEM_H

#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include "commonDefs.h"

class RobotGraphicItem : public QGraphicsItem
{
public:
    RobotGraphicItem(RobotType _type = RED_ROBOT, int _id = 0);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QGraphicsEllipseItem* circle;
    RobotType type;
    int id;
};

#endif // ROBOTGRAPHICITEM_H

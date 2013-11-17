#include "fieldgraphicitem.h"
#include <QPainter>
#include "commonDefs.h"

FieldGraphicItem::FieldGraphicItem()
{
}

QRectF FieldGraphicItem::boundingRect() const
{
    return QRectF(-3, -3, 3, 3);
}

void FieldGraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    QBrush mybrush;

    pen.setColor(Qt::black);
    pen.setWidth(5);
    mybrush.setColor(Qt::darkGray);
    mybrush.setStyle(Qt::SolidPattern);

    painter->setPen(pen);
    painter->setBrush(mybrush);
    painter->drawRect(-843.0/SCENE_SCALE, -1387.0/SCENE_SCALE, 1705.0/SCENE_SCALE, 2786.0/SCENE_SCALE);

    pen.setColor(Qt::black);
    pen.setWidth(3);
    mybrush.setColor(Qt::darkGray);
    mybrush.setStyle(Qt::NoBrush);

    painter->setPen(pen);
    painter->setBrush(mybrush);
    painter->drawRect(-173.0/SCENE_SCALE, -1387.0/SCENE_SCALE, 533.0/SCENE_SCALE, 144.0/SCENE_SCALE);

    pen.setColor(Qt::black);
    pen.setWidth(3);
    mybrush.setColor(Qt::darkGray);
    mybrush.setStyle(Qt::NoBrush);

    painter->setPen(pen);
    painter->setBrush(mybrush);
    painter->drawRect(-173.0/SCENE_SCALE, (1399.0-144.0)/SCENE_SCALE, 533.0/SCENE_SCALE, 144.0/SCENE_SCALE);
}

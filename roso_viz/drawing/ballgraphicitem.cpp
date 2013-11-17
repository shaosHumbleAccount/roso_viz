#include "ballgraphicitem.h"
#include <QPainter>
#include "commonDefs.h"

BallGraphicItem::BallGraphicItem()
{
    setX(-1000);
    setY(-1000);
}

QRectF BallGraphicItem::boundingRect() const
{
    return QRectF(-15.0/SCENE_SCALE, -15.0/SCENE_SCALE, 15.0/SCENE_SCALE, 15.0/SCENE_SCALE);
}

void BallGraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    QBrush mybrush;
    pen.setColor(Qt::black);
    mybrush.setColor(Qt::white);
    mybrush.setStyle(Qt::SolidPattern);

    painter->setPen(pen);
    painter->setBrush(mybrush);
    painter->drawEllipse(QPoint(0,0),15.0/SCENE_SCALE,15.0/SCENE_SCALE);

}

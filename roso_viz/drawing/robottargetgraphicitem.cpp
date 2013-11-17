#include "robottargetgraphicitem.h"
#include <QPainter>

robotTargetGraphicItem::robotTargetGraphicItem(RobotType _type, int _id)
{
    type = _type;
    id = _id;

    setVisible(false);
    setX(-1000);
    setY(-1000);
}

QRectF robotTargetGraphicItem::boundingRect() const
{
    return QRectF(-43.0/SCENE_SCALE, -43.0/SCENE_SCALE, 43.0/SCENE_SCALE, 43.0/SCENE_SCALE);
}

void robotTargetGraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    QBrush mybrush;
    if(type == RED_ROBOT)
    {
        pen.setColor(Qt::red);
        mybrush.setColor(Qt::red);
        mybrush.setStyle(Qt::Dense7Pattern);

        painter->setPen(pen);
        painter->setBrush(mybrush);
        painter->drawEllipse(QPoint(0,0),43.0/SCENE_SCALE,43.0/SCENE_SCALE);

        pen.setColor(Qt::white);
        painter->setPen(pen);
        painter->drawText(-30.0/SCENE_SCALE,-30.0/SCENE_SCALE,60.0/SCENE_SCALE,60.0/SCENE_SCALE,Qt::AlignCenter|Qt::AlignHCenter,QString::number(id));
    }
    else
    {
        pen.setColor(Qt::blue);
        mybrush.setColor(Qt::blue);
        mybrush.setStyle(Qt::Dense7Pattern);

        painter->setPen(pen);
        painter->setBrush(mybrush);
        painter->drawEllipse(QPoint(0,0),43.0/SCENE_SCALE,43.0/SCENE_SCALE);

        pen.setColor(Qt::white);
        painter->setPen(pen);
        painter->drawText(-30.0/SCENE_SCALE,-30.0/SCENE_SCALE,60.0/SCENE_SCALE,60.0/SCENE_SCALE,Qt::AlignCenter|Qt::AlignHCenter,QString::number(id));
    }
}

#include "robotgraphicitem.h"
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QTextItem>

RobotGraphicItem::RobotGraphicItem(RobotType _type, int _id)
{
    type = _type;
    id = _id;

    setVisible(false);
    setX(-1000);
    setY(-1000);
}

QRectF RobotGraphicItem::boundingRect() const
{
    return QRectF(-30, -30, 30, 30);
}

void RobotGraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    QBrush mybrush;
    if(type == RED_ROBOT)
    {
        pen.setColor(Qt::black);
        mybrush.setColor(Qt::red);
        mybrush.setStyle(Qt::SolidPattern);

        painter->setPen(pen);
        painter->setBrush(mybrush);
        painter->drawEllipse(QPoint(0,0),15,15);

        pen.setColor(Qt::white);
        painter->setPen(pen);
        painter->drawText(-10,-10,20,20,Qt::AlignCenter|Qt::AlignHCenter,QString::number(id));
    }
    else
    {
        pen.setColor(Qt::black);
        mybrush.setColor(Qt::blue);
        mybrush.setStyle(Qt::SolidPattern);

        painter->setPen(pen);
        painter->setBrush(mybrush);
        painter->drawEllipse(QPoint(0,0),15,15);

        pen.setColor(Qt::white);
        painter->setPen(pen);
        painter->drawText(-10,-10,20,20,Qt::AlignCenter|Qt::AlignHCenter,QString::number(id));
    }
}

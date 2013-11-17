#include "robotgraphicitem.h"
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QTextItem>
#include "Setting/settingcenter.h"

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
    double r = SettingCenter::singleton()->getSettingValue("field/robot_radius").toDouble();
    return QRectF(-r/SCENE_SCALE, -r/SCENE_SCALE, r/SCENE_SCALE, r/SCENE_SCALE);
}

void RobotGraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    QBrush mybrush;
    double r = SettingCenter::singleton()->getSettingValue("field/robot_radius").toDouble();
    if(type == RED_ROBOT)
    {
        pen.setColor(Qt::black);
        mybrush.setColor(Qt::red);
        mybrush.setStyle(Qt::SolidPattern);

        painter->setPen(pen);
        painter->setBrush(mybrush);
        painter->drawEllipse(QPoint(0,0),r/SCENE_SCALE,r/SCENE_SCALE);

        mybrush.setColor(Qt::yellow);
        painter->setPen(pen);
        painter->setBrush(mybrush);
        painter->drawEllipse(QPoint(0,-r/3*2/SCENE_SCALE),r/3/SCENE_SCALE,r/3/SCENE_SCALE);

        pen.setColor(Qt::white);
        painter->setPen(pen);
        painter->drawText(-r/SCENE_SCALE,-r/SCENE_SCALE,r*2/SCENE_SCALE,r*2/SCENE_SCALE,Qt::AlignCenter|Qt::AlignHCenter,QString::number(id));
    }
    else
    {
        pen.setColor(Qt::black);
        mybrush.setColor(Qt::blue);
        mybrush.setStyle(Qt::SolidPattern);

        painter->setPen(pen);
        painter->setBrush(mybrush);
        painter->drawEllipse(QPoint(0,0),r/SCENE_SCALE,r/SCENE_SCALE);


        mybrush.setColor(Qt::yellow);
        painter->setPen(pen);
        painter->setBrush(mybrush);
        painter->drawEllipse(QPoint(0,-r/3*2/SCENE_SCALE),r/3/SCENE_SCALE,r/3/SCENE_SCALE);

        pen.setColor(Qt::white);
        painter->setPen(pen);
        painter->drawText(-r/SCENE_SCALE,-r/SCENE_SCALE,r*2/SCENE_SCALE,r*2/SCENE_SCALE,Qt::AlignCenter|Qt::AlignHCenter,QString::number(id));
    }
}

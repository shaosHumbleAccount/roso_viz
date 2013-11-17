#include "ballgraphicitem.h"
#include <QPainter>
#include "commonDefs.h"
#include "Setting/settingcenter.h"

BallGraphicItem::BallGraphicItem()
{
    setX(-1000);
    setY(-1000);
}

QRectF BallGraphicItem::boundingRect() const
{
    double r = SettingCenter::singleton()->getSettingValue("field/ball_radius").toDouble();
    return QRectF(-r/SCENE_SCALE, -r/SCENE_SCALE, r/SCENE_SCALE, r/SCENE_SCALE);
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
    double r = SettingCenter::singleton()->getSettingValue("field/ball_radius").toDouble();
    painter->drawEllipse(QPoint(0,0),r/SCENE_SCALE,r/SCENE_SCALE);

}

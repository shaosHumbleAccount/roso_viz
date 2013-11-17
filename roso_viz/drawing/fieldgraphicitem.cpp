#include "fieldgraphicitem.h"
#include <QPainter>
#include "commonDefs.h"
#include "Setting/settingcenter.h"

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

    SettingCenter* sc = SettingCenter::singleton();

    pen.setColor(Qt::black);
    pen.setWidth(5);
    mybrush.setColor(Qt::darkGray);
    mybrush.setStyle(Qt::SolidPattern);

    painter->setPen(pen);
    painter->setBrush(mybrush);
    painter->drawRect(sc->getSettingValue("field/left_top_x").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/left_top_y").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/width").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/height").toDouble()/SCENE_SCALE);

    pen.setColor(Qt::black);
    pen.setWidth(3);
    mybrush.setColor(Qt::darkGray);
    mybrush.setStyle(Qt::NoBrush);

    painter->setPen(pen);
    painter->setBrush(mybrush);
    painter->drawRect(sc->getSettingValue("field/abovepen_left_top_x").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/abovepen_left_top_y").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/abovepen_width").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/abovepen_height").toDouble()/SCENE_SCALE);

    pen.setColor(Qt::black);
    pen.setWidth(3);
    mybrush.setColor(Qt::darkGray);
    mybrush.setStyle(Qt::NoBrush);

    painter->setPen(pen);
    painter->setBrush(mybrush);
    painter->drawRect(sc->getSettingValue("field/lowpen_left_top_x").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/lowpen_left_top_y").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/lowpen_width").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/lowpen_height").toDouble()/SCENE_SCALE);

    pen.setColor(Qt::black);
    pen.setWidth(3);
    mybrush.setColor(Qt::darkGray);
    mybrush.setStyle(Qt::NoBrush);

    painter->setPen(pen);
    painter->setBrush(mybrush);
    painter->drawRect(sc->getSettingValue("field/abovegoal_left_top_x").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/abovegoal_left_top_y").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/abovegoal_width").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/abovegoal_height").toDouble()/SCENE_SCALE);

    pen.setColor(Qt::black);
    pen.setWidth(3);
    mybrush.setColor(Qt::darkGray);
    mybrush.setStyle(Qt::NoBrush);

    painter->setPen(pen);
    painter->setBrush(mybrush);
    painter->drawRect(sc->getSettingValue("field/lowgoal_left_top_x").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/lowgoal_left_top_y").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/lowgoal_width").toDouble()/SCENE_SCALE,
                      sc->getSettingValue("field/lowgoal_height").toDouble()/SCENE_SCALE);

    pen.setWidth(1);
    painter->drawLine(0,0,-50,0);
    painter->drawLine(0,0,0,50);
}

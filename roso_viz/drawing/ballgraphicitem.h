#ifndef BALLGRAPHICITEM_H
#define BALLGRAPHICITEM_H

#include <QGraphicsItem>

class BallGraphicItem : public QGraphicsItem
{
public:
    BallGraphicItem();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BALLGRAPHICITEM_H

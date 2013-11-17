#ifndef FIELDGRAPHICITEM_H
#define FIELDGRAPHICITEM_H

#include <QGraphicsItem>

class FieldGraphicItem : public QGraphicsItem
{
public:
    FieldGraphicItem();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // FIELDGRAPHICITEM_H

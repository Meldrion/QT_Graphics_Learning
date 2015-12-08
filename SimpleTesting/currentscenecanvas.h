#ifndef MYCUSTOMITEM_H
#define MYCUSTOMITEM_H

#include <QVector>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QDebug>
#include "tileset.h"
#include "tileitem.h"

class CurrentSceneCanvas : public QGraphicsItem
{
private:
    QGraphicsRectItem* cursor;
    int m_unit_width;
    int m_unit_height;
    int m_unit_size;
    QVector<Tileset*> m_linked_tilesets;
    QVector<QVector<TileItem* > > m_elements;
    void init();
public:
    CurrentSceneCanvas(int unit_width,int unit_height,int unit_size,QGraphicsItem *parent = 0);
    QRectF boundingRect() const;
    void setUnitSize(int unitSize);
    void setUnitDimension(int unit_width,int unit_height);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
signals:

public slots:
};

#endif // MYCUSTOMITEM_H

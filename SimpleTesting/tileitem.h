#ifndef TILEITEM_H
#define TILEITEM_H

#include <QPixmap>
#include <QGraphicsItem>
#include <QPainter>
#include <QVector>
#include "tileset.h"
#include "scene/tiledata.h"

class TileItem:public QGraphicsItem
{
    TileData* m_tile_data;
public:
    TileItem(int tilesetX,int tilesetY,int tilesetIndex,QVector<Tileset*>& linked_tilesets,QGraphicsItem* parent);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~TileItem();
signals:

public slots:
};

#endif // TILEITEM_H

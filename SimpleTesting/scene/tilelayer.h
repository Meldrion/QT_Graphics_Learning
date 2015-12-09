#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "scene/abstractscenelayer.h"
#include "tileset.h"
#include "tileitem.h"
#include <QVector>
#include <QGraphicsSceneMouseEvent>

namespace Ignis {
    class TileLayer : public AbstractSceneLayer
    {
        QVector<Tileset*> m_linked_tilesets;
        QVector<QVector<TileItem* > > m_elements;
    public:
        TileLayer(int unit_width,int unit_height,int unit_size,QGraphicsItem* parent = 0);
        void init();
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void addTileAt(int x,int y, int tilesetIndex,int tilesetX,int tilesetY);
        void deleteTileAt(int x,int y);
        void addTileset(Tileset* tileset);
    signals:

    public slots:
    };
}
#endif // GAMESCENE_H

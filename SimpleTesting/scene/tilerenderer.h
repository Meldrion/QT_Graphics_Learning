#ifndef TILERENDERER_H
#define TILERENDERER_H

#include <QDebug>
#include <QPainter>
#include "scene/tiledata.h"
#include <QVector>

namespace Ignis
{
    class TileRenderer
    {
        TileData* m_current_tile;
        TileRenderer();
        static TileRenderer* m_instance;
        QVector<QPainter::PixmapFragment> m_fragments;
    public:
        static TileRenderer* instance();
        void render(QPainter* painter,TileData* tile,int x,int y);
        void flush(QPainter* painter);
    };
}

#endif // TILERENDERER_H

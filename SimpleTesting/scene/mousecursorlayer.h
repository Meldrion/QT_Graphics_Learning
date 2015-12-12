#ifndef MOUSECURSORLAYER_H
#define MOUSECURSORLAYER_H

#include <QtMath>
#include <QRectF>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "scene/abstractscenelayer.h"
#include "scene/mousecursor.h"
#include "tileset.h"

namespace Ignis
{
    class MouseCursorLayer : public AbstractSceneLayer
    {
    public:
        MouseCursorLayer(int unit_width,int unit_height,int unit_size,
                         QGraphicsItem *parent = 0);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
        void setCurrentTileset(Tileset* tileset);
        void setTilesetSelection(const QRectF &rect);

    private:
        MouseCursor* m_mouseCursor;
        QPointF m_mouse_unit_position;
        Tileset* m_current_tileset;
        QRectF m_current_selection_rect;
        int m_current_layer_index;
        bool m_mouse_is_down;
    signals:

    public slots:
    };
}

#endif // MOUSECURSORLAYER_H

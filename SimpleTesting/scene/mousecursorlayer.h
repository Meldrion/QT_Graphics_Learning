#ifndef MOUSECURSORLAYER_H
#define MOUSECURSORLAYER_H

#include <QtMath>
#include <QRectF>
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
        void setCurrentTileset(Tileset* tileset);
        void setTilesetSelection(const QRectF &rect);

    private:
        MouseCursor* m_mouseCursor;
        QPointF m_mouse_unit_position;
        Tileset* m_current_tileset;
        QRectF m_current_selection_rect;
    signals:

    public slots:
    };
}

#endif // MOUSECURSORLAYER_H

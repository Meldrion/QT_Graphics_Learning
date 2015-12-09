#ifndef MOUSECURSORLAYER_H
#define MOUSECURSORLAYER_H

#include "scene/abstractscenelayer.h"
#include "scene/mousecursor.h"
#include <QtMath>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

namespace Ignis
{
    class MouseCursorLayer : public AbstractSceneLayer
    {
    public:
        MouseCursorLayer(int unit_width,int unit_height,int unit_size,
                         QGraphicsItem *parent = 0);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    private:
        MouseCursor* m_mouseCursor;
        QPointF m_mouse_unit_position;
    signals:

    public slots:
    };
}

#endif // MOUSECURSORLAYER_H

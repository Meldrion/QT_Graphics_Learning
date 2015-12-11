#ifndef ABSTRACTSCENELAYER_H
#define ABSTRACTSCENELAYER_H

#include <QGraphicsItem>
#include <QRect>
#include <QPainter>
#include <QPointF>

namespace Ignis {
    class AbstractSceneLayer : public QGraphicsItem
    {
        public:
            AbstractSceneLayer(int unit_width,int unit_height,int unit_size,
                               QGraphicsItem *parent);
            QRectF boundingRect() const;
            void setUnitSize(int unitSize);
            void setUnitDimension(int unit_width,int unit_height);
            void setZoom(float zoom);
            void setRenderingStartPosition(const QPointF& startPos);
            void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
            void mousePressEvent(QGraphicsSceneMouseEvent *event);
            void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
        protected:
            int m_unit_width;
            int m_unit_height;
            int m_unit_size;
            QPointF m_startPosition;
            float m_zoom;
        signals:

        public slots:
    };
}

#endif // ABSTRACTSCENELAYER_H

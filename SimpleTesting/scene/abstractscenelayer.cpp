#include "abstractscenelayer.h"

using namespace Ignis;

AbstractSceneLayer::AbstractSceneLayer(int unit_width,int unit_height,int unit_size,
                                       QGraphicsItem *parent) : QGraphicsItem(parent)
{
    m_unit_width = unit_width;
    m_unit_height = unit_height;
    m_unit_size = unit_size;
    setFlag(QGraphicsItem::ItemClipsChildrenToShape);
}

void AbstractSceneLayer::setUnitSize(int unitSize)
{
    m_unit_size = unitSize;
}

void AbstractSceneLayer::setUnitDimension(int unit_width, int unit_height)
{
    m_unit_width = unit_width;
    m_unit_height = unit_height;
}

QRectF AbstractSceneLayer::boundingRect() const
{
    return QRectF(0,0,m_unit_width * m_unit_size,m_unit_height * m_unit_size);
}

void AbstractSceneLayer::setZoom(float zoom)
{
    if (zoom < 0.2f) {zoom = 0.2f;}
    m_zoom = zoom;
}

void AbstractSceneLayer::setRenderingStartPosition(const QPointF &startPos)
{
    m_startPosition.setX(startPos.x());
    m_startPosition.setY(startPos.y());
}

void AbstractSceneLayer::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
}

void AbstractSceneLayer::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
}

void AbstractSceneLayer::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
}

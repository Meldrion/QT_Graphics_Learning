#include "mousecursorlayer.h"

using namespace Ignis;

MouseCursorLayer::MouseCursorLayer(int unit_width,int unit_height,int unit_size,
                                   QGraphicsItem *parent):AbstractSceneLayer(unit_width,unit_height,unit_size,parent)
{
    m_mouse_is_down = false;
    m_current_layer_index = 0;
    m_mouseCursor = new MouseCursor(unit_size,this);
    m_mouse_unit_position = QPointF(0,0);
    m_mouseCursor->setSelectionStart(0,10);
    m_mouseCursor->setSelectionDimension(5,5);
    hide();
}

void MouseCursorLayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

void MouseCursorLayer::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    const QPointF scenePos = event->scenePos();
    if (boundingRect().contains(scenePos))
    {
        m_mouseCursor->show();
        QPointF unit_pos = QPointF((int) scenePos.x() / m_unit_size,(int) scenePos.y() / m_unit_size);
        if (unit_pos.x() != m_mouse_unit_position.x() || unit_pos.y() != m_mouse_unit_position.y())
        {
            m_mouse_unit_position = QPointF(unit_pos);

            m_mouseCursor->setPos(m_mouse_unit_position.x() * m_unit_size,
                                  m_mouse_unit_position.y() * m_unit_size);
        }
    }
        else
    {
        m_mouseCursor->hide();
    }
}

void MouseCursorLayer::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_mouse_is_down = true;
}

void MouseCursorLayer::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_mouse_is_down = false;
}

void MouseCursorLayer::setCurrentTileset(Tileset* tileset)
{
    m_current_tileset = tileset;
    this->m_mouseCursor->setCurrentTileset(tileset);
}

void MouseCursorLayer::setTilesetSelection(const QRectF &rect)
{
    m_current_selection_rect = QRectF(rect);
    m_mouseCursor->setSelectionStart(rect.x(),rect.y());
    m_mouseCursor->setSelectionDimension(rect.width(),rect.height());
}

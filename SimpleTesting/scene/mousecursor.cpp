#include "mousecursor.h"

using namespace Ignis;

MouseCursor::MouseCursor(int unit_size,QGraphicsItem* parent) : QGraphicsItem(parent)
{
    m_rect_color = QColor(255,0,0,128);
    m_unit_size = unit_size;
    m_unit_selection_width = 1;
    m_unit_selection_height = 1;
}

QRectF MouseCursor::boundingRect() const
{
    return QRectF(0,0,m_unit_size * m_unit_selection_width,m_unit_size * m_unit_selection_height);
}

void MouseCursor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->fillRect(boundingRect(),QBrush(m_rect_color));
}

void MouseCursor::setSelectionDimension(int unit_selection_width, int unit_selection_height)
{
    m_unit_selection_width = unit_selection_width;
    m_unit_selection_height = unit_selection_height;
}

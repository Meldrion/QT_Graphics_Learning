#include "mousecursor.h"

using namespace Ignis;

MouseCursor::MouseCursor(int unit_size,QGraphicsItem* parent) : QGraphicsItem(parent)
{
    m_unit_start_X = 0;
    m_unit_start_Y = 0;
    m_current_tileset = 0x0;
    m_rect_color = QColor(255,0,0,115);
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
    const QRectF& rect = boundingRect();
    if (m_current_tileset)
    {
        painter->setOpacity(0.45);
        for (int i=m_unit_start_X;i<m_unit_start_X + m_unit_selection_width;i++)
        {
            for (int j=m_unit_start_Y;j<m_unit_start_Y + m_unit_selection_width;j++)
            {
                if (m_current_tileset->isInRange(i,j))
                {
                    painter->drawPixmap((i - m_unit_start_X) * m_unit_size,
                                        (j - m_unit_start_Y) * m_unit_size,
                                        m_unit_size, m_unit_size,*m_current_tileset->getTileAt(i,j));
                }
            }
        }
    }

    painter->fillRect(rect,QBrush(m_rect_color));
}

void MouseCursor::setSelectionStart(int selection_start_x, int selection_start_y)
{
    m_unit_start_X = selection_start_x;
    m_unit_start_Y = selection_start_y;
}

void MouseCursor::setSelectionDimension(int unit_selection_width, int unit_selection_height)
{
    m_unit_selection_width = unit_selection_width;
    m_unit_selection_height = unit_selection_height;
}

void MouseCursor::setCurrentTileset(Tileset *tileset)
{
    m_current_tileset = tileset;
}

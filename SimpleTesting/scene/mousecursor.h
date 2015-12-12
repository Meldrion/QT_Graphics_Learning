#ifndef MOUSECURSOR_H
#define MOUSECURSOR_H

#include <QGraphicsItem>
#include <QPainter>
#include "tileset.h"

namespace Ignis {
    class MouseCursor : public QGraphicsItem
    {
    private:
        int m_unit_size;
        QColor m_rect_color;
        int m_unit_start_X;
        int m_unit_start_Y;
        int m_unit_selection_width;
        int m_unit_selection_height;
        Tileset* m_current_tileset;
    public:
        MouseCursor(int unit_size,QGraphicsItem* parent = 0);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void setSelectionStart(int selection_start_x,int selection_start_y);
        void setSelectionDimension(int unit_selection_width,int unit_selection_height);
        void setCurrentTileset(Tileset* tileset);
    };
}

#endif // MOUSECURSOR_H

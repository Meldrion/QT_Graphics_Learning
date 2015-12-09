#include "mousecursor.h"

using namespace Ignis;

MouseCursor::MouseCursor(QGraphicsItem* parent) : QGraphicsItem(parent)
{
}

QRectF MouseCursor::boundingRect() const
{
    return QRectF(0,0,32,32);
}

void MouseCursor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->fillRect(boundingRect(),QBrush(QColor(255,0,0,128)));
}


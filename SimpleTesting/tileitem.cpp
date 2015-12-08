#include "tileitem.h"

TileItem::TileItem(QPixmap* tile,QGraphicsItem* parent) : QGraphicsItem(parent)
{
    m_tile = tile;
}

QRectF TileItem::boundingRect() const
{
    return QRectF(0,0,m_tile->width(),m_tile->height());
}

void TileItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QPoint(0,0),*m_tile);
}

TileItem::~TileItem()
{
    m_tile = 0x0;
}

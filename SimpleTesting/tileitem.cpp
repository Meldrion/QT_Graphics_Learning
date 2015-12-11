#include "tileitem.h"

TileItem::TileItem(int tilesetX,int tilesetY,int tilesetIndex,QVector<Tileset*>& linked_tilesets,QGraphicsItem* parent) : QGraphicsItem(parent)
{
    QPixmap* tile_image = linked_tilesets.at(tilesetIndex)->getTileAt(tilesetX,tilesetY);
    m_tile_data = new TileData(tilesetX,tilesetY,tilesetIndex,tile_image);
}

QRectF TileItem::boundingRect() const
{
    return QRectF(0,0,m_tile_data->tilePicture()->width(),m_tile_data->tilePicture()->height());
}

void TileItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap* tile = m_tile_data->tilePicture();
    painter->drawPixmap(0,0,tile->width(),tile->height(),*tile);
}

TileItem::~TileItem()
{
    delete m_tile_data;
}

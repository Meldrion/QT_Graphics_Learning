#include "tiledata.h"

TileData::TileData(int tileset_x,int tileset_y,int tileset_index,QPixmap* tile_picture)
{
    m_tileset_x = tileset_x;
    m_tileset_y = tileset_y;
    m_tileset_index = tileset_index;
    m_tile_picture = tile_picture;
}

int TileData::tilesetX()
{
    return m_tileset_x;
}

int TileData::tilesetY()
{
    return m_tileset_y;
}

int TileData::tilesetIndex()
{
    return m_tileset_index;
}


QPixmap* TileData::tilePicture()
{
    return m_tile_picture;
}

bool TileData::equals(TileData* other)
{
    return m_tileset_index == other->tilesetIndex() &&
           m_tileset_x == other->tilesetX() &&
           m_tileset_y == other->tilesetY();
}

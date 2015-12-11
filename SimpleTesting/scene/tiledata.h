#ifndef TILEDATA_H
#define TILEDATA_H

#include <QPixmap>

class TileData
{
    int m_tileset_x;
    int m_tileset_y;
    int m_tileset_index;
    QPixmap* m_tile_picture;
public:
    TileData(int tileset_x,int tileset_y,int tileset_index,QPixmap* tile_picture);
    int tilesetX();
    int tilesetY();
    int tilesetIndex();
    QPixmap* tilePicture();
    bool equals(TileData* other);
signals:

public slots:
};

#endif // TILEDATA_H

#include "tileset.h"

Tileset::Tileset(QString path,int tileDim)
{
    QPixmap tilesetImage;
    if (tilesetImage.load(path))
    {
        m_tileset_real_width = tilesetImage.width();
        m_tileset_real_height = tilesetImage.height();
        m_tileset_unit_width = m_tileset_real_width / tileDim;
        m_tileset_unit_height = m_tileset_real_height / tileDim;

        QPixmap* current_tile = 0x0;

        for (int x = 0; x < m_tileset_unit_width; x++)
        {
            QVector<QPixmap*> innerVector;
            for (int y = 0; y < m_tileset_unit_height
                 ; y++)
            {
                current_tile = new QPixmap(tilesetImage.copy(x * tileDim,y * tileDim,tileDim,tileDim));
                innerVector.append(current_tile);
            }
            m_tiles.append(innerVector);
        }
    }
        else
    {
        qDebug() << "Could not load image " << path;
    }
}

bool Tileset::isInRange(int x, int y)
{
    return 0 <= x && 0 <= y && x < m_tileset_unit_width && y < m_tileset_unit_height;
}

QPixmap* Tileset::getTileAt(int x, int y)
{
    return m_tiles.at(x).at(y);
}


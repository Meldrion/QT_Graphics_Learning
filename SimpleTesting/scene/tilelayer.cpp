#include "tilelayer.h"

using namespace Ignis;

TileLayer::TileLayer(int unit_width, int unit_height, int unit_size, QGraphicsItem *parent)
    : AbstractSceneLayer(unit_width,unit_height,unit_size,parent)
{
    m_startPosition = QPointF(0,0);
    m_zoom = 1.0;
    init();
}

void TileLayer::init()
{
    m_elements.clear();
    for (int i=0;i<m_unit_width;i++)
    {
        QVector<TileData*> innerVector;
        for (int j=0;j<m_unit_height;j++)
        {
            innerVector.append(0x0);
        }
        m_elements.append(innerVector);
    }
}

void TileLayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    float tileDim = 32 * m_zoom;
    int startX = (int) m_startPosition.x() / tileDim;
    int startY = (int) m_startPosition.y() / tileDim;
    int width = qCeil(widget->width() / tileDim);
    int height = qCeil(widget->height() / tileDim);

    int endX = qMin(startX + width,m_unit_width - 1);
    startX = endX - width;
    int endY = qMin(startY + height,m_unit_height - 1);
    startY = endY - height;

    for (int i = startX;i <= endX;i++) {
        for (int j = startY;j <= endY;j++) {

            TileData* tile = m_elements[i][j];
            if (tile)
            {
                TileRenderer::instance()->render(painter,tile,i,j);
            }
        }
    }

    TileRenderer::instance()->flush(painter);
}

void TileLayer::addTileAt(int x, int y,int tilesetIndex,int tilesetX,int tilesetY)
{
    delete m_elements[x][y];
    TileData* data = new TileData(tilesetX,tilesetY,tilesetIndex,
                                  m_linked_tilesets.at(tilesetIndex)->getTileAt(tilesetX,tilesetY));
    m_elements[x][y] = data;
}

void TileLayer::deleteTileAt(int x, int y)
{
    delete m_elements[x][y];
    m_elements[x][y] = 0x0;
}

void TileLayer::addTileset(Tileset *tileset)
{
    this->m_linked_tilesets.append(tileset);
}

#include "tilelayer.h"

using namespace Ignis;

TileLayer::TileLayer(int unit_width, int unit_height, int unit_size, QGraphicsItem *parent)
    : AbstractSceneLayer(unit_width,unit_height,unit_size,parent)
{
    init();
}

void TileLayer::init()
{
    m_elements.clear();
    for (int i=0;i<m_unit_width;i++)
    {
        QVector<TileItem*> innerVector;
        for (int j=0;j<m_unit_height;j++)
        {
            innerVector.append(0x0);
        }
        m_elements.append(innerVector);
    }
}

void TileLayer::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (boundingRect().contains(event->scenePos()))
    {
    }
}

void TileLayer::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (boundingRect().contains(event->scenePos()))
    {
        int x_unit_pos = (int) (event->scenePos().x() / 32);
        int y_unit_pos = (int) (event->scenePos().y() / 32);
        //addTileAt(x_unit_pos,y_unit_pos,1,0);
    }
}

void TileLayer::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}

void TileLayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

void TileLayer::addTileAt(int x, int y,int tilesetIndex,int tilesetX,int tilesetY)
{
    delete m_elements[x][y];
    TileItem* item = new TileItem(m_linked_tilesets.at(tilesetIndex)->getTileAt(tilesetX,tilesetY),this);
    item->setPos(x*m_unit_size,y*m_unit_size);
    m_elements[x][y] = item;
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

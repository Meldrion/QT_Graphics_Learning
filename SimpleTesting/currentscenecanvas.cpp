#include "currentscenecanvas.h"

CurrentSceneCanvas::CurrentSceneCanvas(int unit_width,int unit_height,int unit_size,QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    setUnitDimension(unit_width,unit_height);
    setUnitSize(unit_size);
    cursor = new QGraphicsRectItem(this);
    cursor->setPen(QColor(255,0,0,128));
    cursor->setBrush(QColor(255,0,0,128));
    cursor->setRect(0,0,unit_size,unit_size);
    cursor->setZValue(9999);
    setFlag(QGraphicsItem::ItemClipsChildrenToShape);
    init();

    // Dummy Code
    this->m_linked_tilesets.append(new Tileset("desert.png"));
    TileItem* item = new TileItem(m_linked_tilesets.at(0)->getTileAt(0,0),this);
    m_elements[0].replace(0,item);
}

QRectF CurrentSceneCanvas::boundingRect() const
{
    return QRectF(0,0,m_unit_width * m_unit_size,m_unit_height * m_unit_size);
}

void CurrentSceneCanvas::setUnitSize(int unitSize)
{
    m_unit_size = unitSize;
}

void CurrentSceneCanvas::setUnitDimension(int unit_width, int unit_height)
{
    m_unit_width = unit_width;
    m_unit_height = unit_height;
}

void CurrentSceneCanvas::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (boundingRect().contains(event->scenePos()))
    {
        if (!cursor->isVisible())
        {
            cursor->show();
        }
        int xPos = (int) (event->scenePos().x() / 32) * 32;
        int yPos = (int) (event->scenePos().y() / 32) * 32;
        this->cursor->setPos(xPos,yPos);
    } else {
        if (cursor->isVisible())
        {
            cursor->hide();
        }
    }
}

void CurrentSceneCanvas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    painter->fillRect(rect,QBrush(QColor(255,255,255)));
    painter->setPen(QPen(QColor(0,0,0)));
    QRectF outerBounding(rect.x() - 1 , rect.y() - 1,
                         rect.width() + 2 , rect.height() + 2);
    painter->drawRect(outerBounding);
}

void CurrentSceneCanvas::init()
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

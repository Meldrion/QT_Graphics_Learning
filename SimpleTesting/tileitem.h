#ifndef TILEITEM_H
#define TILEITEM_H

#include <QPixmap>
#include <QGraphicsItem>
#include <QPainter>

class TileItem:public QGraphicsItem
{
    QPixmap* m_tile;
public:
    TileItem(QPixmap* tile,QGraphicsItem* parent);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~TileItem();
signals:

public slots:
};

#endif // TILEITEM_H

#ifndef MOUSECURSOR_H
#define MOUSECURSOR_H

#include <QGraphicsItem>
#include <QPainter>

namespace Ignis {
    class MouseCursor : public QGraphicsItem
    {
    public:
        MouseCursor(QGraphicsItem* parent = 0);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    signals:

    public slots:
    };
}

#endif // MOUSECURSOR_H

#ifndef SOMETESTSCENE_H
#define SOMETESTSCENE_H

#include <QDebug>
#include <QWidget>
#include <QGraphicsScene>
#include "scene/tilelayer.h"

namespace Ignis
{
    class Scene : public QGraphicsScene
    {
    public:
        Scene(QWidget* parent = 0);
        ~Scene();
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        void changeViewport(const QPointF &startPosition,const float zoom);
        void addLayer(Ignis::AbstractSceneLayer* layer);
    private:
        QVector<Ignis::AbstractSceneLayer*> m_layers;
    signals:

    public slots:
    };
}

#endif // SOMETESTSCENE_H

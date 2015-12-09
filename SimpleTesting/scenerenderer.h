#ifndef SOMETESTSCENE_H
#define SOMETESTSCENE_H

#include <QDebug>
#include <QWidget>
#include <QGraphicsScene>
#include "scene/tilelayer.h"

class SceneRenderer : public QGraphicsScene
{
public:
    SceneRenderer(QWidget* parent = 0);
    ~SceneRenderer();
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void addLayer(Ignis::AbstractSceneLayer* layer);
private:
    QVector<Ignis::AbstractSceneLayer*> m_layers;
signals:

public slots:
};

#endif // SOMETESTSCENE_H

#ifndef SOMETESTSCENE_H
#define SOMETESTSCENE_H

#include <QDebug>
#include <QWidget>
#include <QGraphicsScene>
#include "currentscenecanvas.h"

class SceneRenderer : public QGraphicsScene
{
    CurrentSceneCanvas* current_scene_canvas;
public:
    SceneRenderer(QWidget* parent = 0);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
signals:

public slots:
};

#endif // SOMETESTSCENE_H

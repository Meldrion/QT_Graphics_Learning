#include "scenerenderer.h"

SceneRenderer::SceneRenderer(QWidget* parent):QGraphicsScene(parent)
{
    setBackgroundBrush(QBrush(QColor(96,96,96)));
    current_scene_canvas = new CurrentSceneCanvas(20,15,32);
    this->addItem(current_scene_canvas);
}

void SceneRenderer::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    current_scene_canvas->mouseMoveEvent(event);
    QGraphicsScene::mouseMoveEvent(event);
}

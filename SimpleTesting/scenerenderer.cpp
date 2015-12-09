#include "scenerenderer.h"

SceneRenderer::SceneRenderer(QWidget* parent):QGraphicsScene(parent)
{
    setBackgroundBrush(QBrush(QColor(96,96,96)));
}

SceneRenderer::~SceneRenderer()
{
    for (QVector<Ignis::AbstractSceneLayer*>::iterator it = m_layers.begin();it != m_layers.end();++it)
    {
        delete *it;
    }
}

void SceneRenderer::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    for (QVector<Ignis::AbstractSceneLayer*>::iterator it = m_layers.begin();it != m_layers.end();++it)
    {
        Ignis::AbstractSceneLayer* layer = *it;
        layer->mouseMoveEvent(event);
    }

    QGraphicsScene::mouseMoveEvent(event);
}

void SceneRenderer::addLayer(Ignis::AbstractSceneLayer *layer)
{
    if (!m_layers.contains(layer))
    {
        this->m_layers.append(layer);
        this->addItem(layer);
    }
}

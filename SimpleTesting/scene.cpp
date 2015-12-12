#include "scene.h"

using namespace Ignis;

Scene::Scene(QWidget* parent):QGraphicsScene(parent)
{
    setBackgroundBrush(QBrush(QColor(96,96,96)));
}

Scene::~Scene()
{
    for (QVector<Ignis::AbstractSceneLayer*>::iterator it = m_layers.begin();it != m_layers.end();++it)
    {
        delete *it;
    }
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    for (QVector<Ignis::AbstractSceneLayer*>::iterator it = m_layers.begin();it != m_layers.end();++it)
    {
        Ignis::AbstractSceneLayer* layer = *it;
        layer->mouseMoveEvent(event);
    }

    QGraphicsScene::mouseMoveEvent(event);
}

void Scene::mouseLeaveEvent()
{
    for (QVector<Ignis::AbstractSceneLayer*>::iterator it = m_layers.begin();it != m_layers.end();++it)
    {
        Ignis::AbstractSceneLayer* layer = *it;
        Ignis::MouseCursorLayer* mouseLayer = dynamic_cast<Ignis::MouseCursorLayer*>(layer);
        if (mouseLayer)
        {
            mouseLayer->hide();
        }
    }
}

void Scene::mouseEnterEvent()
{
    for (QVector<Ignis::AbstractSceneLayer*>::iterator it = m_layers.begin();it != m_layers.end();++it)
    {
        Ignis::AbstractSceneLayer* layer = *it;
        Ignis::MouseCursorLayer* mouseLayer = dynamic_cast<Ignis::MouseCursorLayer*>(layer);
        if (mouseLayer)
        {
            mouseLayer->show();
        }
    }
}

void Scene::changeViewport(const QPointF &startPosition,const float zoom)
{
    for (QVector<Ignis::AbstractSceneLayer*>::iterator it = m_layers.begin();it != m_layers.end();++it)
    {
        Ignis::AbstractSceneLayer* layer = *it;
        layer->setZoom(zoom);
        layer->setRenderingStartPosition(startPosition);
    }
}

void Scene::addLayer(Ignis::AbstractSceneLayer *layer)
{
    if (!m_layers.contains(layer))
    {
        this->m_layers.append(layer);
        this->addItem(layer);
    }
}

#include "scenecanvas.h"

SceneCanvas::SceneCanvas(QWidget* parent):QGraphicsView(parent)
{

    this->setMouseTracking(true);
    zoomValue = 250;
}

void SceneCanvas::wheelEvent(QWheelEvent *event) {

    if (QApplication::keyboardModifiers() & Qt::ControlModifier)
    {
        if (event->delta() > 0)
        {
            zoomValue += 6;
            if (500 < zoomValue)
            {
                zoomValue = 500;
            }
        }
        else
        {
            zoomValue -= 6;
            if (zoomValue < 0)
            {
                zoomValue = 0;
            }
        }

        setupMatrix();
    }
}

void SceneCanvas::setupMatrix()
{
    qreal scale = qPow(qreal(2), (zoomValue - 250) / qreal(50));
    QMatrix matrix;
    matrix.scale(scale, scale);
    this->setMatrix(matrix);
}

void SceneCanvas::init()
{
    int mapWidth = 400;
    int mapHeight = 400;
    int tileDim = 32;
    m_scene = new SceneRenderer(this);
    this->setScene(m_scene);
    m_scene->setSceneRect(0,0,tileDim * mapWidth,tileDim * mapHeight);
    this->centerOn(0,0);
}

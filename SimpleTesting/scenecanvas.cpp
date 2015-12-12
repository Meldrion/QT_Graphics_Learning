#include "scenecanvas.h"

SceneCanvas::SceneCanvas(QWidget* parent):QGraphicsView(parent)
{
    this->setMouseTracking(true);
    this->setDragMode(QGraphicsView::NoDrag);
    zoomValue = 250;
}

void SceneCanvas::leaveEvent(QEvent *event)
{
    if (m_scene) {m_scene->mouseLeaveEvent();}
}

void SceneCanvas::enterEvent(QEvent *event)
{
    if (m_scene) {m_scene->mouseEnterEvent();}
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
    } else {
        QGraphicsView::wheelEvent(event);
    }
}

void SceneCanvas::scrollContentsBy(int dx, int dy)
{
    QGraphicsView::scrollContentsBy(dx,dy);
    if (m_scene)
    {
        qreal scale = qPow(qreal(2), (zoomValue - 250) / qreal(50));
        if (scale < 0.2) {scale = 0.2;}
        int tX = this->horizontalScrollBar()->value();
        int tY = this->verticalScrollBar()->value();
        this->m_scene->changeViewport(QPointF(tX,tY),scale);
        this->m_scene->update(tX,tY,width() / scale,height() / scale);
    }
}

void SceneCanvas::setupMatrix()
{
    qreal scale = qPow(qreal(2), (zoomValue - 250) / qreal(50));
    if (scale < 0.2) {scale = 0.2;}

    int tX = this->horizontalScrollBar()->value();
    int tY = this->verticalScrollBar()->value();
    this->m_scene->changeViewport(QPointF(tX,tY),scale);

    QMatrix matrix;
    matrix.scale(scale, scale);
    this->setMatrix(matrix);
}

void SceneCanvas::init()
{
    int mapWidth = 250;
    int mapHeight = 250;
    int tileDim = 32;
    m_scene = new Ignis::Scene(this);

    Ignis::SceneBackgroundWhiteLayer* background = new Ignis::SceneBackgroundWhiteLayer(mapWidth,mapHeight,tileDim);
    Ignis::TileLayer* tileLayer = new Ignis::TileLayer(mapWidth,mapHeight,tileDim);
    Ignis::TileLayer* tileLayer2 = new Ignis::TileLayer(mapWidth,mapHeight,tileDim);
    Ignis::TileLayer* tileLayer3 = new Ignis::TileLayer(mapWidth,mapHeight,tileDim);
    Ignis::TileLayer* tileLayer4 = new Ignis::TileLayer(mapWidth,mapHeight,tileDim);

    Ignis::MouseCursorLayer* mouseCursor = new Ignis::MouseCursorLayer(mapWidth,mapHeight,tileDim);

    m_scene->addLayer(background);
    m_scene->addLayer(tileLayer);
    m_scene->addLayer(tileLayer2);
    m_scene->addLayer(tileLayer3);
    m_scene->addLayer(tileLayer4);
    m_scene->addLayer(mouseCursor);

    // Dummy
    Tileset* desertTileset = new Tileset("desert.png",32);

    tileLayer->addTileset(desertTileset);
    tileLayer2->addTileset(desertTileset);
    tileLayer3->addTileset(desertTileset);
    tileLayer4->addTileset(desertTileset);
    mouseCursor->setCurrentTileset(desertTileset);

    int tX = 0;
    int tY = 0;

    for (int i=0;i<mapWidth;i++)
    {
        tX = (tX == 7)?0:++tX;
        for (int j=0;j<mapHeight;j++)
        {
            tY = (tY == 14)?0:++tY;

            //tileLayer->addTileAt(i,j,0,1,0);

            // Worst Case
            tileLayer->addTileAt(i,j,0,tX,tY);
            tileLayer2->addTileAt(i,j,0,tX,tY);
            tileLayer3->addTileAt(i,j,0,tX,tY);
            tileLayer4->addTileAt(i,j,0,tX,tY);
        }
    }
    // Dummy end

    this->setScene(m_scene);
    m_scene->setSceneRect(0,0,tileDim * mapWidth,tileDim * mapHeight);
    this->centerOn(0,0);
}

#ifndef SCENECANVAS_H
#define SCENECANVAS_H

#include <QWheelEvent>
#include <QGraphicsView>
#include <QColor>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QtMath>
#include <QDebug>
#include <QApplication>
#include "scenerenderer.h"

class SceneCanvas : public QGraphicsView
{
private:
    SceneRenderer* m_scene;
    QGraphicsRectItem* m_cursor;
    QGraphicsRectItem* m_scene_canvas;

    int zoomValue;
public:
    SceneCanvas(QWidget* parent = 0);
    void wheelEvent(QWheelEvent *event);
    void setupMatrix();
    void init();
signals:

public slots:
};

#endif // SCENECANVAS_H

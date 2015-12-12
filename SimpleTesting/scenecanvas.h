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
#include <QScrollBar>
#include "scene.h"
#include "scene/tilelayer.h"
#include "scene/mousecursorlayer.h"
#include "scene/scenebackgroundwhitelayer.h"

class SceneCanvas : public QGraphicsView
{
private:
    Ignis::Scene* m_scene;
    QGraphicsRectItem* m_cursor;
    QGraphicsRectItem* m_scene_canvas;
    int zoomValue;
public:
    SceneCanvas(QWidget* parent = 0);
    void leaveEvent(QEvent *event);
    void enterEvent(QEvent *event);
    void wheelEvent(QWheelEvent *event);
    void scrollContentsBy(int dx, int dy);
    void setupMatrix();
    void init();
signals:

public slots:
};

#endif // SCENECANVAS_H

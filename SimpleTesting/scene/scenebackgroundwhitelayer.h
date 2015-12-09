#ifndef SCENEBACKGROUNDWHITELAYER_H
#define SCENEBACKGROUNDWHITELAYER_H

#include "abstractscenelayer.h"

namespace Ignis
{
    class SceneBackgroundWhiteLayer : public AbstractSceneLayer
    {
    public:
        SceneBackgroundWhiteLayer(int unit_width, int unit_height,
                                  int unit_size, QGraphicsItem *parent = 0);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    signals:

    public slots:
    };
}
#endif // SCENEBACKGROUNDWHITELAYER_H

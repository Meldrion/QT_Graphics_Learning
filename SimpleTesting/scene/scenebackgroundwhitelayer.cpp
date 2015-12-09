#include "scenebackgroundwhitelayer.h"

using namespace Ignis;

SceneBackgroundWhiteLayer::SceneBackgroundWhiteLayer(int unit_width, int unit_height,
                                                     int unit_size, QGraphicsItem *parent)
    : AbstractSceneLayer(unit_width,unit_height,unit_size,parent)
{

}


void SceneBackgroundWhiteLayer::paint(QPainter *painter,
                                      const QStyleOptionGraphicsItem *option,
                                      QWidget *widget)
{

    QRectF rect = boundingRect();
    painter->fillRect(rect,QBrush(QColor(255,255,255)));
    painter->setPen(QPen(QColor(0,0,0)));
    QRectF outerBounding(rect.x() - 1 , rect.y() - 1,
                         rect.width() + 2 , rect.height() + 2);
    painter->drawRect(outerBounding);
}

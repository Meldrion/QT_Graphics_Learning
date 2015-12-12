#ifndef TILESET_H
#define TILESET_H

#include <QDebug>
#include <QString>
#include <QVector>
#include <QPixmap>

class Tileset
{
private:
    int m_tileset_unit_width;
    int m_tileset_unit_height;
    int m_tileset_real_width;
    int m_tileset_real_height;
    QVector<QVector<QPixmap*> > m_tiles;
public:
    Tileset(QString path,int tileDim = 32);
    bool isInRange(int x,int y);
    QPixmap* getTileAt(int x,int y);

signals:

public slots:
};

#endif // TILESET_H

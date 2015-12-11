#include "tilerenderer.h"

using namespace Ignis;

TileRenderer* TileRenderer::m_instance = 0x0;

TileRenderer::TileRenderer()
{
    m_current_tile = 0x0;
}

TileRenderer* TileRenderer::instance()
{
    if (!m_instance) {
        m_instance = new TileRenderer();
    }
    return m_instance;
}

void TileRenderer::render(QPainter* painter, TileData* tile, int x, int y)
{
    if (!tile) {return;}
    if (m_current_tile && !m_current_tile->equals(tile)) { flush(painter); }
    m_current_tile = tile;

    int w = tile->tilePicture()->width();
    int h = tile->tilePicture()->height();

    QPainter::PixmapFragment fragment;
    fragment.x = x * w + w / 2;
    fragment.y = y * h + h / 2;
    fragment.width = tile->tilePicture()->width();
    fragment.height = tile->tilePicture()->height();
    fragment.scaleX = 1;
    fragment.scaleY = 1;
    fragment.rotation = 0;
    fragment.opacity = 1;
    m_fragments.append(fragment);
}

void TileRenderer::flush(QPainter* painter)
{
    if (!m_current_tile)
        return;

    painter->drawPixmapFragments(m_fragments.constData(),
                                  m_fragments.size(),
                                  *m_current_tile->tilePicture());

    m_current_tile = 0x0;
    m_fragments.resize(0);
}

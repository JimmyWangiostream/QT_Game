#ifndef CHAFICON_H
#define CHAFICON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class chaficon: public QGraphicsPixmapItem{
public:
    chaficon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};
#endif // chaficon_H


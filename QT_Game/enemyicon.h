#ifndef ENEMYICON_H
#define ENEMYICON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class enemyicon: public QGraphicsPixmapItem{
public:
    enemyicon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};
#endif // ENEMYICON_H

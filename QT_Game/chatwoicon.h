#ifndef CHATWOICON_H
#define CHATWOICON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class chatwoicon: public QGraphicsPixmapItem{
public:
    chatwoicon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};
#endif // CHATWOICON_H

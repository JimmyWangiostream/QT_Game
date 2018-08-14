#ifndef CHATICON_H
#define CHATICON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class chaticon: public QGraphicsPixmapItem{
public:
    chaticon(QGraphicsItem* parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};
#endif // chatICON_H


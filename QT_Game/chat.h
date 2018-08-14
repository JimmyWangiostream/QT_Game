
#ifndef CHAT_H
#define CHAT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>

class chat: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    chat(QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
public slots:
    void move_forward();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
    int hp;
    int cango;
    int atk;
};


#endif // CHA3_H

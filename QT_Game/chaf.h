#ifndef CHAF_H
#define CHAF_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>

class chaf: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    chaf(QGraphicsItem * parent=0);
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

#endif // chaf_H

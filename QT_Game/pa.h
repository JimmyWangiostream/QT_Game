
#ifndef PA_H
#define PA_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>


class pa: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
     pa(QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
public slots:
    void move_forward();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
    int hp;
    int atk;
    int cango;
};

#endif // play_H


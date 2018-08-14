
#ifndef TRAP_H
#define TRAP_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Trap:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Trap(QGraphicsItem * parent=0);


};

#endif // Trap_H

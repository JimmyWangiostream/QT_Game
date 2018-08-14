
#include "Game.h"
#include <QFont>
#include "Trap.h"
#include <QPixmap>
#include <QGraphicsRectItem>

/*Trap::Trap(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/images/dsdfd.png"));
}*/
Trap::Trap(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/images/dsdfd.png");
        qreal width = p.width();qreal height = p.height();
        p=p.scaled(width/3,height/3,Qt::KeepAspectRatio);
        setPixmap(p);
}

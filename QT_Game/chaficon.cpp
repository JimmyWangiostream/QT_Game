#include "chaficon.h"
#include "Game.h"
#include "chaf.h"

extern Game * game;

chaficon::chaficon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/images/ch2.png");
        qreal width = p.width();qreal height = p.height();
        p=p.scaled(width/9,height/9,Qt::KeepAspectRatio);
        setPixmap(p);
}

void chaficon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->cf){
        game->cf = new chaf();
        game->setCursor();
    }
}

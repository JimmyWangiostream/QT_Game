#include "chatwoicon.h"
#include "Game.h"
#include "chatwo.h"

extern Game * game;

chatwoicon::chatwoicon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/images/cha2.png");
        qreal width = p.width();qreal height = p.height();
        p=p.scaled(width/5,height/5,Qt::KeepAspectRatio);
        setPixmap(p);
}

void chatwoicon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->c){
        game->c = new chatwo();
        game->setCursor();
    }
}

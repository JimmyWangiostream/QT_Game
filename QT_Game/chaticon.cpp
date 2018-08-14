#include "chaticon.h"
#include "Game.h"
#include "chat.h"

extern Game * game;

chaticon::chaticon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/images/asa.png");
        qreal width = p.width();qreal height = p.height();
        p=p.scaled(width/5,height/5,Qt::KeepAspectRatio);
        setPixmap(p);
}

void chaticon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->ct){
        game->ct = new chat();
        game->setCursor();
    }
}

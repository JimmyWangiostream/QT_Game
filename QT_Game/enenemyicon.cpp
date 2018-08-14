#include "enemyicon.h"
#include "Game.h"
#include "Enemy.h"

extern Game * game;

enemyicon::enemyicon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap p;p.load(":/images/plays.png");
        qreal width = p.width();qreal height = p.height();
        p=p.scaled(width/4,height/4,Qt::KeepAspectRatio);
        setPixmap(p);
}

void enemyicon::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if (!game->e){
        game->e = new Enemy();
        game->setCursor();
    }
}

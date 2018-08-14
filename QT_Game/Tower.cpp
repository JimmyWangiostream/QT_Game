#include "Tower.h"
#include <QPixmap>
#include "Bullet.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <QFont>

extern Game * game;

Tower::Tower(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){
    // set the graphics
    setPixmap(QPixmap(":/images/dfs.png"));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(attack()));
    timer->start(2000);

}

void Tower:: Towergg(){
    scene()->removeItem(this);
    game->bgmusic->stop();
    game->bgmusic->setMedia(QUrl("qrc:/music/winsound.mp3"));
    game->bgmusic->play();
    // delete them from the heap to save memory
    delete this;

}

void Tower::attack(){
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+70,y());

    game->scene->addItem(bullet);

}

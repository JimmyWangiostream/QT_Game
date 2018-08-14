
#include "pa.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "Game.h"
#include "Tower.h"
#include <stdlib.h>
#include "Trap.h"
#include"Enemy.h"


extern Game * game;

pa::pa(QGraphicsItem *parent){
    atk=0;
    // set graphics
    QPixmap p;p.load(":/images/en.png");
        qreal width = p.width();qreal height = p.height();
        p=p.scaled(width/3,height/3,Qt::KeepAspectRatio);
        setPixmap(p);
//int random_y = rand() % 500;
        //setPos(580,300);
    // set des HP
hp=10;
    // connect timer to move_forward
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);
}


void pa::move_forward(){
      QList<QGraphicsItem *> colliding_items = collidingItems();
cango=1;
      // if one of the colliding items is an play, destroy both the bullet and the play
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
          if (typeid(*(colliding_items[i])) == typeid(Tower)){
        game->hp->decrease();

        cango=0;
          }
         else  if (typeid(*(colliding_items[i])) == typeid(Trap)){
        scene()->removeItem(this);
                      delete this;
        cango=0;
          }
          else if (typeid(*(colliding_items[i])) == typeid(Enemy)||typeid(*(colliding_items[i])) == typeid(chatwo)){
                         hp-=2;
                            cango=0;
                              }
          else if (typeid(*(colliding_items[i])) == typeid(chat)||typeid(*(colliding_items[i])) == typeid(chaf)){
                         hp-=2;
                            cango=0;
                              }
                    else {
                       cango=1;
          }

      }
    if(hp<=0){
        scene()->removeItem(this);
        delete this;
    }
    if(x()<130){
        atk=1;
    }

    if(cango){
        if(atk==1){
            setPos(x(),y()+(200-y())/10);
        }
        else{
    setPos(x()-4, y());
        }
}

}




#include "Enemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "Game.h"
#include "Tower.h"
#include <stdlib.h>
#include "Trap.h"
#include "pa.h"

extern Game * game;
Enemy::Enemy(QGraphicsItem *parent){
    atk=0;
    // set graphics
    QPixmap p;p.load(":/images/plays.png");
        qreal width = p.width();qreal height = p.height();
        p=p.scaled(width/3,height/3,Qt::KeepAspectRatio);
        setPixmap(p);
   // int random_x = rand() % 100;
    /*int random_y = rand() % 500;
        setPos(180,random_y);
      */
    // set  HP des
 hp=15;

    // connect timer to move_forward
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);
}

void Enemy::move_forward(){

cango=1;
      QList<QGraphicsItem *> colliding_items = collidingItems();

      // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
          if (typeid(*(colliding_items[i])) == typeid(Tower)){
        game->health->decrease();
      cango=0;
          }
          else if (typeid(*(colliding_items[i])) == typeid(pa)){
               hp-=1;
                  cango=0;
                    }
          else if(typeid(*(colliding_items[i])) == typeid(Trap)){
        scene()->removeItem(this);
                      delete this;
          }
          else {
              cango=1;
}
      }

//66
    if(x()>760){
        atk=1;
    }
    if(hp<=0){
        scene()->removeItem(this);
        delete this;
    }
    if(cango){
        if(atk==1){
            setPos(x(),y()+(230-y())/10);
        }
        else{
    setPos(x()+3, y());
        }
}


}


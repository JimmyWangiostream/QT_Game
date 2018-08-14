#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QPixmap>
#include "Enemy.h"
#include "Game.h"
#include "Trap.h"
#include"pa.h"

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent){
   //setPixmap(QPixmap(":/images/reerrr.png"));
   QPixmap p;p.load(":/images/bom.png");
           qreal width = p.width();qreal height = p.height();
           p=p.scaled(width/2,height/2,Qt::KeepAspectRatio);
           setPixmap(p);
    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(70);
}

void Bullet::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
  for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;
            // return (all code below refers to a non existint bullet)
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Trap)){

            // remove them from the scene (still on the heap)

            scene()->removeItem(this);
            // delete them from the heap to save memory

            delete this;
            // return (all code below refers to a non existint bullet)
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(pa)){

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;
            // return (all code below refers to a non existint bullet)
            return;
        }

    }

    // if there was no collision with an Enemy, move the bullet forward
 if(x()>500)   setPos(x()-8,y());
else setPos(x()+8,y());
}

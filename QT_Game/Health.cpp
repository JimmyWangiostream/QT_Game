#include "Health.h"
#include <QFont>
#include "Game.h"


extern Game * game;
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 200;

    // draw the text
    setPlainText(QString("EnemyTower Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    /*health-=5;
   setPlainText(QString("EnemyTower Health: ") + QString::number(health));*/
   if(health==0){
       game->hp->clean();
        setPlainText(QString("YOU WIN !!"));
       game->t->Towergg();
   }
   else{health-=5;
  setPlainText(QString("EnemyTower Health: ") + QString::number(health));
   }
}
 void Health::clean(){
     scene()->removeItem(this);
     delete this;
}
int Health::getHealth(){
    return health;
}

#include "myhp.h"
#include <QFont>
#include "Game.h"
#include"Health.h"
extern Game * game;
myhp::myhp(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    hp = 200;

    // draw the text
    setPlainText(QString("MyTower myhp: ") + QString::number(hp)); // myhp: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}
void myhp::clean(){

    scene()->removeItem(this);
    // delete them from the heap to save memory

    delete this;
}
void myhp::decrease(){
   if(hp==0){
      game->health->clean();
        setPlainText(QString("YOU LOSE !!"));
       game->mt->Towergg();
   }
  else{ hp-=5;
  setPlainText(QString("MyTower myhp: ") + QString::number(hp));
   }
}

int myhp::getmyhp(){
    return hp;
}

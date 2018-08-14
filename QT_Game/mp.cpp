#include "mp.h"
#include <QFont>
#include "Game.h"
#include"QTimer"

extern Game * game;
mp::mp(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    mana = 25;

    // draw the text
    setPlainText(QString("YOUR MP: ") + QString::number(mana)); // mp:25
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}
int mp::getmana(){
    return mana;
}

void mp::increase(){
    mana++;
    setPlainText(QString("YOUR MP: ") + QString::number(mana));
}

void mp::decrease(int a){
   if(mana<a){
       can=0;
   }
   else{mana-=a;
       can=1;
  setPlainText(QString("YOUR MP: ") + QString::number(mana));
   }
}
int mp::getcan(){
    return can;
}

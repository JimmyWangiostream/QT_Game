#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>
#include <QGraphicsScene>
#include "Tower.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Health.h"
#include <qglobal.h>
#include "Trap.h"
#include "myhp.h"
#include "pa.h"
#include "enemyicon.h"
#include"chatwo.h"
#include "chatwoicon.h"
#include"chaticon.h"
#include"chaticon.h"
#include"chaf.h"
#include"chaficon.h"
#include <qmath.h>
Game::Game(): QGraphicsView(){
    // create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1000,800);
    setObjectName("mainWindow");
        setStyleSheet("#mainWindow{border-image:url(:/images/bg12.jpg);}");
    //setBackgroundBrush(QBrush(QImage(":/images/bbg.jpeg")));
    // set the scene
    setScene(scene);
    // set curosr
        cursor = nullptr;
        e= nullptr;
        c=nullptr;
        ct=nullptr;
         cf=nullptr;
        setMouseTracking(true);
card1=0;
card2=1;


    // create a ene tower
    t = new Tower();
    t->setPos(780,160);
    // add the tower to scene
    scene->addItem(t);
    mt = new Tower();
   mt->setPos(-150,150);
    scene->addItem(mt);
    //creat play

     /* pa * p=new pa();
      p->setPos(500,400);
      scene->addItem(p);
      */
/*create cha2
      c=new chatwo();
      c->setPos(200,450);
      scene->addItem(c2);
      */
    //enemyicon
ei=new enemyicon();
 ei->setPos(x()+20,y()+500);
 scene->addItem(ei);
  //c2icon
twoi=new chatwoicon();
 twoi->setPos(x()+80,y()+500);
 scene->addItem(twoi);

ti=new chaticon();
/* ti->setPos(x()+180,y()+500);
 scene->addItem(ti);*/
 //c4icon
fi=new chaficon();
/* fi->setPos(x()+230,y()+500);
 scene->addItem(fi);*/

   //create a trap
    Trap * cc = new Trap();
    cc->setPos(450,150);
    scene->addItem(cc);
    //add health
    health = new Health();
       health->setPos(health->x()+550,health->y()+25);
       scene->addItem(health);
       //add mp
       ma = new mp();
          ma->setPos(x()+550,y()+250);
          scene->addItem(ma);
          //

//add my hp

           hp = new myhp();
              hp->setPos(hp->x(),hp->y()+25);
              scene->addItem(hp);

    // alter window
     setFixedSize(1000,800);
   setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //add enemy
    // create enemy
     /* Enemy * enemy = new Enemy();
      enemy->setPos(250,400);
        scene->addItem(enemy);
*/
      //add bgm
        bgmusic = new QMediaPlayer();
            bgmusic->setMedia(QUrl("qrc:/music/winsound.mp3"));
            bgmusic->play();
            QTimer * manatimer = new QTimer(this);
            connect(manatimer,SIGNAL(timeout()),this,SLOT(manaincrease()));
             manatimer->start(2000);

}
/*void Game::lmi()
{
    connect(manatimer,SIGNAL(timeout()),this,SLOT(ea()));
    manatimer->start(2000);
}*/
void Game::manaincrease()
{
    //if(ma->getmana()<40)
    //{
        ma->decrease(10);
    //}

}
void Game::ea(){
    pa * p=new pa();
    p->setPos(500,400);
    scene->addItem(p);

}
void Game::wash(int card){
    if(card==2){
        ei=new enemyicon();
        ei->setPos(x()+20,y()+500);
        scene->addItem(ei);

    }
    else if(card==3){
        twoi=new chatwoicon();
            twoi->setPos(x()+80,y()+500);
            scene->addItem(twoi);
}

            else if(card==0){
        ti= new chaticon();
            ti->setPos(x()+160,y()+500);
            scene->addItem(ti);
}
            else if(card==1){
         fi=new chaficon();
            fi->setPos(x()+220,y()+500);
            scene->addItem(fi);

}
    else;
}

void Game::setCursor(){
    // if there is already a cursor, remove it first
    if (cursor){
        scene->removeItem(cursor);
        delete cursor;
    }
    cursor = new QGraphicsPixmapItem();
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event){
    if (cursor){
        cursor->setPos(event->pos());
    }
}

void Game::mousePressEvent(QMouseEvent *event){
    // if we are building
    if (e){
        // return if the cursor is colliding with a tower
        QList<QGraphicsItem *> items = cursor->collidingItems();
        for (size_t i = 0, n = items.size(); i < n; i++){
            if (dynamic_cast<Enemy*>(items[i])){
                return;
            }
        }
        // otherwise, build at the clicked locatio
        ma->decrease(3);
        if(ma->getcan()){
        scene->addItem(e);
       e->setPos(event->pos());
       //as
       scene->removeItem(ei);
                     delete ei;
       wash(0);
        }
       //as
        cursor = nullptr;
        e = nullptr;
        c=nullptr;
         ct=nullptr;
           cf=nullptr;

    }
    else if (c){
        // return if the cursor is colliding with a tower
        QList<QGraphicsItem *> items = cursor->collidingItems();
        for (size_t i = 0, n = items.size(); i < n; i++){
            if (dynamic_cast<Enemy*>(items[i])){
                return;
            }
        }
        // otherwise, build at the clicked location
        scene->addItem(c);
       c->setPos(event->pos());


       scene->removeItem(twoi);
                     delete twoi;
       wash(1 );


        cursor = nullptr;
       e = nullptr;
        c=nullptr;
         ct=nullptr;
           cf=nullptr;
    }
    //aa*/
    else if (ct){
        // return if the cursor is colliding with a tower
        QList<QGraphicsItem *> items = cursor->collidingItems();
        for (size_t i = 0, n = items.size(); i < n; i++){
            if (dynamic_cast<chat*>(items[i])){
                return;
            }
        }
        // otherwise, build at the clicked location
        scene->addItem(ct);
       ct->setPos(event->pos());
       scene->removeItem(ti);
                     delete ti;
       wash(2);

        cursor = nullptr;
       e = nullptr;
        c=nullptr;
        ct=nullptr;
          cf=nullptr;
    }
    else if (cf){
        // return if the cursor is colliding with a tower
        QList<QGraphicsItem *> items = cursor->collidingItems();
        for (size_t i = 0, n = items.size(); i < n; i++){
            if (dynamic_cast<chaf*>(items[i])){
                return;
            }
        }
        // otherwise, build at the clicked location
        scene->addItem(cf);
       cf->setPos(event->pos());

       scene->removeItem(fi);
                     delete fi;
       wash(3);

        cursor = nullptr;
       e = nullptr;
        c=nullptr;
         ct=nullptr;
         cf=nullptr;
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }

}


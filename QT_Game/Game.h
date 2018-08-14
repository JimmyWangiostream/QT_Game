#ifndef GAME_H
#define GAME_H
#include <QTimer>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "Tower.h"
#include "Health.h"
#include <QMediaPlayer>
#include"myhp.h"
#include "Enemy.h"
#include"chatwo.h"
#include"chat.h"
#include "chaf.h"
#include "enemyicon.h"
#include "chatwoicon.h"
#include"chaticon.h"
#include"chaficon.h"
#include"mp.h"
class Game: public QGraphicsView{
public:
    // member functions
    Game();
    void setCursor();
    QGraphicsPixmapItem * cursor;
       void mouseMoveEvent(QMouseEvent *event);
       void mousePressEvent(QMouseEvent *event);
   // void mousePressEvent(QMouseEvent *event);
       void wash(int i);
       void lmi();
QMediaPlayer * bgmusic;
    // member attributes
    QGraphicsScene * scene;
    Tower * t;
    Tower *mt;
    Health * health;
    myhp * hp;
    Enemy *e;
    chatwo *c;
    chat  *ct;
    chaf* cf;
      enemyicon *ei;
      chatwoicon *twoi;
      chaticon *ti;
      chaficon*fi;
      mp * ma;
private:
      int card1;
      int card2;
public slots:
      void manaincrease();
      void ea();
};

#endif // GAME_H

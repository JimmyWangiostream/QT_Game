#ifndef MP_H
#define MP_H


#include <QGraphicsTextItem>

class mp: public QGraphicsTextItem{

public:
   mp(QGraphicsItem * parent=0);
    void decrease(int i);
    int getcan();
    int getmana();
     void increase();
private:
    int can;
    int mana;
};


#endif // MP_H

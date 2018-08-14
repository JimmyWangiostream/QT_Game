#ifndef MYHP_H
#define MYHP_H


#include <QGraphicsTextItem>

class myhp: public QGraphicsTextItem{
public:
    myhp(QGraphicsItem * parent=0);
    void decrease();
    void clean();
    int getmyhp();
private:
    int hp;
};

#endif // myhp_H

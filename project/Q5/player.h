#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include "myitem.h"
class Player //: public QGraphicsItem
{
public:
    MyItem *particle_black;
    MyItem *particle1_white;
    Player(int x_black, int y_black, int x_white, int y_white);
    void move_event(int phase);
    template<class T> friend bool incl(T left1, T right1, T left2, T right2);
};

#endif // PLAYER_H

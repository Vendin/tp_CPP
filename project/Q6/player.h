#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include "myitem.h"
#include <QObject>

namespace Ui {
class Player;
}


class Player : public QObject//: QGraphicsItem
{
    Q_OBJECT
private:

public:
    MyItem *particle_black;
    MyItem *particle1_white;
    Player(int x_black, int y_black, int x_white, int y_white);
    void change_speed(int a, int b);
    bool get_speed_zero();
    template<class T> friend bool incl(T left1, T right1, T left2, T right2);
public slots:
        void move_event();
};

#endif // PLAYER_H

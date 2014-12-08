#include "player.h"
#include "dialog.h"
#include "myitem.h"


Player::Player(int x_black, int y_black, int x_white, int y_white)
{
    particle_black = new MyItem(x_black, y_black);
    particle1_white = new MyItem(x_white, y_white);
    /*scece ->addItem(item1);
    item1 -> setFocus();
    item1 ->setActive(true);*/

}

void Player::move_event(int phase)
{
// тут проверка

    particle_black->advance(phase);
    particle1_white->advance(phase);
   // if (incl(itt[0]->coordinate_X, itt[0]->coordinate_X + 20, itt[1]->coordinate_X, itt[1]->coordinate_X + 20) && \
     //   incl(itt[0]->coordinate_Y, itt[0]->coordinate_Y + 20, itt[1]->coordinate_Y, itt[1]->coordinate_Y + 20)  ) {


}

template<class T> bool incl(T left1, T right1, T left2, T right2)
{
    if (left1 <= left2) return right1 >= left2;
    else return left1 <= right2;
}

#include "player.h"
#include "dialog.h"
#include "myitem.h"


Player::Player(int x_black, int y_black, int x_white, int y_white)
{
    particle_black = new MyItem(x_black, y_black);
    particle1_white = new MyItem(x_white, y_white);
}

void Player::move_event()
{
// тут проверка
    if (incl(particle_black->coordinate_X, particle_black->coordinate_X + 39, particle1_white->coordinate_X, particle1_white->coordinate_X + 39) && \
        incl(particle_black->coordinate_Y, particle_black->coordinate_Y + 39, particle1_white->coordinate_Y, particle1_white->coordinate_Y + 39)  ) {
      abort();
    }
}

void Player::change_speed(int a, int b)
{
    particle_black->set_speed(a, b);
    particle1_white->set_speed(-a, -b);
}

bool Player::get_speed_zero()
{
    if (particle1_white->get_speed_zero() && particle_black->get_speed_zero() ) {
        return true;
    }
    return false;
}

template<class T> bool incl(T left1, T right1, T left2, T right2)
{
    if (left1 <= left2) return right1 >= left2;
    else return left1 <= right2;
}

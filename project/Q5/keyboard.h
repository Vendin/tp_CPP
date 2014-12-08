#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <QEvent>
#include <QKeyEvent>


class Keyboard
{
public:
    Keyboard();
    bool event(QEvent *event);
};

#endif // KEYBOARD_H

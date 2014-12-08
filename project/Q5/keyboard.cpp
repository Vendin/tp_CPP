#include "keyboard.h"

Keyboard::Keyboard()
{
}

bool Keyboard::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
             QKeyEvent *ke = static_cast<QKeyEvent *>(event);
             if (ke->key() == Qt::Key_W) {

                 return true;
             }
         }
 return false;

}

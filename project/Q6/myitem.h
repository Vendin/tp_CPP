#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <iostream>

namespace Ui {
class Menu;
}

class MyItem : public QGraphicsItem
{
private:
    qreal angle;
    qreal speed_X, speed_Y;
    void DoCollision();
public:
    qreal coordinate_X, coordinate_Y;
    MyItem(int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void set_speed(int x, int y);
    void advance(int phase);
    bool get_speed_zero();
};

#endif // MYITEM_H

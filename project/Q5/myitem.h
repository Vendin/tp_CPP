#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <iostream>
#include <keyboard.h>

class MyItem : public QGraphicsItem
{
private:
    qreal angle;
    qreal speed_X, speed_Y;
    void DoCollision();
protected:

public:
    MyItem(int x, int y);
    QRectF boundingRect() const;
    qreal coordinate_X, coordinate_Y;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void set_speed(int x, int y);
    void advance(int phase);

};

#endif // MYITEM_H

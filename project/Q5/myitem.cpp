#include "myitem.h"
#include "dialog.h"
#include "player.h"
MyItem::MyItem(int x, int y)
{
    //random start rotation
    angle = 180;
    setRotation(angle);
    speed_Y = 0;
    speed_X = 0;
    coordinate_X = x;
    coordinate_Y = y;
    setPos (mapToParent(coordinate_X, coordinate_Y));
}

QRectF MyItem::boundingRect() const
{
    //sizes of particles
    return QRect(0,0,20,20);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush Brush(Qt::gray);
    // basic Collision detection
    if(scene()->collidingItems(this).isEmpty()){
          // no collision
        Brush.setColor(Qt::green);

    } else { // collision
        Brush.setColor(Qt::red);
        DoCollision();
    }
    painter->fillRect(rec,Brush);
    painter->drawRect(rec);
}

void MyItem::set_speed(int X, int Y)
{
    speed_X = X;
    speed_Y = Y;
}

void MyItem::advance(int phase)
{
    if(!phase) return;

    coordinate_X += speed_X;
    coordinate_Y += speed_Y;
    std::cout << coordinate_X << " " << coordinate_Y << std::endl;

    QPointF location = this->pos();
    setPos(mapToParent(speed_X, speed_Y));
}

void MyItem::DoCollision()
{
 // Get a new position
    // see if the new position is in bounds
    QPointF newpoint = mapToParent(-(boundingRect().width()  )   , -(boundingRect().width())  );
    if(!scene()->sceneRect().contains((newpoint))){
    // move it back in bounds
        coordinate_X -= speed_X;
        coordinate_Y -= speed_Y;
        setPos(mapToParent(-speed_X, -speed_Y));
        speed_X = 0;
        speed_Y = 0;
    }
    else
    {
        // set the new position
        coordinate_X -= speed_X;
        coordinate_Y -= speed_Y;
         setPos(mapToParent(-speed_X, -speed_Y));
        speed_X = 0;
        speed_Y = 0;

    }
}


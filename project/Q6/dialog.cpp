#include "dialog.h"
#include "ui_dialog.h"
#include "myitem.h"
#include "player.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Dialog  *Dialog::instan = NULL;

Dialog::Dialog(QWidget *parent) :QDialog(parent), ui(new Ui::Dialog)
{

    ui->setupUi(this);
    scece = new QGraphicsScene(this);
    ui ->graphicsView ->setScene(scece);
    ui ->graphicsView ->setRenderHint(QPainter::Antialiasing);
    scece -> setSceneRect(0,0,610,610);

    QPen mypen = QPen(Qt::black);
    mypen.setWidth(10);
    QLineF TopLine(scece->sceneRect().topLeft(), scece->sceneRect().topRight());
    QLineF LeftLine(scece->sceneRect().topLeft(), scece->sceneRect().bottomLeft());
    QLineF RightLine(scece->sceneRect().topRight(), scece->sceneRect().bottomRight());
    QLineF BottomLine(scece->sceneRect().bottomLeft(), scece->sceneRect().bottomRight());

    scece->addLine(TopLine,mypen);
    scece->addLine(LeftLine,mypen);
    scece->addLine(RightLine,mypen);
    scece->addLine(BottomLine,mypen);

    object = new Player(-324,-605,-325,-44);
    scece ->addItem(object->particle_black);
    object->particle_black -> setFocus();
    object->particle_black ->setActive(true);

    scece ->addItem(object->particle1_white);
    object->particle1_white -> setFocus();
    object->particle1_white ->setActive(true);

    this->barrier_random();

    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),scece,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),object,SLOT(move_event()));

    timer->start(3);
}

Dialog *Dialog::instance()
{
    if(instan == NULL)
    {
        instan = new Dialog;
        return instan;
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::keyPressEvent(QKeyEvent *event)
{
    int speed = 1;
    if ( object->get_speed_zero() )
        switch(event->key())
        {
            case Qt::Key_W:
                object->change_speed(0, speed);
                break;
            case Qt::Key_8:
                object->change_speed(0, speed);
                break;

            case Qt::Key_S:
                object->change_speed(0, -speed);
                break;
            case Qt::Key_5:
                object->change_speed(0, -speed);
                break;

            case Qt::Key_A:
                object->change_speed(speed, 0);
                break;
            case Qt::Key_4:
                object->change_speed(speed, 0);
                break;

            case Qt::Key_D:
                object->change_speed(-speed, 0);
                break;
            case Qt::Key_6:
                object->change_speed(-speed, 0);
                break;
        }
}

void Dialog::barrier_one()
{
    for (int i = 45, j = 0; i < 600; i+=40, j++)
    {
        QRectF object(i, i, 40, 40);
        scece -> addRect(object);
    }

    for (int i = 525, j = 45; i > 40; i-=40, j+=40)
    {
        QRectF object(i, j, 40, 40);
        scece -> addRect(object);
    }
    QRectF object_1(5, 285, 200, 40);
    scece -> addRect(object_1);

    QRectF object_2(405, 285, 200, 40);
    scece -> addRect(object_2);

    QRectF object_3(285, 405, 40, 160);
    scece -> addRect(object_3);

    QRectF object_4(285, 45, 40, 160);
    scece -> addRect(object_4);

}

void Dialog::barrier_two()
{
    QRectF object_1(165, 325, 280, 40);
    scece -> addRect(object_1);

    QRectF object_2(485, 285, 40, 320);
    scece -> addRect(object_2);

    QRectF object_3(325, 285, 40,320);
    scece -> addRect(object_3);

    QRectF object_4(5, 405,240, 40);
    scece -> addRect(object_4);

}

void Dialog::barrier_three()
{
    QRectF object_1(165, 325, 280, 40);
    scece -> addRect(object_1);

    QRectF object_2(485, 285, 40, 320);
    scece -> addRect(object_2);

    QRectF object_3(325, 285, 40,320);
    scece -> addRect(object_3);

    QRectF object_4(5, 405, 240, 40);
    scece -> addRect(object_4);


}

void Dialog::barrier_random()
{
    srand (time(NULL));
    int length, width, j, N = 150;

    for(int i = 45; i < 300; i+=30)
    {
        j = rand() % 600;
        length = rand()%150;
        width = rand()%N;


        QRectF object(j, i, length, width);

        scece -> addRect(object);
    }

}


#include "dialog.h"
#include "ui_dialog.h"
#include "myitem.h"
#include "player.h"

Dialog::Dialog(QWidget *parent) :QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    scece = new QGraphicsScene(this);
    ui ->graphicsView ->setScene(scece);
    ui ->graphicsView ->setRenderHint(QPainter::Antialiasing);
    scece -> setSceneRect(-300,-300,400,400);

    QPen mypen = QPen(Qt::blue);
    mypen.setWidth(3);
    QLineF TopLine(scece->sceneRect().topLeft(), scece->sceneRect().topRight());
    QLineF LeftLine(scece->sceneRect().topLeft(), scece->sceneRect().bottomLeft());
    QLineF RightLine(scece->sceneRect().topRight(), scece->sceneRect().bottomRight());
    QLineF BottomLine(scece->sceneRect().bottomLeft(), scece->sceneRect().bottomRight());

    scece->addLine(TopLine,mypen);
    scece->addLine(LeftLine,mypen);
    scece->addLine(RightLine,mypen);
    scece->addLine(BottomLine,mypen);

    object = new Player(0,0,100,10);
    scece ->addItem(object->particle_black);
    object->particle_black -> setFocus();
    object->particle_black ->setActive(true);

    scece ->addItem(object->particle1_white);
    object->particle1_white -> setFocus();
    object->particle1_white ->setActive(true);
    Player *as = new Player(0,0,100,100);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),scece,SLOT(advance()));

    //connect(timer,SIGNAL(timeout()),scece,SLOT(advance()));
    timer->start(4);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::keyPressEvent(QKeyEvent *event)
{
    int speed = 1;
    switch(event->key())
    {
        case Qt::Key_W:
            object->particle_black->set_speed(0, speed);
            object->particle1_white->set_speed(0, -speed);
            break;
        case Qt::Key_8:
            object->particle_black->set_speed(0, speed);
            object->particle1_white->set_speed(0, -speed);
            break;

        case Qt::Key_S:
            object->particle_black->set_speed(0, -speed);
            object->particle1_white->set_speed(0, speed);
            break;
        case Qt::Key_5:
            object->particle_black->set_speed(0, -speed);
            object->particle1_white->set_speed(0, speed);
            break;

        case Qt::Key_A:
            object->particle_black->set_speed(speed, 0);
            object->particle1_white->set_speed(-speed, 0);
            break;
        case Qt::Key_4:
            object->particle_black->set_speed(speed, 0);
            object->particle1_white->set_speed(-speed, 0);
            break;

        case Qt::Key_D:
            object->particle_black->set_speed(-speed, 0);
            object->particle1_white->set_speed(speed, 0);
            break;
        case Qt::Key_6:
            object->particle_black->set_speed(-speed, 0);
            object->particle1_white->set_speed(speed, 0);
            break;
    }
}


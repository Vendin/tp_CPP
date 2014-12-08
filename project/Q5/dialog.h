#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QRectF>
#include <myitem.h>
#include <iostream>
#include <player.h>
using namespace std;

namespace Ui
{
class Dialog;
}
class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void keyPressEvent(QKeyEvent *);
private:
    Ui::Dialog *ui;
    QGraphicsScene *scece;
    QTimer *timer;
    Player *object;
};

#endif // DIALOG_H

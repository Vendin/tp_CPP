#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <myitem.h>
#include <player.h>

namespace Ui
{
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    static Dialog *instance();
    ~Dialog();
    void keyPressEvent(QKeyEvent *);
    void barrier_one();
    void barrier_two();
    void barrier_three();
    void barrier_random();
protected:
     explicit Dialog(QWidget *parent = 0);
private:
    Ui::Dialog *ui;
    QGraphicsScene *scece;
    Player *object;
    QTimer *timer;
    static Dialog* instan;
};


#endif // DIALOG_H

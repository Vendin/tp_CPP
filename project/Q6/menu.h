#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "dialog.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();
private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::Menu *ui;
};

#endif // MENU_H

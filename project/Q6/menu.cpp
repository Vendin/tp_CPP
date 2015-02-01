#include "menu.h"
#include "ui_menu.h"
#include "dialog.h"


Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_1_clicked()
{
    this->close();


}

void Menu::on_pushButton_2_clicked()
{
    std::abort();
}

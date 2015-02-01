#include "dialog.h"
#include <QApplication>
#include <menu.h>
#include "ui_dialog.h"
 #include <QObject>
#include <QtGui>
#include <dialog.h>
#include <mainwindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

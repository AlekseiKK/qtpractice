#include "mainwindow.h"
#include <QtWidgets>
#include <QDebug>


#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.init_game();
    w.make_button(); // Вызывая здесь кнопка появляется
    w.show();


    return a.exec();
}

#include "mainwindow.h"
#include <QPushButton>
#include <QRandomGenerator>
#include <QWidget>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(1000, 1000);
    connect(m_all_buttons, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
        [=](QAbstractButton *button){ button->deleteLater();});

}

MainWindow::~MainWindow()
{
}

void MainWindow::init_game()
{
    timer_id = startTimer(DELAY);

}

void MainWindow::make_button()
{

    QPushButton* a = new QPushButton(this);
    a->setGeometry(50, 50, qrand() % 900, 50);
    a->setText("+");
    m_all_buttons->addButton(a);
    qDebug() << get_amount_of_numbers();

}

int MainWindow::get_amount_of_numbers()
{
    return (m_all_buttons->buttons()).size();

}

void MainWindow::timerEvent(QTimerEvent *)
{
    make_button(); /* Когда вызываю функцию здесь кнопка не появляется,
                   но добавляется в  m_all_buttons, если вызываю эту функцию в main.cpp , то кнопка появляется*/
}


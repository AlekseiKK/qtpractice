#include "mainwindow.h"
#include <QPushButton>
#include <QRandomGenerator>
#include <QWidget>
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(1000, 1000);
    connect(m_all_buttons, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked), [=](QAbstractButton *button)
    {   score += 1;
        button->deleteLater();
    });
    init_game();

}

MainWindow::~MainWindow()
{
}

void MainWindow::init_game()
{
    for (int i = 0; i < 10; ++i)
    {
        make_button();
    }
    timer_id = startTimer(DELAY);
}

void MainWindow::make_button()
{
    QPushButton* a = new QPushButton(this);
    a->setGeometry(qrand() % 1000, qrand() % 100, 50, 50);
    a->setText("+");
    m_all_buttons->addButton(a);
    a->show();
}

int MainWindow::get_current_amount_of_numbers()
{
    return (m_all_buttons->buttons()).size();
}

void MainWindow::game_over()
{
    QMessageBox message_box;
    message_box.setText("Game Over");
    message_box.exec();


}

void MainWindow::timerEvent(QTimerEvent *)
{
    for (int i = 0; i <= MAX_AMOUNT_OF_BUTTONS - get_current_amount_of_numbers(); ++i)
    {
      make_button();
    }
    for(QAbstractButton* button: m_all_buttons->buttons())
    {
        button->move(button->x(), button->y() + Y_STEP);
        if (button->y() > HEIGHT / 2){
            QColor color = QColor(255, 0, 0);
            QString style = QString("background-color: %1").arg(color.name());
            button->setStyleSheet(style);
        }
        if (button->y() > HEIGHT - button->height())
        {
            game_over();
        }
    }


    qDebug() << score;
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QButtonGroup>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init_game();
    void make_button();
    int get_current_amount_of_numbers();
    void game_over();
protected:
    void timerEvent(QTimerEvent*) override;
private:
    const int MAX_AMOUNT_OF_BUTTONS = 10;
    const int Y_STEP = 10;
    const int WIDTH = 1000;
    const int HEIGHT = 1000;
    const int DELAY = 100;
    int score = 0;
    int timer_id;
    QButtonGroup* m_all_buttons = new QButtonGroup(this);
};
#endif // MAINWINDOW_H

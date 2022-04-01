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
    int get_amount_of_numbers();
protected:
    void timerEvent(QTimerEvent*) override;
private:
    static const int DELAY = 2000;
    int timer_id;
    QButtonGroup* m_all_buttons = new QButtonGroup(this);
};
#endif // MAINWINDOW_H

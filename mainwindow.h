#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QEventLoop>
#include <QTimer>
#include "about.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void setScores();
    void setPlayer();
    void setBomb();
    void setWD();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *btn_setScores;
    QPushButton *btn_setPlayer;
    QPushButton *btn_setBomb;
    QPushButton *btn_setWD;
    QPushButton *btn_about;
    QLineEdit *text_scores;
    QLineEdit *text_player;
    QLineEdit *text_bomb;
    About *about;
};

#endif // MAINWINDOW_H

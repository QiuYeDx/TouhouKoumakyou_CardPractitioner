#ifndef ABOUT_H
#define ABOUT_H

#include <QMainWindow>
#include <QLabel>
namespace Ui {
class About;
}

class About : public QMainWindow
{
    Q_OBJECT
public slots:
    void about();
public:
    explicit About(QWidget *parent = nullptr);
    ~About();

private:
    Ui::About *ui;
    QLabel *label_about;
    QLabel *label_me;
    QLabel *label_blog;
    QLabel *label_github;
};

#endif // ABOUT_H

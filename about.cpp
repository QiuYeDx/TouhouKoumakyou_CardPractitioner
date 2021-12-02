#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    this->setWindowTitle("关于~☆");
    this->setFixedSize(400, 200);
    this->setWindowIcon(QIcon(":/img/src/img.jpg"));
    QFont font ("Microsoft YaHei", 10, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    label_about = new QLabel(this);
    label_about->setText("以此献给在2021年仍然对东方不离不弃的车万人。");
    label_about->setGeometry(40, 25, 360, 30);
    label_about->setFont(font);

    label_me = new QLabel(this);
    label_me->setText("制作者:QiuYeDx   ただの1人 普通985本科生。");
    label_me->setGeometry(40, 65, 360, 30);
    label_me->setFont(font);

    label_blog = new QLabel(this);
    label_blog->setText("私のBlog: <style> a {text-decoration: none;color: red} </style><a href='https://qiuyedx.com'>秋夜Dx の ブログ</a>");
    label_blog->setGeometry(40, 105, 360, 30);
    label_blog->setFont(font);

    label_github = new QLabel(this);
    label_github->setText("项目已开源:<style> a {text-decoration: none;color: red} </style><a href='https://github.com/QiuYeDx/TouhouKoumakyou_CardPractitioner'>TouhouKoumakyou_CardPractitioner</a>");
    label_github->setGeometry(40, 145, 360, 30);
    label_github->setFont(font);
}

About::~About()
{
    delete ui;
}

void About::about(){
    this->show();
}

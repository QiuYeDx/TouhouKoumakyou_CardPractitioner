#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Windows.h"
int flag_wd = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("红魔乡v1.02符卡练习器~☆");
    this->setFixedSize(400, 190);
    this->setWindowIcon(QIcon(":/img/src/img.jpg"));
    about = new About;

    text_scores = new QLineEdit(this);
    text_scores->setGeometry(40, 20, 120, 30);
    text_scores->setText("0");

    text_player = new QLineEdit(this);
    text_player->setGeometry(40, 60, 120, 30);
    text_player->setText("3");

    text_bomb = new QLineEdit(this);
    text_bomb->setGeometry(40, 100, 120, 30);
    text_bomb->setText("3");

    btn_setScores = new QPushButton("设置得分", this);
    btn_setScores->setGeometry(240, 20, 100, 30);
    QObject::connect(btn_setScores, SIGNAL(clicked()), this, SLOT(setScores()));

    btn_setPlayer = new QPushButton("设置Player", this);
    btn_setPlayer->setGeometry(240, 60, 100, 30);
    QObject::connect(btn_setPlayer, SIGNAL(clicked()), this, SLOT(setPlayer()));

    btn_setBomb = new QPushButton("设置Bomb", this);
    btn_setBomb->setGeometry(240, 100, 100, 30);
    QObject::connect(btn_setBomb, SIGNAL(clicked()), this, SLOT(setBomb()));

    btn_setWD = new QPushButton("开启无敌", this);
    btn_setWD->setGeometry(240, 140, 100, 30);
    QObject::connect(btn_setWD, SIGNAL(clicked()), this, SLOT(setWD()));

    btn_about = new QPushButton("关于", this);
    btn_about->setGeometry(40, 140, 120, 30);
    QObject::connect(btn_about, SIGNAL(clicked()), about, SLOT(about()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setScores(){
    if(!text_scores->text().isEmpty()){
        wchar_t wName[] = L"東方紅魔郷     the Embodiment of Scarlet Devil";
        HWND h = ::FindWindow(NULL, wName);
        DWORD processid;
        GetWindowThreadProcessId(h, &processid);
        HANDLE hprocess;
        hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processid);

        if(hprocess == 0){
            printf("failed!");
            return;
        }else{
            printf("succeeded!");

            DWORD scores = text_scores->text().toInt();
            DWORD addr = 0x0069BCA0;

            DWORD res = WriteProcessMemory(hprocess, (LPVOID)addr, &scores, 4, 0);
            return;
        }
    }else{
        text_scores->setText("不能为空哟www");
    }
}

void MainWindow::setPlayer(){
    if(!text_player->text().isEmpty()){
        wchar_t wName[] = L"東方紅魔郷     the Embodiment of Scarlet Devil";
        HWND h = ::FindWindow(NULL, wName);
        DWORD processid;
        GetWindowThreadProcessId(h, &processid);
        HANDLE hprocess;
        hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processid);

        if(hprocess == 0){
            printf("failed!");
            return;
        }else{
            printf("succeeded!");

            DWORD player = text_player->text().toInt();
            DWORD addr = 0x00428A38;
            DWORD addr2;
            int flag = ReadProcessMemory(hprocess, (LPVOID)addr, &addr2, 4, 0);
            if(flag)
                DWORD res = WriteProcessMemory(hprocess, (LPVOID)(addr2 + 1), &player, 4, 0);
            return;
        }
    }else{
        text_player->setText("不能为空哟www");
    }
}

void MainWindow::setBomb(){
    if(!text_bomb->text().isEmpty()){
        wchar_t wName[] = L"東方紅魔郷     the Embodiment of Scarlet Devil";
        HWND h = ::FindWindow(NULL, wName);
        DWORD processid;
        GetWindowThreadProcessId(h, &processid);
        HANDLE hprocess;
        hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processid);

        if(hprocess == 0){
            printf("failed!");
            return;
        }else{
            printf("succeeded!");

            DWORD bomb = text_bomb->text().toInt();
            DWORD addr = 0x00428A38;
            DWORD addr2;
            int flag = ReadProcessMemory(hprocess, (LPVOID)addr, &addr2, 4, 0);
            if(flag)
                DWORD res = WriteProcessMemory(hprocess, (LPVOID)(addr2 + 2), &bomb, 4, 0);
            return;
        }
    }else{
        text_bomb->setText("不能为空哟www");
    }
}

void MainWindow::setWD(){
    wchar_t wName[] = L"東方紅魔郷     the Embodiment of Scarlet Devil";
    HWND h = ::FindWindow(NULL, wName);
    DWORD processid;
    GetWindowThreadProcessId(h, &processid);
    HANDLE hprocess;
    hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processid);

    if(hprocess == 0){
        printf("failed!");
        return;
    }else{
        printf("succeeded!");

        flag_wd = btn_setWD->text().compare("开启无敌")==0?(btn_setWD->setText("关闭无敌"),3):(btn_setWD->setText("开启无敌"),0);
        while(flag_wd){
            DWORD wd = 3;
            DWORD addr = 0x0040B218;
            DWORD addr2;
            ReadProcessMemory(hprocess, (LPVOID)addr, &addr2, 4, 0);
            DWORD res = WriteProcessMemory(hprocess, (LPVOID)(addr2 + 0x000009E0), &wd, 4, 0);
            QEventLoop loop;
            QTimer::singleShot(100, &loop, SLOT(quit()));
            loop.exec();
        }
    }
}


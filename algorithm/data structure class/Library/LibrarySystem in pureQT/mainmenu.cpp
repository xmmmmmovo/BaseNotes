#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QPainter> // 绘制类
#include <QDebug> // 测试用

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    init();
}

MainMenu::~MainMenu()
{
    delete ui;
}

// 重载绘制函数 绘制背景
void MainMenu::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/src/bk.png"));
}

void MainMenu::init(){
}

void MainMenu::dealLogin(QString usna){
    userName = usna;
    qDebug() << userName;
    this->show();
}

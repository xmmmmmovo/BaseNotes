#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QPainter> // 绘制类
#include <QDebug> // 测试用
#include <QTreeView> // treeView
#include <QTextBrowser> // 书本信息头文件
/**
  主窗口
*/
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

/**
  重载绘制函数 绘制背景
*/
void MainMenu::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/src/bk.png"));
}

void MainMenu::init(){
}

/**
  处理登录事件的槽函数
*/
void MainMenu::dealLogin(QString usna){
    userName = usna;
    qDebug() << userName;
    this->show();
}

/**
  按下 打开文件 按钮反馈
*/
void MainMenu::on_openBookLib_triggered()
{

}

/**
  按下 添加书籍 按钮反馈
*/
void MainMenu::on_addBook_triggered()
{

}

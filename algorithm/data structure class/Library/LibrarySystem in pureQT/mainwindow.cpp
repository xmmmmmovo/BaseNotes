#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lableclick.h"
#include <QPainter> // 绘制类
#include <QMessageBox> // 对话框头文件
#include <QString> // std::string的超集
#include <QDebug> // 调试用

#include "Hash.h"

/**
  主窗口（登录窗口）
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    init();
    initHashTable();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::init(){
    loginLable = ui->loginLable;
    quitLable = ui->quitLable;
    connect(loginLable, &LableClick::clicked, this, &MainWindow::loginPush); // 绑定
    connect(quitLable, &LableClick::clicked, this, &MainWindow::quitPush); // 绑定槽函数
    connect(this, &MainWindow::loginSuccessful, &menu, &MainMenu::dealLogin);

    userName = "123";
    userPassword = "123";
}

/**
  重载绘制函数 绘制背景
*/
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/src/loginbk.png"));
}

/**
  按下登录按钮
*/
void MainWindow::loginPush(){
//    qDebug() << "按到了！";
    if (ui->usernameLineEdit->text() == userName
            && ui->userpasswordLineEdit->text() == userPassword) {
        emit loginSuccessful(ui->usernameLineEdit->text()); // 登陆成功信号发送
        this->close();
    } else {
        QMessageBox::critical(this, "登陆失败！", "登陆失败！\n请检查用户名或密码是否正确！");
    }
}

/**
  按下退出按钮
*/
void MainWindow::quitPush(){
    this->close();
}

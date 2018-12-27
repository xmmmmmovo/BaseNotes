#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "lableclick.h"
#include "mainmenu.h"
#include <QMainWindow>
#include <QString>
/**
  主窗口（登录窗口）
*/
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void loginSuccessful(QString); // 登陆成功的信号

private:
    // ui方面的变量
    Ui::MainWindow *ui;
    MainMenu menu;
    LableClick *loginLable; // 登录按钮
    LableClick *quitLable; // 退出按钮

    // 内部变量
    QString userName; // 用户名
    QString userPassword; // 密码

    // 私有函数
    void paintEvent(QPaintEvent *event); // 添加背景
    void init(); // 初始化
    void loginPush(); // 按下登录按钮
    void quitPush(); // 按下推出按钮
};

#endif // MAINWINDOW_H

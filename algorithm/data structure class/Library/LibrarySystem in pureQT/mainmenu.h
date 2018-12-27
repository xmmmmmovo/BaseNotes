#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QString>
#include <QTreeView>
#include <QTextBrowser>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();
    void dealLogin(QString); // 处理登录信息

private:
    Ui::MainMenu *ui;
    QString userName;
    QTextBrowser *bookInfo;
    QTreeView *bookTree;

    void init();
    void paintEvent(QPaintEvent *); // 添加背景
};

#endif // MAINMENU_H

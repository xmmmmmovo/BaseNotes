#include "mainwindow.h"
//菜单头文件
#include <QMenuBar>
#include <QMenu>
//行为头文件
#include <QAction>

#include <QDebug>
#include <QPushButton>
//工具栏头文件
#include <QToolBar>
//状态栏头文件
#include <QStatusBar>
//标签头文件
#include <QLabel>
//文本编辑头文件
#include <QTextEdit>
//浮动窗口头文件
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //菜单栏
    QMenuBar *mBar = menuBar();
    //添加菜单
    QMenu *pFile = mBar->addMenu("文件");
    //添加菜单项，添加动作
    QAction *pNew = pFile->addAction("新建");
    connect(pNew, &QAction::triggered,
            [=](){
        qDebug() <<"按键被按下";
    });
    pFile->addSeparator();//添加分割线
    QAction *pOpen = pFile->addAction("打开");

    //工具栏，菜单的快捷方式
    QToolBar *toolBar = addToolBar("toolbar");
    //工具栏添加快捷键
    toolBar->addAction(pNew);

    QPushButton *b = new QPushButton(this);
    b->setText("按钮");
    //添加小控件
    toolBar->addWidget(b);
    connect(b, &QPushButton::clicked,
            [=](){
       b->setText("123");
    });

    //状态栏
    QStatusBar *sBar = statusBar();
    QLabel *lable = new QLabel(this);
    lable->setText("normal text file");
    sBar->addWidget(lable);
    //继续添加则是从右向左添加
    //下面指令是从右向左添加
    sBar->addPermanentWidget(new QLabel("右", this));

    //核心控件
    QTextEdit *textEdit = new QTextEdit(this);
    //设定中心控件
    setCentralWidget(textEdit);

    //浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    //浮动窗口添加控件
    QTextEdit *dockTextEdit = new QTextEdit(this);
    dock->setWidget(dockTextEdit);
}

MainWindow::~MainWindow()
{

}

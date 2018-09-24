#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
//对话框头文件
#include <QDialog>
//标准对话框头文件
#include <QMessageBox>
//文件对话框
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("对话框");

    QAction *p1 = menu->addAction("模态对话框");
    connect(p1, &QAction::triggered,
            [=](){
        QDialog dlg;
        dlg.exec();
        qDebug() << "结束";
    });

    QAction *p2 = menu->addAction("非模态对话框");
    connect(p2, &QAction::triggered,
            [=](){
        //方法一：在类中写
        //dlg.show();
        //qDebug() << "结束";

        //方法二
        //会多次分配空间 浪费内存
        //QDialog *p = new QDialog(this);
        //p->show();

        //方法三
        //比较灵活
        QDialog *p = new QDialog;//不指定父对象
        p->setAttribute(Qt::WA_DeleteOnClose);
        p->show();
    });

    QAction *p3 = menu->addAction("关于对话框");
    connect(p3, &QAction::triggered,
            [=](){
        QMessageBox::about(this, "about", "关于qt");
    });

    QAction *p4 = menu->addAction("问题对话框");
    connect(p4, &QAction::triggered,
            [=](){
        int ret = QMessageBox::question(this, "question", "Are you OK?");

        switch (ret) {
        case QMessageBox::Yes:

            break;

        case QMessageBox::No:
            break;

        default:
            break;
        }
    });

    QAction *p5 = menu->addAction("文件对话框");
    connect(p5, &QAction::triggered,
            [=](){
        QString path = QFileDialog::getOpenFileName(this, "open", "../",
                                                    "Text(*.txt);;all(*.*)");
    });

    QAction *p6 = menu->addAction("错误对话框");
    connect(p6, &QAction::triggered,
            [=](){
        QMessageBox::critical(this, "error", "错误");
    });

}

MainWindow::~MainWindow()
{

}

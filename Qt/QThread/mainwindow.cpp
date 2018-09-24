#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //分配空间
    thread = new MyThread(this);
    connect(thread, &MyThread::isDone, this, &MainWindow::dealDone);
    connect(this, &MainWindow::destroyed, this, &MainWindow::stopThread);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startThread_clicked()
{
    //启动线程
    thread->start();

}

void MainWindow::dealDone(){
    qDebug() << "结束";
}

void MainWindow::stopThread(){
    qDebug() << "关闭线程";
    //关闭线程
    thread->quit();
    //等待线程 防止线程阻塞
    thread->wait();
}

void MainWindow::on_startButton_clicked()
{

}

void MainWindow::on_stopButton_clicked()
{

}

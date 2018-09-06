#include "mainwindow.h"
#include "ui_mainwindow.h"
//补全器
#include <QCompleter>
#include <QStringList>
//动画
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);//加载UI

    ui->myButton->setText("123");
    QString str = ui->lineEdit->text();

    //ui->lineEdit->setTextMargins();
    //显示模式
    //ui->lineEdit->setEchoMode();

    QStringList list;
    list << "11" << "22";//类似cin
    QCompleter *com = new QCompleter(list, this);
    com->setCaseSensitivity(Qt::CaseInsensitive);

    ui->lineEdit->setCompleter(com);

    ui->url->setOpenExternalLinks(true);//是否跳转网址

}

MainWindow::~MainWindow()
{
    delete ui;
}

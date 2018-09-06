#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
//表格模型
#include <QSqlTableModel>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Qt支持的数据库驱动
    qDebug() << QSqlDatabase::drivers();

    //添加数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
    db.setDatabaseName("./info.db");

    if(!db.open()){
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }

    //QSqlQuery query;
    //query.exec("create table student(id int, name varchar(255), age int, score int);");

    //设置模型
    model = new QSqlTableModel(this);
    model->setTable("student");//指定使用哪个表
    //关联
    ui->tableView->setModel(model);
    //显示
    model->select();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 获得表的行数
    int rowNum = model->rowCount();
    // 添加一行
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),rowNum);
}

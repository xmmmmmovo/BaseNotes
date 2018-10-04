#include "widget.h"
#include <QDebug>
#include <QDataStream>
#include <QTextStream>
#include <QFile>
//内存文件
#include <QBuffer>
//文件+行号
#define cout qDebug() << "[" << __FILE__ << ":" << "]"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QBuffer memFile;
    memFile.open(QIODevice::WriteOnly);

    memFile.write("11111111111\n");
    memFile.write("222222222");

    memFile.close();

    cout << memFile.buffer();
}

Widget::~Widget()
{

}

void Widget::writeData(){
    QFile file("../test1.txt");
    bool isOpen = file.open(QIODevice::WriteOnly);
    if(isOpen){
        //创建数据流 与file文件关联
        QDataStream stream(&file);
        stream << QString("test") << 250;
        file.close();
    }
}

void Widget::readData(){
    QFile file("../test1.txt");
    bool isOpen = file.open(QIODevice::ReadOnly);
    if(isOpen){
        //创建数据流 与file文件关联
        QDataStream stream(&file);
        //按照写的顺序读数据
        QString str;
        int a;
        stream >> str >> a;
        file.close();
    }
}

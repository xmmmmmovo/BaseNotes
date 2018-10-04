#include "mybutton.h"
#include <QDebug>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

    //指定父对象后直接或间接继承于QObject
    //子对象如果是动态分配空间的new，不需手动释放delete
    //系统会自动释放
}
MyButton::~MyButton(){
    qDebug() << "被析构";
}

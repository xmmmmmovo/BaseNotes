#include "mainwidget.h"
#include <QPushButton>
#include <QDebug>//打印

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    //构造函数：构造一次窗口便会调用一次

    b1.setParent(this);
    b1.setText("close");
    b1.move(100, 100);

    b2 = new QPushButton(this);
    b2->show();

    connect(&b1, &QPushButton::pressed, this, &MainWidget::close);
    /*
     * &b1: 信号发出者
     * &QPushButton::pressed：处理的信号
     *      &发送者类名::信号名字
     * this：信号接受者 //this代指当前窗口
     * &MainWidget::close：槽函数，信号处理函数
     *      &接收的类名::槽函数名字
    */

    /*
     * 自定义槽，普通函数的用法
     * QT5：任意的成员函数，普通全局函数，静态函数
     * 槽函数余姚与信号一致（参数，返回值）
     * 由于信号都是没有返回值，所以，槽函数一定没有返回值
    */
    connect(b2, &QPushButton::released, this, &MainWidget::mySlot);
    connect(b2, &QPushButton::released, &b1, &MainWidget::hide);

    /*
     * 信号：短信
     * 槽函数：接收短信的手机
    */

    setWindowTitle("boss");
    //下面代码同上
    //this->setWindowTitle("boss");

    b3.setParent(this);
    b3.setText("切换窗口");
    b3.move(50, 50);

    //w.show();

    connect(&b3, &QPushButton::released, this, &MainWidget::changeWin);

    /*
     * 出现二义性问题
     * 利用函数指针便可解决
     * 不容易出问题但比较麻烦
    */
    void (SubWidget::*funSignal)() = &SubWidget::mySignal;
    connect(&w, funSignal, this, &MainWidget::dealSingal);

    void (SubWidget::*numSignal)(int, QString) = &SubWidget::mySignal;
    connect(&w, numSignal, this, &MainWidget::dealSlot);

    /*
     * QT4中的信号连接
     * 解决方案比较容易执行
     * 但也有局限性,并且容易出错
     * QT4槽函数必须要有slots关键字(见头文件)
    */
    //connect(&w, SIGNAL(mySignal()), this, SLOT(dealSingal()));
    //connect(&w, SIGNAL(mySignal(int,QString)), this, SLOT(dealSlot(int,QString)));
    //SIGNAL SLOT 将函数名字 -> 字符串 不进行语法错误检查

    /*
     * lambda表达式,匿名函数对象
     * C++11新特性, 项目文件: CONFIG += C++11
     * QT配合信号使用 非常方便
    */
    QPushButton *b5 = new QPushButton(this);
//    b5->setText("lambda表达式");
//    b5->move(150, 150);
//    connect(b5, &QPushButton::clicked,
//            //= :把外部局部变量，类中所有成员以值传递
//            //this :类中所有成员以值的传递方式
//            //& : 把外部所有局部变量，引用的方式传递
//            //同java 内部类变量只读
//            [=](bool isCheck){
//        b5->setText("变化");
//        qDebug() << isCheck;
//    });

    resize(400, 400);
}

void MainWidget::mySlot(){
    b2->setText("hello Qt");
}

void MainWidget::changeWin(){
    w.show();
    this->hide();
}

void MainWidget::dealSingal(){
    w.hide();
    this->show();
}

void MainWidget::dealSlot(int a, QString str){
    qDebug() << a << str.toUtf8().data();//中文显示
}

MainWidget::~MainWidget()
{

}

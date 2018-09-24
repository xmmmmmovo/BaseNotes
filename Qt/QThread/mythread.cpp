#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run(){
    //复杂数据处理
    msleep(10);//毫秒
    usleep(10);//微秒
    sleep(5);//秒

    emit isDone();
}

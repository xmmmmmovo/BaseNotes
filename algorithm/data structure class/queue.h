/**
 * 循环队列类
 * 2018-09-24 author:xmmmmmovo
*/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cmath>

using namespace std;

template <class T>
class Queue{
public:
    Queue();
    ~Queue();
    bool empty();
    int size();
    void display();//显示队列里所有的节点
    T* front();//头元素
    T* back();//尾元素
    /*
    * 先进为前 后进为后
    * FIFO 最后进的后面插入数据
    */
    void push_back(T);//后插
    void pop_front();//前取

private:
    T* queueList;
    T* finalListPoint;
    //基准点 此点只存放地址 实际所指向变量无实值
    T* benchMarkPoint;
    int maxSize = 100;
    int nowSize = 0;
};

//构造函数
template <class T>
Queue<T>::Queue(){
    queueList = new T[maxSize];//为队列分配空间
    benchMarkPoint = finalListPoint = queueList + maxSize - 1;//选取最后点为基准点
}

//析构函数
template <class T>
Queue<T>::~Queue(){
    delete[] queueList;//释放内存 防止内存泄漏
}

template <class T>
bool Queue<T>::empty(){
    if (nowSize)
    {
        return false;
    }else{
        return true;
    }
}

template <class T>
int Queue<T>::size(){
    return nowSize;
}

template <class T>
void Queue<T>::display(){
    for(T* i = queueList;i != benchMarkPoint; i++)
    {
        if(i ==  finalListPoint){

        }
    }
}

template <class T>
T* Queue<T>::front(){

}
template <class T>
T* Queue<T>::back(){

}

template <class T>
void Queue<T>::push_back(T element){

}

template <class T>
void Queue<T>::pop_front(){

}

#endif // QUEUE_H
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cmath>

#define Rank int
using namespace std;

template <class T>
class Stack{
    public:
        Stack();
        bool empty(); //测试堆栈是否为空〄1�7
        T pop(); //移除堆栈顶部的对象，并作为此函数的��返回该对象〄1�7
        T push(T);//把项压入堆栈顶部〄1�7
        int size();//长度返回
        T top();//返回栈顶元素
    
    private:
        T *stack;
        Rank nowSize = -1;//存放数��长庄1�7/末尾元素的位罄1�7
        Rank maxSize = 16;//总长庄1�7

        void checkIfOut();
        void increaseList();
};

template <class T>
Stack<T>::Stack(){
    stack = new T[maxSize];
}

template <class T>
bool Stack<T>::empty(){
    return (nowSize == -1)?true:false;
}

template <class T>
T Stack<T>::pop(){
    if (empty())
    {
        cout << "Stack is empty !";
        return -1;
    }else{
        nowSize--;
        return stack[nowSize + 1];
    }
}

template <class T>
T Stack<T>::push(T element){
    nowSize++;
    checkIfOut();
    stack[nowSize] = element;
    return size();//返回现在栈的大小
}

template <class T>
int Stack<T>::size(){
    return nowSize + 1;
}

template <class T>
T Stack<T>::top(){
    return stack[nowSize];
}

template <class T>
void Stack<T>::checkIfOut(){
    if (nowSize + 1 > maxSize)
    {
        increaseList();
    }
}

template <class T>
void Stack<T>::increaseList(){
    T* oldList = stack;
    stack = new T[maxSize <<= 1];//左移丢�佄1�7 容量加��1�7
    for(int i = 0;i < nowSize - 1;i++)
    {
        stack[i] = oldList[i];
    }
    delete []oldList;//释放空间 防止内存泄漏
}

#endif // STACK_H
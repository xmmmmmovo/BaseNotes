#include "vector.h"
#include <iostream>
#include <cmath>

using namespace std;

template <class T>
Vector<T>::Vector(){
    sequenceList = new T[maxSize];//分配空间
}

template <class T>
Rank Vector<T>::size(){
    return nowSize;
}

template <class T>
T Vector<T>::get(Rank pos){
    return sequenceList[pos];
}

template <class T>
void Vector<T>::put(Rank pos, T num){
    if (pos > nowSize)
    {
        cout << "越界警告！";
    }else
    {
        sequenceList[pos - 1] = num;
    }
}

template <class T>
void Vector<T>::insert(Rank pos, T num){
    if (pos > nowSize)
    {
        cout << "越界警告！";

    }else{
        checkIfOut();
        moveBack(pos);
        sequenceList[pos] = num;
        nowSize++;
    }
}

template <class T>
void Vector<T>::append(T num){
    checkIfOut();
    nowSize++;
    
    sequenceListp[nowSize] = num;
}

template <class T>
void Vector<T>::remove(Rank pos){
    if (pos > nowSize)
    {
        cout << "越界警告！";
    }else
    {
        moveForward(pos);
        nowSize--;
    }
}

template <class T>
bool Vector<T>::disordered(){
    for(i = 0;i < nowSize-1; i++)
    {
        if (sequenceList[i] > sequenceList[i+1])
        {
            return false;
        }
    }

    return true;
}

template <class T>
void Vector<T>::sort(){

}

template <class T>
void Vector<T>::show(Rank pos){
    if (pos > size)
    {
        cout << "越界警告！";
    }else
    {
        cout << sequenceList[pos - 1];
    }
}

template <class T>
void Vector<T>::showAll(){
    for(i = 0;i < nowSize;i++)
    {
        cout << sequenceList[i] << " ";   
    }
}

template <class T>
void Vector<T>::moveForward(Rank pos){
    for(i = pos;i < nowSize; i++)
    {
        sequenceList[pos-1] = sequenceList[pos];
    }
}

template <class T>
void Vector<T>::moveBack(Rank pos){
    for(i = nowSize;i > pos; i--)
    {
        sequenceList[i] = sequenceList[i-1];
    }
}

template <class T>
void Vector<T>::checkIfOut(){
    if (nowSize + 1 > maxSize)
    {
        increaseList();
    }
}

template <class T>
void Vector<T>::increaseList(){
    T* oldList = sequenceList;
    sequenceList = new T[maxSize <<= 1];//左移一位 容量加倍
    for(i = 0;i < nowSize - 1;i++)
    {
        sequenceList[i] = oldList[i];
    }
    delete []oldList;//释放空间 防止内存泄漏
}

template <class T>
void Vector<T>::swap(T *a, T *b){
    
}
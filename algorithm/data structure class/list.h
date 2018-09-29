/**
 * 双向链表类
 * 2018-9-24 author:xmmmmmovo
*/
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cmath>

using namespace std;

template <class T>
class List
{
public:
    List();
    ~List();
    void begin();//迭代器返回头结点
    void end();//迭代器返回尾节点
    void rbegin();//反向链表迭代器返回尾节点
    void rend();//头结点
    T iterator();//迭代器数据接口

private:
    typedef struct nodeList{
        nodeList *pred;//前驱
        nodeList *succ;//后继
        T data;
    } node;

    node *iterator = header;//迭代器 所有外部访问皆在此处
    node *header;//头结点
    node *trailer;//尾结点
};

//构造双向链表
template <class T>
List<T>::List()
{
    header = new node();
    trailer = new node();

    header->pred = NULL;
    header->succ = trailer;
    trailer->pred = header;
    trailer->succ = NULL;
}

//同理 释放内存 防止内存泄漏
template <class T>
List<T>::~List()
{
    node testNode = *header;
    node *nodeAddress = &testNode;

    while(nodeAddress->succ){
        nodeAddress = nodeAddress->succ;
        delete nodeAddress->pred;
    }
    delete nodeAddress;
    delete *testNode;
}

template <class T>
void List<T>::begin(){
    iterator = this->header;
}

#endif // LIST_H
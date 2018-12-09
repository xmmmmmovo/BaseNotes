/**
 * 单向链表类
 * 已用继承重写
*/
#ifndef UNDIRECTIONALLINKEDLIST_H
#define UNDIRECTIONALLINKEDLIST_H

#include "singer.h"
#include <iostream>
#include <cmath>

using namespace std;

class List: public Singer
{
public:
    List();
    ~List();
    void begin();//迭代器返回头结点
    void end();//迭代器返回尾节点
    bool next(); // 后移迭代器
    Singer nowNodeData(); // 获取迭代器data
    Singer nextNodeData(); // 获取下一迭代器data
    Singer beforeNodeData(); // 获取上一个的节点
    Singer getPosition(int); // 获取某节点数值
    void swapWithBefore();
    int getLength(); // 返回长度
    void insertInFort(Singer);//头结点后插入
    void insertInBack(Singer);//尾节点插入

private:    
    typedef struct nodeList{
        Singer data;
        nodeList *succ = NULL;
    } node;
    node *iterator;//迭代器 每次插入后迭代器指针指向插入位置
    node *beforeIterator;
    node *header;//头结点
    node *trailer;//尾结点
    int count = 0;

    void printError();
};

//构造单向链表
List::List()
{
    header = new node();
    trailer = header;
    iterator = header;
    beforeIterator = NULL;
}

//同理 释放内存 防止内存泄漏
List::~List()
{
    node *temp;
    while(header->succ){
        temp = header;
        header = header->succ;
        delete temp;
    }
    delete header;
}

void List::begin(){
    iterator = header;
    beforeIterator = NULL;
}

void List::end(){
    iterator = trailer;
    beforeIterator = NULL; // 尾部也先判断成null
}

bool List::next(){
    beforeIterator = iterator;
    iterator = iterator->succ;
    return iterator ? true:false;
}

Singer List::nowNodeData(){
    return iterator->data;
}

Singer List::nextNodeData(){
    return iterator->succ->data;
}

Singer List::beforeNodeData(){
    return beforeIterator->data;
}

Singer List::getPosition(int pos){
    int length = 0;
    if(pos > count){ // 判断是否越界
        printError(); // 可能出现野指针问题 暂不知道解决方案
    }else{
        begin();
        iterator = iterator->succ;
        while(iterator){
            if(length == pos)
                return iterator->data;
            iterator = iterator->succ;
            length ++;
        }
    }
}

void List::swapWithBefore(){
    Singer temp;
    temp = iterator->data;
    iterator->data = beforeIterator->data;
    beforeIterator->data = temp;
}

int List::getLength(){
    return count;
}

void List::insertInFort(Singer data){
    node *insertNode = new node();
    insertNode->data = data;
    insertNode->succ = header->succ;

    header->succ = insertNode;
    iterator = insertNode;
    count++;
}

void List::insertInBack(Singer data){
    node *insertNode = new node();
    insertNode->data = data;

    trailer->succ = insertNode;
    trailer = insertNode;
    iterator = insertNode;
    count++;
}

void List::printError(){
    cout << "can'Singer find num or point\n";
}

#endif // UNDIRECTIONALLINKEDLIST_H
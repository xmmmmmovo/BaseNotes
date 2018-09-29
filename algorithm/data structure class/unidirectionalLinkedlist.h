/**
 * 单向链表类
 * 2018-9-28 author:xmmmmmovo
*/
#ifndef UNDIRECTIONALLINKEDLIST_H
#define UNDIRECTIONALLINKEDLIST_H

#include <iostream>
#include <cmath>

using namespace std;

template <class T>
class List
{
public:
    typedef struct nodeList{
        T data;
        nodeList *succ = NULL;//后继 如果定义成private会造成析构函数无法运行
    } node;

    List();
    ~List();
    void begin();//迭代器返回头结点
    void end();//迭代器返回尾节点
    void insertInFort(T);//头结点后插入
    void insertInBack(T);//尾节点插入
    void insert(T);//直接在迭代器后方插入
    void insert(T, T);//某个数值后插入
    void insert(node *, T);//某个具体点后面的数值
    void insertPointByPos(int, T);//插入某个位置节点 因函数重载原因改名
    void deletePoint();//删除迭代器所在节点
    void deletePoint(T);//删除某个数值节点 因重名原因改名
    void deletePointByPos(int);//删除某个位置节点 同插入原因改名
    void printAll();
    node* getIterator();//迭代器数据接口

    //课后习题
    bool disordered();//判断是否有序
    void backInsert(T);//前插
    void traserve();//将单链表转置

private:
    node *iterator;//迭代器 每次插入后迭代器指针指向插入位置
    node *header;//头结点
    node *trailer;//尾结点

    void insertPoint(node *, T);//将节点后插入操作抽象成函数
};

//构造单向链表
template <class T>
List<T>::List()
{
    header = new node();
    trailer = header;
    iterator = header;
}

//同理 释放内存 防止内存泄漏
template <class T>
List<T>::~List()
{
    node *temp;
    while(header->succ){
        temp = header;
        header = header->succ;
        delete temp;
    }
    delete header;
}

template <class T>
void List<T>::begin(){
    iterator = header;
}

template <class T>
void List<T>::end(){
    iterator = trailer;
}

template <class T>
void List<T>::insertInFort(T data){
    node *insertNode = new node();
    insertNode->data = data;
    insertNode->succ = header->succ;

    header->succ = insertNode;
}

template <class T>
void List<T>::insertInBack(T data){
    node *insertNode = new node();
    insertNode->data = data;

    trailer->succ = insertNode;
    trailer = insertNode;
}

template <class T>
void List<T>::insert(T data){
    insertPoint(iterator, data);
}

template <class T>
void List<T>::insert(T needNum, T data){
    node *tempNode = header;
    while(tempNode->succ){
        tempNode = tempNode->succ;
        if(tempNode->data == data){
            insertPoint(tempNode, data);
            return;//直接返回 不继续循环 缺点：只能插入一次
        }
    }
    printError();
}

template <class T>
void List<T>::insert(node *insertNode, T data){
    if (!insertNode->succ){
        printError();
        return;
    }
    insertPoint(insertNode, data);
}

template <class T>
void List<T>::insertPointByPos(int pos, T data){
    int count = 0;//计数器
    node *tempNode = header;   
    while(tempNode->succ){
        tempNode = tempNode->succ;
        count++;
        if(count == pos){
            insertPoint(tempNode, data);
        }
    }
    printError();
}

template <class T>
void List<T>::deletePoint(){
    if(iterator == header){
        printError();
        return;
    }
    
    node *tempNode = header;
    while(tempNode->succ){
        tempNode = tempNode->succ;
    }
}

template <class T>
void List<T>::deletePoint(T needNum){

}

template <class T>
void List<T>::deletePointByPos(int pos){

}

template <class T>
List<T>::node* List<T>::getIterator(){
    return iterator;
}

template <class T>
bool List<T>::disordered(){

}

template <class T>
void List<T>::backInsert(T){
}

template <class T>
void List<T>::traserve(){

}

template <class T>
void List<T>::printAll(){
    begin();
    iterator = iterator->succ;//因为指向的是头结点 所以后移一位
    while(iterator){
        cout << iterator->data << " ";
        iterator = iterator->succ;
    }
    cout << '\n';
    begin();//复位
}

template <class T>
void List<T>::insertPoint(node *insertNode, T data){
    node *newNode = new node();
    newNode->data = data;
    newNode->succ = insertNode->succ;
    insertNode->succ = newNode;
    iterator = newNode;
}

void printError(){
    cout << "can't find num or point";
}

#endif // UNDIRECTIONALLINKEDLIST_H
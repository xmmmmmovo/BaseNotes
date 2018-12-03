/**
 * 单向链表类
 * 2018-12-3 xmmmmmovo by:c++
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
    bool next(); // 后移迭代器
    T nowNodeData(); // 获取迭代器data
    T nextNodeData(); // 获取下一迭代器data
    T beforeNodeData(); // 获取上一个的节点
    T getPosition(int); // 获取某节点数值
    void swapWithBefore();
    int getLength(); // 返回长度
    void insertInFort(T);//头结点后插入
    void insertInBack(T);//尾节点插入

    // 插入删除方法
    void insert(T);//直接在迭代器后方插入
    void insert(T, T);//某个数值后插入
    void insertPointByPos(int, T);//插入某个位置节点 因函数重载原因改名
    void deletePoint();//删除迭代器所在节点
    void deletePoint(T);//删除某个数值节点 因重名原因改名
    void deletePointByPos(int);//删除某个位置节点 同插入原因改名

    //课后习题
    bool disordered();//判断是否有序
    void backInsert(T, T);//前插
    void traserve();//将单链表转置

private:
    node *iterator;//迭代器 每次插入后迭代器指针指向插入位置
    node *beforeIterator;
    node *header;//头结点
    node *trailer;//尾结点
    int count = 0;

    void insertPoint(node *, T);//将节点后插入操作抽象成函数
    void delPoint(node *);
    void printError();
};

//构造单向链表
template <class T>
List<T>::List()
{
    header = new node();
    trailer = header;
    iterator = header;
    beforeIterator = NULL;
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
    beforeIterator = NULL;
}

template <class T>
void List<T>::end(){
    iterator = trailer;
    beforeIterator = NULL; // 尾部也先判断成null
}

template <class T>
bool List<T>::next(){
    beforeIterator = iterator;
    iterator = iterator->succ;
    return iterator ? true:false;
}

template <class T>
T List<T>::nowNodeData(){
    return iterator->data;
}

template <class T>
T List<T>::nextNodeData(){
    return iterator->succ->data;
}

template <class T>
T List<T>::beforeNodeData(){
    return beforeIterator->data;
}

template <class T>
T List<T>::getPosition(int pos){
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

template <class T>
void List<T>::swapWithBefore(){
    T temp;
    temp = iterator->data;
    iterator->data = beforeIterator->data;
    beforeIterator->data = temp;
}

template <class T>
int List<T>::getLength(){
    return count;
}

template <class T>
void List<T>::insertInFort(T data){
    node *insertNode = new node();
    insertNode->data = data;
    insertNode->succ = header->succ;

    header->succ = insertNode;
    iterator = insertNode;
    count++;
}

template <class T>
void List<T>::insertInBack(T data){
    node *insertNode = new node();
    insertNode->data = data;

    trailer->succ = insertNode;
    trailer = insertNode;
    iterator = insertNode;
    count++;
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
        if(tempNode->data == needNum){
            insertPoint(tempNode, data);
            return;//直接返回 不继续循环 缺点：只能插入一次
        }
    }
    printError();
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
        if (tempNode->succ == iterator){
            tempNode->succ = iterator->succ;
            delete iterator;
            iterator = tempNode;
            return;
        }
        tempNode = tempNode->succ;
    }
}

template <class T>
void List<T>::deletePoint(T needNum){
    node *tempNode = header;
    while(tempNode->succ){
        if(tempNode->succ->data == needNum){
            delPoint(tempNode);
            return;
        }
        tempNode = tempNode->succ;
    }
}

template <class T>
void List<T>::deletePointByPos(int pos){
    int count = 0;
    node *tempNode = header;
    for(int count = 0;tempNode->succ;count++){
        if (count + 1 == pos){
            delPoint(tempNode);
            return;
        }
        tempNode = tempNode->succ;
    }
    printError();
}

//迭代器停留于非顺序最后一个值
template <class T>
bool List<T>::disordered(){
    begin();
    iterator = iterator->succ;
    while(iterator->succ->succ){
        if (iterator->data > iterator->succ->data){
            iterator = iterator->succ;
            return true;           
        }
    }
    end();
    return false;
}

//前插
template <class T>
void List<T>::backInsert(T needNum, T data){
    node *tempNode = header;
    while(tempNode->succ){
        if (tempNode->succ->data == needNum){
            node *insertNode = new node();
            insertNode->data = data;
            insertNode->succ = tempNode->succ;
            tempNode->succ = insertNode;
            tempNode = insertNode->succ;
            count++;
            return;
        }
        tempNode = tempNode->succ;
    }
    printError();
}

//逆序 非递归解法
template <class T>
void List<T>::traserve(){
    node *medNode = header->succ;
    node *nextNode = header->succ->succ;
    node *preNode;
    medNode->succ = NULL;
    trailer = medNode;
    delete header;
    while(nextNode){
        preNode = medNode;
        medNode = nextNode;
        nextNode = nextNode->succ;
        medNode->succ = preNode;
    }
    node *newHeader = new node();
    newHeader->succ = medNode;
    header = newHeader;
}

template <class T>
void List<T>::insertPoint(node *insertNode, T data){
    node *newNode = new node();
    newNode->data = data;
    newNode->succ = insertNode->succ;
    if (insertNode == trailer){
        trailer = newNode;
    }
    insertNode->succ = newNode;
    iterator = newNode;
    count++;
}

template <class T>
void List<T>::delPoint(node *needDelNode){
    node *delNode = needDelNode->succ;
    if (delNode == trailer){
       trailer = needDelNode; 
    }
    needDelNode->succ = delNode->succ;
    delete delNode;
    iterator = needDelNode;
    count--;
}

template <class T>
void List<T>::printError(){
    cout << "can't find num or point\n";
}

#endif // UNDIRECTIONALLINKEDLIST_H
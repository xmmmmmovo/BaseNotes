/**
 * ����������
 * ���ü̳���д
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
    void begin();//����������ͷ���
    void end();//����������β�ڵ�
    bool next(); // ���Ƶ�����
    Singer nowNodeData(); // ��ȡ������data
    Singer nextNodeData(); // ��ȡ��һ������data
    Singer beforeNodeData(); // ��ȡ��һ���Ľڵ�
    Singer getPosition(int); // ��ȡĳ�ڵ���ֵ
    void swapWithBefore();
    int getLength(); // ���س���
    void insertInFort(Singer);//ͷ�������
    void insertInBack(Singer);//β�ڵ����

private:    
    typedef struct nodeList{
        Singer data;
        nodeList *succ = NULL;
    } node;
    node *iterator;//������ ÿ�β���������ָ��ָ�����λ��
    node *beforeIterator;
    node *header;//ͷ���
    node *trailer;//β���
    int count = 0;

    void printError();
};

//���쵥������
List::List()
{
    header = new node();
    trailer = header;
    iterator = header;
    beforeIterator = NULL;
}

//ͬ�� �ͷ��ڴ� ��ֹ�ڴ�й©
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
    beforeIterator = NULL; // β��Ҳ���жϳ�null
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
    if(pos > count){ // �ж��Ƿ�Խ��
        printError(); // ���ܳ���Ұָ������ �ݲ�֪���������
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
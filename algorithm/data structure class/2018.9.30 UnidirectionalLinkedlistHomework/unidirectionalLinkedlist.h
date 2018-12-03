/**
 * ����������
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
        nodeList *succ = NULL;//��� ��������private��������������޷�����
    } node;

    List();
    ~List();
    void begin();//����������ͷ���
    void end();//����������β�ڵ�
    bool next(); // ���Ƶ�����
    T nowNodeData(); // ��ȡ������data
    T nextNodeData(); // ��ȡ��һ������data
    T beforeNodeData(); // ��ȡ��һ���Ľڵ�
    T getPosition(int); // ��ȡĳ�ڵ���ֵ
    void swapWithBefore();
    int getLength(); // ���س���
    void insertInFort(T);//ͷ�������
    void insertInBack(T);//β�ڵ����

    // ����ɾ������
    void insert(T);//ֱ���ڵ������󷽲���
    void insert(T, T);//ĳ����ֵ�����
    void insertPointByPos(int, T);//����ĳ��λ�ýڵ� ��������ԭ�����
    void deletePoint();//ɾ�����������ڽڵ�
    void deletePoint(T);//ɾ��ĳ����ֵ�ڵ� ������ԭ�����
    void deletePointByPos(int);//ɾ��ĳ��λ�ýڵ� ͬ����ԭ�����

    //�κ�ϰ��
    bool disordered();//�ж��Ƿ�����
    void backInsert(T, T);//ǰ��
    void traserve();//��������ת��

private:
    node *iterator;//������ ÿ�β���������ָ��ָ�����λ��
    node *beforeIterator;
    node *header;//ͷ���
    node *trailer;//β���
    int count = 0;

    void insertPoint(node *, T);//���ڵ������������ɺ���
    void delPoint(node *);
    void printError();
};

//���쵥������
template <class T>
List<T>::List()
{
    header = new node();
    trailer = header;
    iterator = header;
    beforeIterator = NULL;
}

//ͬ�� �ͷ��ڴ� ��ֹ�ڴ�й©
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
    beforeIterator = NULL; // β��Ҳ���жϳ�null
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
            return;//ֱ�ӷ��� ������ѭ�� ȱ�㣺ֻ�ܲ���һ��
        }
    }
    printError();
}

template <class T>
void List<T>::insertPointByPos(int pos, T data){
    int count = 0;//������
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

//������ͣ���ڷ�˳�����һ��ֵ
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

//ǰ��
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

//���� �ǵݹ�ⷨ
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
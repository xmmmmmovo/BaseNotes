/**
 * ?????
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
        T data = 0;
        nodeList *succ = NULL;//?? ?????private???????????
    } node;

    List();
    ~List();
    void begin();//????????
    void end();//????????
    void insertInFort(T);//??????
    void insertInBack(T);//?????
    void insert(T);//??????????
    void insert(T, T);//???????
    void insertPointByPos(int, T);//???????? ?????????
    void deletePoint();//?????????
    void deletePoint(T);//???????? ???????
    void deletePointByPos(int);//???????? ???????
    void printAll();
    node* getIterator();//???????

    //????
    bool disordered();//??????
    void backInsert(T, T);//??
    void traserve();//??????

private:
    node *iterator;//??? ????????????????
    node *header;//???
    node *trailer;//???

    void insertPoint(node *, T);//?????????????
    void delPoint(node *);
    void printError();
};

//??????
template <class T>
List<T>::List()
{
    header = new node();
    trailer = header;
    iterator = header;
}

//?? ???? ??????
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
    iterator = insertNode;
}

template <class T>
void List<T>::insertInBack(T data){
    node *insertNode = new node();
    insertNode->data = data;

    trailer->succ = insertNode;
    trailer = insertNode;
    iterator = insertNode;
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
            return;//???? ????? ?????????
        }
    }
    printError();
}

template <class T>
void List<T>::insertPointByPos(int pos, T data){
    int count = 0;//???
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

template <class T>
typename List<T>::node* List<T>::getIterator(){
    return iterator;
}

//??????????????
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

//??
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
            return;
        }
        tempNode = tempNode->succ;
    }
    printError();
}

//?? ?????
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
void List<T>::printAll(){
    begin();
    iterator = iterator->succ;//????????? ??????
    while(iterator){
        cout << iterator->data << " ";
        iterator = iterator->succ;
    }
    cout << '\n';
    begin();//??
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
}

template <class T>
void List<T>::printError(){
    cout << "can't find num or point\n";
}

#endif // UNDIRECTIONALLINKEDLIST_H
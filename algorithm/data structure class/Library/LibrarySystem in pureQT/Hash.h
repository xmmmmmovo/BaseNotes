#pragma once
/**
哈希表
总体使用拉链法解决冲突
*/
#include "Book.h"
#include "Vector.h"
#include "List.h"
#include <cstdio>
#include <QDebug>
using namespace std;
typedef int KeyType;
#define Length 100 // 定义100个节点以供分类

typedef struct HashNode
{
    book *book = NULL; // 指针类型传输，节省时间
    bool isNull = true; // 判断此节点是否已经被占用
    int count = 0; // 记录每本书的数量
    Vector<long long int> bookNums; // 用于记录所有同类书本的编号
}hashnode;

node **HashTable; // 用于存放哈希节点的数组

/**
  初始化哈希表
*/
void initHashTable(){
    HashTable = (node **)malloc(sizeof(node *) * Length); // 分配空间
}

/**
  获取哈希地址
*/
int getHashAddress(book *data){
    return (data->bookNumber / 100) % 7 * 3 + data->bookType;
}

/**
  插入
*/
void insertHashData(book *data){
    int address = getHashAddress(data);
    if (HashTable[address]->hashNode->isNull) { // 如果没有节点就说明这个就是第一个节点
        HashTable[address] = initList();
        HashTable[address]->hashNode = (hashnode *)malloc(sizeof(hashnode));
        HashTable[address]->hashNode->book = data;
    }else {
        hashnode *newNode = (hashnode *)malloc(sizeof(hashnode));
        newNode->book = data;
        addNode(newNode, HashTable[address]);
    }
}

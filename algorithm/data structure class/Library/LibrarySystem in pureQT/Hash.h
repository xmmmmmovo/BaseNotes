#pragma once
/**
哈希表
*/
#include "Book.h"
#include "List.h"
#include "Vector.h"
#include <cstdio>
#include <QDebug>
using namespace std;
typedef int KeyType;
#define Length 100 // 定义100个节点以供分类

typedef struct HashNode
{
    book *node = NULL; // 指针类型传输，节省时间
    bool isNull = true; // 判断此节点是否已经被占用
    int count = 0; // 记录每本书的数量
    Vector<long long int> bookNums; // 用于记录所有同类书本的编号
}hashnode;

node *HashTable;

/**
  初始化哈希表
*/
void initHashTable(){
    HashTable = (node *)malloc(sizeof(node) * Length); // 分配空间
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
}

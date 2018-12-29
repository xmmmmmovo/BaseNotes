#pragma once
/**
哈希表
总体使用拉链法解决冲突
*/
#include "Book.h"
#include "Vector.h"
#include "List.h"
#include "Structs.h"
#include <cstdio>
#include <QDebug>
/**
  哈希表(散列表)
  优点：查找插入便捷
  缺点：无法排序
  冲突解决方案：拉链法
*/
using namespace std;
typedef int KeyType;
#define Length 26 // 26个字母节点

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
    return (int)data->bookName[0] % 100; // 采取书名唯一标识获取哈希地址
}

/**
  插入哈希节点
*/
void insertHashData(){
}

/**
  删除哈希节点
*/
void deleteHashData(){
}

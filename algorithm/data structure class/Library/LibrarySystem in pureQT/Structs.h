#ifndef STRUCTS_H
#define STRUCTS_H
#define Rank int

/**
  用于存放所有的结构体
*/
#include <string>
#include <stdio.h>
#include "Vector.h"
using namespace std;
/**
  图书结构体
*/
typedef struct Book {
    string bookName = "null"; // 书籍名称
    int bookStock = 0; //书籍库存
    bool ifRent = false; // 是否出借
    int bookType = -1; // 书籍类型
}book;

/**
  哈希表节点
*/
typedef struct HashNode
{
    book *insideBook = NULL; // 指针类型传输，节省时间
    bool isNull = true; // 判断此节点是否已经被占用
    int count = 0; // 记录每本书的数量
    int firstChar = '\0';
    Vector<long long int> bookNums; // 用于记录所有同类书本的编号
}hashnode;


/**
  双向链表节点
*/
typedef struct Node{
    hashnode *hashNode = NULL; // 存放哈希节点
    struct Node *next = NULL;
    struct Node *befo = NULL;
}node;

/**
  自定义树节点
*/
typedef struct treeNode{
    hashnode *aNode; // 用于存放哈希节点
    struct treeNode *parent = NULL; // 父节点
    Vector<struct treeNode *> children; // 定义孩子节点
}treenode;

#endif // STRUCTS_H

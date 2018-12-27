#pragma once // 只被include一次
/**
链表
*/
#include "Book.h"
typedef struct HashNode hashnode; // 声明预防互相包含问题
/**
链表节点
*/
typedef struct Node{
    hashnode *hashNode = NULL;
    struct Node *next = NULL;
}node;

/**
初始化链表
*/
node *initList() {
    node *header = NULL; // 头结点
    header = (node *)malloc(sizeof(node));
    return header;
}

/**
添加节点
*/
void addNode(hashnode *newHashNode , node *header) {
    return;
}

/**
删除节点(通过编号)
*/
void removeNode(node *header, long long int number) {
    return;
}

/**
删除节点(通过名称)
*/
void removeNode(node *header, string name) {
}

node *findNode(){
}

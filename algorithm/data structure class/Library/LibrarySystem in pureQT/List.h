#pragma once // 只被include一次
/**
  链表
*/
#include "Book.h"
#include "Structs.h"

/**
  初始化节点
*/
node *newNode() {
    node *newNode = (node *)malloc(sizeof(node)); // 为新节点分配空间
    return newNode;
}

node *newNode(hashnode *hashNode) {
    node *newNode = (node *)malloc(sizeof(node)); // 头结点
    newNode->hashNode = hashNode;
    return newNode;
}

/**
  添加节点
*/
void addNode(hashnode *newHashNode , node *nowNode) { // 在nowNode(当前节点)之后插入
    node *newNode =(node *)malloc(sizeof(node)); // 为新节点分配空间
    newNode->hashNode = newHashNode;
    newNode->befo = nowNode; // 前连
    nowNode->next = newNode; // 后连
}

/**
  删除节点
*/
node *deleteNode(node *delNode){
    node *tempNode = delNode->befo; // 一个中继节点
    if (tempNode) {
        tempNode->next = NULL;
        free(delNode);
    }else { // 如果是第一个就特殊删除格式
        tempNode = delNode->next;
        free(delNode);
        tempNode->befo = NULL;
        return delNode->next;
    }
}

/**
  寻找节点
*/
node *findNode(node *firstNode, string findingName){ // 传进去首节点
    node *findingNode = firstNode;
    while (findingNode->hashNode->insideBook->bookName != findingName
           && findingNode) { // 在寻找完所有点或者命中点之前都不会跳出循环
        findingNode = findingNode->next;
    }
    return findingNode;
}

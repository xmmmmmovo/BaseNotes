#pragma once // 只被include一次
/**
双向链表
*/
#include "Book.h"
/**
双向链表节点
*/
typedef struct Node{
	book *book = NULL;
	struct Node *next = NULL;
	struct Node *before = NULL;
}node;

node *header = NULL; // 头结点
node *iteratorNode = NULL; // 迭代器
int length = 0;

/**
初始化链表
*/
void initList() {
	header = (node *)malloc(sizeof(node));
	iteratorNode = header;
	return;
}

/**
添加节点
*/
void addNode(book *newBook) {
	node *newNode = (node *)malloc(sizeof(node));
	newNode->book = newBook;
	iteratorNode->next = newNode;
	newNode->before = iteratorNode;
	iteratorNode = newNode;
	return;
}

/**
删除节点
*/
void removeNode() {
	node *temp = header;
	while (temp){
		if (temp->next == iteratorNode){
			free(iteratorNode);
			iteratorNode = temp;
			temp->next = NULL;
			return;
		}
		temp = temp->next;
	}
	return;
}
#pragma once // ֻ��includeһ��
/**
˫������
*/
#include "Book.h"
/**
˫������ڵ�
*/
typedef struct Node{
	book *book = NULL;
	struct Node *next = NULL;
	struct Node *before = NULL;
}node;

node *header = NULL; // ͷ���
node *iteratorNode = NULL; // ������
int length = 0;

/**
��ʼ������
*/
void initList() {
	header = (node *)malloc(sizeof(node));
	iteratorNode = header;
	return;
}

/**
��ӽڵ�
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
ɾ���ڵ�
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
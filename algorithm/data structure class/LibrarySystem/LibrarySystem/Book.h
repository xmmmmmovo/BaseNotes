#pragma once
/**
�鼮�����ڲ����к���
*/
#include <string>

using namespace std;

/**
�鼮�ṹ��
*/
typedef struct Book {
	long long int bookNumber = 0; // �鼮���
	int bookNameNumber = 0; // ͬ���鼮��Ψһ����
	string bookName = "test"; // �鼮����
	int bookStock = 0; //�鼮���
	bool ifRent = false; // �Ƿ����
	int bookType = -1; // �鼮����
}book;

/**
��ʼ���鼮
*/
book* initBook(int number, string name, int stock, bool rent, int type) {
	book *newBook = (book *)malloc(sizeof(book));
	newBook->bookNumber = number;
	newBook->bookName = name;
	newBook->bookStock = stock;
	newBook->bookType = type;
	newBook->ifRent = rent;
	return newBook;
}
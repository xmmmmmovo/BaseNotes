#pragma once
/**
书籍及其内部所有函数
*/
#include <string>

using namespace std;

/**
书籍结构体
*/
typedef struct Book {
	long long int bookNumber = 0; // 书籍编号
	int bookNameNumber = 0; // 同类书籍的唯一编码
	string bookName = "test"; // 书籍名称
	int bookStock = 0; //书籍库存
	bool ifRent = false; // 是否出借
	int bookType = -1; // 书籍类型
}book;

/**
初始化书籍
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
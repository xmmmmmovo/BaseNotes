#pragma once
/**
  书籍
*/
#include <string>

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
  初始化
*/
book *initBook(){ // 纯初始化
    book *newBook = (book *)malloc(sizeof(book));
    return newBook;
}

book* initBook(string name, int stock, bool rent, int type) {
    book *newBook = (book *)malloc(sizeof(book));
    newBook->bookName = name;
    newBook->bookStock = stock;
    newBook->bookType = type;
    newBook->ifRent = rent;
    return newBook;
}

#pragma once
/**
  书籍
*/
#include <string>
#include "Structs.h"

using namespace std;

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

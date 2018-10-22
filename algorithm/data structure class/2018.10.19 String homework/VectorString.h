/**
 * 向量字符串(利用之前写过的vector类(其实是偷懒直接用标准库的了))
 * !待完成 用继承覆写vector类并写出利用vectorString的复制比较连接
 * 2018-10-21 author:xmmmmmovo
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class vectorString
{
public:
    vectorString();
    ~vectorString();

    void strcreate(char *);
    void strassign(char *);//赋值函数
    int strlength();
    bool strempty();
    void strclear();
    int strcompare(char *);//可以是普通字符串
    int strcompare(vectorString &);//可以是对象
    void strconcat(char *);//同上
    void strconcat(vectorString &);
    char* substring(int, int);//子串(只需要一串)
    int index(char *);//查找 返回位置
    int index(vectorString &);
    void strinsert(char *, int);
    void strinsert(vectorString &, int);
    void strdelete(int, int);
    void replace(char *, char *);
    void replace(vectorString &, vectorString &);

private:
    vector<char> string;
    int strlength(char *);
};

vectorString::vectorString(){
}

vectorString::~vectorString(){
    //销毁字符串 释放空间
    delete &string;
}

void vectorString::strcreate(char *str){
}

void vectorString::strassign(char *str){
}

int vectorString::strlength(){
    return string.size();
}

int vectorString::strlength(char *str){
    int i = 0;
    for(i = 0;str[i] != '\0' ;i++);
    return i;
}

bool vectorString::strempty(){
    return string.empty(); 
}

void vectorString::strclear(){
    string.clear();
}

int vectorString::strcompare(char *str){
    int i = 0, cout1, cout2, lenth1, lenth2;
    if((lenth1 = strlength())>(lenth2 = strlength(str))){
        return 1;
    }else if(lenth1 < lenth2){
        return -1;
    }

    for(i = 0;i < lenth1;i++){
        cout1 += (int)string[i];
        cout2 += (int)str[i];
    }

    if(cout1 > cout2){
        return 1;
    }else if(cout1 == cout2){
        return 0;
    }else{
        return -1;
    }
}
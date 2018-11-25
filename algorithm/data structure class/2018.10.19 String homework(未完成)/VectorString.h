/**
 * 向量字�?�?(利用之前写过的vector�?(其实�?��懒直接用标准库的�?))
 * !待完�? 用继承�?写vector类并写出利用vectorString的�?制比较连�?
 * 2018-10-21 author:xmmmmmovo
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

class vectorString
{
public:
    vectorString();
    ~vectorString();

    void strcreate(char *);
    void strassign(char *);//赋值函�?
    int strlength();
    bool strempty();
    void strclear();
    int strcompare(char *);//�?���?��通字符串
    int strcompare(vectorString &);//�?���??�?
    void strconcat(char *);//同上
    void strconcat(vectorString &);
    char* substring(int, int);//子串(�?��要一�?)
    int index(char *);//查找 返回位置
    int index(vectorString &);
    void strinsert(char *, int);
    void strinsert(vectorString &, int);
    void strinsert(vectorString &, vectorString &);//根据字�?串匹配插入删�?
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
    for(int i = 0;i < strlength(str);i++)
    {
        string.push_back(str[i]);
    }
}

void vectorString::strassign(char *str){
    string.assign(str, str + strlength(str) - 1);
}

int vectorString::strlength(){
    return string.size();
}

int vectorString::strlength(char *str){
    int i = 0;
    for(i = 0;(str[i] != '\0')||(str[i] != '\n') ;i++);
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

void vectorString::strconcat(char *str){
    for(int i = 0;i < strlength(str);i++)
    {
        string.emplace_back(str[i]);
    }
}

char* vectorString::substring(int pos, int length){
    char *str = (char *)malloc(sizeof(char) * 20);//new 操作符不识别 改为malloc写法
    for(int i = pos - 1, j = 0;(i < length) && (i<strlength()) ;i++, j++)
    {
        str[j] = string[i];
    }

    return str;
}

int vectorString::index(char *str){
}

void vectorString::strinsert(char *str, int pos){
}

void vectorString::strdelete(int flg1, int flg2){
}

void vectorString::replace(char *str, char *repstr){
}
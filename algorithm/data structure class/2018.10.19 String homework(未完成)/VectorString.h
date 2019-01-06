/**
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
    void strassign(char *);
    int strlength();
    bool strempty();
    void strclear();
    int strcompare(char *);
    int strcompare(vectorString &);
    void strconcat(char *);
    void strconcat(vectorString &);
    char* substring(int, int);
    int index(char *);
    int index(vectorString &);
    void strinsert(char *, int);
    void strinsert(vectorString &, int);
    void strinsert(vectorString &, vectorString &);
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
    char *str = (char *)malloc(sizeof(char) * 20);
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
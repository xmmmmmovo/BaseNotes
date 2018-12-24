#pragma once
/**
哈希表
*/
#include <cstdio>
using namespace std;
typedef int KeyType;


struct Hash
{
    KeyType *elem = NULL; //记录哈希表中的元素
    bool *isFull = false; // 记录哈希表是否有元素了
    int count = 0; // 记录哈希表中的元素个数
    int sizeIndex;
};

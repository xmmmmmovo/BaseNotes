#pragma once
/**
线性表
*/
#include <iostream>
#include <cmath>
#include <string>

#define Rank int
int i = 0;
using namespace std;

/**
  线性表
*/
template <class T>
class Vector {
public:
    Vector();//构造函�?
    Rank size();
    T get(Rank);
    void put(Rank, T);//替换
    void insert(Rank, T);
    void append(T);//末尾添加
    void remove(Rank);//删除向量
    void remove(Rank, Rank);//函数重载
    bool disordered();//判断是否排列整齐
    void sort(Rank, Rank);//从小到大排序

private:
    T *sequenceList;//向量（连续表
    Rank nowSize = 0;//存放数值长�?
    Rank maxSize = 16;//总长�?

    bool checkLoHi(Rank, Rank);
    void checkIfOut();
    void increaseList();
    void moveBack(Rank);
    void moveForward(Rank);
    void swap(Rank, Rank);//交换数值操�?
    int med3(int a, int b, int c);
    void vecswap(int a, int b, int n);
};

template <class T>
Vector<T>::Vector() {
    std::locale::global(std::locale(""));
    sequenceList = new T[maxSize];//分配空间
}

template <class T>
Rank Vector<T>::size() {
    return nowSize;
}

template <class T>
T Vector<T>::get(Rank pos) {
    return sequenceList[pos - 1];
}

template <class T>
void Vector<T>::put(Rank pos, T num) {
    if (pos > nowSize)
    {
        cout << "Out Of List !!";
    }
    else
    {
        sequenceList[pos - 1] = num;
    }
}

template <class T>
void Vector<T>::insert(Rank pos, T num) {
    if (pos > nowSize)
    {
        cout << "Out Of List !!";

    }
    else {
        checkIfOut();
        moveBack(pos);
        sequenceList[pos] = num;
        nowSize++;
    }
}

template <class T>
void Vector<T>::append(T num) {
    checkIfOut();

    sequenceList[nowSize] = num;
    nowSize++;
}

template <class T>
void Vector<T>::remove(Rank pos) {
    if (pos > nowSize)
    {
        cout << "Out Of List !!";
    }
    else
    {
        moveForward(pos);
        nowSize--;
    }
}

template <class T>
bool Vector<T>::disordered() {
    for (i = 0; i < nowSize - 1; i++)
    {
        if (sequenceList[i] > sequenceList[i + 1])
        {
            return true;
        }
    }

    return false;
}

/**
  下面四个函数都是优化快排的内容
*/
template <class T>
void Vector<T>::swap(Rank a, Rank b){
    int temp = sequenceList[a];
    sequenceList[a] = sequenceList[b];
    sequenceList[b] = temp;
}

template <class T>
int Vector<T>::med3(int a, int b, int c) {
    return sequenceList[a] < sequenceList[b] ? (sequenceList[b] < sequenceList[c] ? b : sequenceList[a] < sequenceList[c] ? c : a)
            : sequenceList[b] > sequenceList[c] ? b : sequenceList[a] > sequenceList[c] ? c : a;
}

template <class T>
void Vector<T>::vecswap(int a, int b, int n) {
    for (int i = 0; i < n; i++, a++, b++)
        swap(a, b);
}

template <class T>
void Vector<T>::sort(int p, int r){
    if (p >= r)
        return;

    // 在数组大小小于7的情况下使用快速排序
    if (r - p + 1 < 7) {
        for (int i = p; i <= r; i++) {
            for (int j = i; j > p && sequenceList[j - 1] > sequenceList[j]; j--) {
                swap(j, j - 1);
            }
        }
        return;
    }

    // 选择中数，与qsort6相同。
    int len = r - p + 1;
    int m = p + (len >> 1);
    if (len > 7) {
        int l = p;
        int n = p + len - 1;
        if (len > 40) {
            int s = len / 8;
            l = med3(l, l + s, l + 2 * s);
            m = med3(m - s, m, m + s);
            n = med3(n - 2 * s, n - s, n);
        }
        m = med3(l, m, n);
    }

    int v = sequenceList[m];

    // a,b进行左端扫描，c,d进行右端扫描
    int a = p, b = a, c = p + len - 1, d = c;
    while (true) {
        // 尝试找到大于pivot的元素
        while (b <= c && sequenceList[b] <= v) {
            // 与pivot相同的交换到左端
            if (sequenceList[b] == v)
                swap(a++, b);
            b++;
        }
        // 尝试找到小于pivot的元素
        while (c >= b && sequenceList[c] >= v) {
            // 与pivot相同的交换到右端
            if (sequenceList[c] == v)
                swap(c, d--);
            c--;
        }
        if (b > c)
            break;
        // 交换找到的元素
        swap(b++, c--);
    }

    // 将相同的元素交换到中间
    int s, n = p + len;
    s = (a - p > b - a ? b - a : a - p);
    vecswap(p, b - s, s);
    s = (d - c > n - d - 1 ? n - d - 1 : d - c);
    vecswap(b, n - s, s);

    // 递归调用子序列
    if ((s = b - a) > 1)
        sort(p, s + p - 1);
    if ((s = d - c) > 1)
        sort(n - s, n - 1);

}

template <class T>
void Vector<T>::remove(Rank pos, Rank step) {
    for (i = pos; i < nowSize; i++)
    {
        sequenceList[i] = sequenceList[i + step];
    }
    nowSize -= step;
}

template <class T>
void Vector<T>::moveForward(Rank pos) {
    for (i = pos; i < nowSize; i++)
    {
        sequenceList[pos - 1] = sequenceList[pos];
    }
}

template <class T>
void Vector<T>::moveBack(Rank pos) {
    for (i = nowSize; i > pos; i--)
    {
        sequenceList[i] = sequenceList[i - 1];
    }
}

template <class T>
void Vector<T>::checkIfOut() {
    if (nowSize + 1 > maxSize)
    {
        increaseList();
    }
}

template <class T>
void Vector<T>::increaseList() {
    T* oldList = sequenceList;
    sequenceList = new T[maxSize <<= 1];//左移一�? 容量加�?
    for (i = 0; i < nowSize - 1; i++)
    {
        sequenceList[i] = oldList[i];
    }
    delete[]oldList;//释放空间 防止内存泄漏
}

//判断时利用主观的位置
template <class T>
bool Vector<T>::checkLoHi(Rank lo, Rank hi) {
    if ((lo <= 0) || (hi > nowSize)) {
        return false;
    }

    return true;
}

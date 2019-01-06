/*
因为模板类不能分离编�?
只能将实现与定义放在同一个文件里
故放�?.h头文件中
*/
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>
#include <string>

#define Rank int
int i = 0;
using namespace std;

template <class T>
class Vector{
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
        Rank searchUnsortedList(Rank, Rank, T);//搜寻
        Rank searchSortedList(Rank, Rank, T);//搜寻（有序向�?
        void deduplicate(Rank, Rank);//剔除重复向量
        void uniquify(Rank, Rank);//剔除重复元素(有序向量
        void show(Rank);//显示�?
        void showAll();//显示所�?
        //有时�?->写遍历并进行相同操作函数

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
        Rank bubbleSort(Rank, Rank);
};

template <class T>
Vector<T>::Vector(){
    std::locale::global(std::locale(""));
    sequenceList = new T[maxSize];//分配空间
}

template <class T>
Rank Vector<T>::size(){
    return nowSize;
}

template <class T>
T Vector<T>::get(Rank pos){
    return sequenceList[pos - 1];
}

template <class T>
void Vector<T>::put(Rank pos, T num){
    if (pos > nowSize)
    {
        cout << "Out Of List !!";
    }else
    {
        sequenceList[pos - 1] = num;
    }
}

template <class T>
void Vector<T>::insert(Rank pos, T num){
    if (pos > nowSize)
    {
        cout << "Out Of List !!";

    }else{
        checkIfOut();
        moveBack(pos);
        sequenceList[pos] = num;
        nowSize++;
    }
}

template <class T>
void Vector<T>::append(T num){
    checkIfOut();

    sequenceList[nowSize] = num;
    nowSize++;
}

template <class T>
void Vector<T>::remove(Rank pos){
    if (pos > nowSize)
    {
        cout << "Out Of List !!";
    }else
    {
        moveForward(pos);
        nowSize--;
    }
}

template <class T>
bool Vector<T>::disordered(){
    for(i = 0;i < nowSize-1; i++)
    {
        if (sequenceList[i] > sequenceList[i+1])
        {
            return true;
        }
    }

    return false;
}

template <class T>
void Vector<T>::sort(Rank lo, Rank hi){
    if(checkLoHi(lo--, hi--)){
        while(lo < (hi = bubbleSort(lo, hi)));//当最后的逆序对是lo的时候跳出循�?
    }else{
        cout << "Out Of List !!";
    }
    
}

//冒泡排序
//已优�? 不过时间复杂度最差也为o(n^2)
template <class T>
Rank Vector<T>::bubbleSort(Rank lo, Rank hi){
    Rank last = lo;
    
    while(++lo <= hi){
        if (sequenceList[lo - 1] > sequenceList[lo])
        {
            last = lo;//最后交换的逆序�?
            swap(lo - 1, lo);
        }
    }
    
    return last;
}

//遍历查找 缺点：重复数组的时候无法进行选择
template <class T>
Rank Vector<T>::searchUnsortedList(Rank lo, Rank hi, T num){
    if(checkLoHi(lo--, hi--)){
        for(i = lo;i <= hi;i++)
        {
            if (num == sequenceList[i])
            {
                return i + 1;
            }
        }
    }else{
        cout << "Out Of List !!";
    }

    return -1;
}

//有序向量搜寻
//二分查找
template <class T>
Rank Vector<T>::searchSortedList(Rank lo, Rank hi, T num){
    if(checkLoHi(lo--, hi)){
        Rank mi;
        while(lo < hi)
        {
            mi = (lo + hi)/2;

            if(num < sequenceList[mi]){
                hi = mi;
            }else{
                lo = mi + 1;
            }
        }

        return lo;//返回位置
    }else{
        cout << "Out Of List !!";
    }
}

//无序向量删除
//bug原因
//！！未完成！�?
template <class T>
void Vector<T>::deduplicate(Rank lo, Rank hi){
    if(checkLoHi(lo--, hi--)){
        for(i = lo;i <= hi; i++)
        {
            remove(searchUnsortedList(lo + 1, hi + 1, sequenceList[i]));
            hi--;
        }
    }else{
        cout << "Out Of List !!";
    }

}

//有序向量删除重复元素
template <class T>
void Vector<T>::uniquify(Rank lo, Rank hi){
    Rank j, count;

    if(checkLoHi(lo--, hi--)){
        for(i = lo;i < hi;i++)
        {
            if(sequenceList[i] == sequenceList[i+1]){
                for(j = i+1, count = 0; sequenceList[j] == sequenceList[i]; j++, count++);
                remove(i+1, count);
            }
        }
    }else{
        cout << "Out Of List !!";
    }
}

template <class T>
void Vector<T>::remove(Rank pos, Rank step){
    for(i = pos;i < nowSize; i++)
    {
        sequenceList[i] = sequenceList[i + step];
    }
    nowSize -= step;
}

template <class T>
void Vector<T>::show(Rank pos){
    if (pos > size)
    {
        cout << "Out Of List !!";
    }else
    {
        cout << sequenceList[pos - 1];
    }
}

template <class T>
void Vector<T>::showAll(){
    cout << "\n";
    for(i = 0;i < nowSize;i++)
    {
        cout << sequenceList[i] << " ";   
    }
    cout << "\n";
}

template <class T>
void Vector<T>::moveForward(Rank pos){
    for(i = pos;i < nowSize; i++)
    {
        sequenceList[pos-1] = sequenceList[pos];
    }
}

template <class T>
void Vector<T>::moveBack(Rank pos){
    for(i = nowSize;i > pos; i--)
    {
        sequenceList[i] = sequenceList[i-1];
    }
}

template <class T>
void Vector<T>::checkIfOut(){
    if (nowSize + 1 > maxSize)
    {
        increaseList();
    }
}

template <class T>
void Vector<T>::increaseList(){
    T* oldList = sequenceList;
    sequenceList = new T[maxSize <<= 1];//左移一�? 容量加�?
    for(i = 0;i < nowSize - 1;i++)
    {
        sequenceList[i] = oldList[i];
    }
    delete []oldList;//释放空间 防止内存泄漏
}

//指针交换bug待解�?!!!!
//暂时使用对象交换
template <class T>
void Vector<T>::swap(Rank a, Rank b){
    T temp;
    temp = sequenceList[a];
    sequenceList[a] = sequenceList[b];
    sequenceList[b] = temp;
}

//判断时利用主观的位置
template <class T>
bool Vector<T>::checkLoHi(Rank lo, Rank hi){
    if((lo <= 0) || (hi > nowSize)){
        return false;
    }

    return true;
}

#endif // VECTOR_H
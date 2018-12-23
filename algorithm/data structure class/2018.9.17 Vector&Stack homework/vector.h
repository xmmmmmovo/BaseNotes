/*
��Ϊģ���಻�ܷ�����1�7?
ֻ�ܽ�ʵ���붨�����ͬһ���ļ���
�ʷń1�7?.hͷ�ļ���
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
        Vector();//���캯�1�7?
        Rank size();
        T get(Rank);
        void put(Rank, T);//�滻
        void insert(Rank, T);
        void append(T);//ĩβ���
        void remove(Rank);//ɾ������
        void remove(Rank, Rank);//��������
        bool disordered();//�ж��Ƿ��������� 
        void sort(Rank, Rank);//��С��������
        Rank searchUnsortedList(Rank, Rank, T);//��Ѱ
        Rank searchSortedList(Rank, Rank, T);//��Ѱ��������1�7?
        void deduplicate(Rank, Rank);//�޳��ظ�����
        void uniquify(Rank, Rank);//�޳��ظ�Ԫ��(��������
        void show(Rank);//��ʾ�1�7?
        void showAll();//��ʾ���1�7?
        //��ʱ�1�7?->д������������ͬ��������

    private:
        T *sequenceList;//������������
        Rank nowSize = 0;//�����ֵ���1�7?
        Rank maxSize = 16;//�ܳ��1�7?

        bool checkLoHi(Rank, Rank);
        void checkIfOut();
        void increaseList();
        void moveBack(Rank);
        void moveForward(Rank);
        void swap(Rank, Rank);//������ֵ�ل1�7?
        Rank bubbleSort(Rank, Rank);
};

template <class T>
Vector<T>::Vector(){
    std::locale::global(std::locale(""));
    sequenceList = new T[maxSize];//����ռ�
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
        while(lo < (hi = bubbleSort(lo, hi)));//�������������lo��ʱ������ѭ�1�7?
    }else{
        cout << "Out Of List !!";
    }
    
}

//ð������
//���ń1�7? ����ʱ�临�Ӷ����ҲΪo(n^2)
template <class T>
Rank Vector<T>::bubbleSort(Rank lo, Rank hi){
    Rank last = lo;
    
    while(++lo <= hi){
        if (sequenceList[lo - 1] > sequenceList[lo])
        {
            last = lo;//��󽻻�������1�7?
            swap(lo - 1, lo);
        }
    }
    
    return last;
}

//�������� ȱ�㣺�ظ������ʱ���޷�����ѡ��
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

//����������Ѱ
//���ֲ���
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

        return lo;//����λ��
    }else{
        cout << "Out Of List !!";
    }
}

//��������ɾ��
//bugԭ��
//����δ��ɣ��1�7?
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

//��������ɾ���ظ�Ԫ��
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
    sequenceList = new T[maxSize <<= 1];//����һ�1�7? �����ӄ1�7?
    for(i = 0;i < nowSize - 1;i++)
    {
        sequenceList[i] = oldList[i];
    }
    delete []oldList;//�ͷſռ� ��ֹ�ڴ�й©
}

//ָ�뽻��bug����1�7?!!!!
//��ʱʹ�ö��󽻻�
template <class T>
void Vector<T>::swap(Rank a, Rank b){
    T temp;
    temp = sequenceList[a];
    sequenceList[a] = sequenceList[b];
    sequenceList[b] = temp;
}

//�ж�ʱ�������۵�λ��
template <class T>
bool Vector<T>::checkLoHi(Rank lo, Rank hi){
    if((lo <= 0) || (hi > nowSize)){
        return false;
    }

    return true;
}

#endif // VECTOR_H
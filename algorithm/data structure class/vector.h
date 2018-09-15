#ifndef VECTOR_H
#define VECTOR_H

#define Rank int

template <class T>
class Vector{
    public:
        Vector();
        Rank size();
        T get(Rank);
        void put(Rank, T);//替换
        void insert(Rank, T);
        void append(T);//末尾添加
        void remove(Rank);
        bool disordered();//判断是否排列整齐 
        void sort();//从小到大排序
        Rank find(T);//搜寻
        Rank search(T);//搜寻（有序向量
        void deduplicate();//剔除重复向量
        void uniquify();//剔除重复元素(有序向量
        void show(Rank);//显示秩
        void showAll();//显示所有
        //有时间->写遍历并进行相同操作函数

    private:
        T sequenceList;//向量（有序表
        Rank nowSize = 0;//存放数值长度
        Rank maxSize = 16;//总长度

        void checkIfOut();
        void increaseList();
        void moveBack(Rank);
        void moveForward(Rank);
        void swap(T *, T *);//交换数值操作
};

#endif // VECTOR_H
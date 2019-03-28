# 数据结构

[TOC]

## 绪论

### 3.1分而治之

- 二分递归

### 3.2 减而治之

- 每次递归之后的范围都缩小

### 一般递归仅为找规律所为 实现尽可能用迭代算法



## 向量



### 4.1.2 向量ADT（栈）

- size()报告向量当前的规模（元素总数）
- get(r)获取秩(长度)为r的元素
- put(r, e) 用e替换秩为r元素的数值
- insert(r, e)e作为r元素插入
- remove(r)删除秩为r的元素，返回该元素中原存放的对象
- disordered() 判断所有元素是否已按非降序排列
- sort() 以非降序排列
-  find(e) 查找
- search(e) 查找e并返回不大于e且秩最大的元素（有序向量）
- deduplicate() 剔除重复元素
- uniquify() 剔除重复元素（有序向量）
- teaverse() 遍历向量并统一处理所有元素，处理方法由函数对象指定

### 4.2向量(数组)

### 知识点

- [有序向量](https://blog.csdn.net/zh99_2014/article/details/53301373)
- [二分查找](https://blog.csdn.net/u014581901/article/details/50096759)

- 二分查找

  - binSearch() 普通的二分查找
  - fibSearch()  以fib(hi - lo).prev() (上一个fib数)为分割点

- 插值查找

  - 下面的公式适用于均匀且独立的随机分布
  - mi = lo + (hi - lo) * (e - A[lo]) / (A[hi] - A[lo])
  - 易受到小扰动干扰和“蒙骗”

- 插值查找(loglogn)/二分查找(logn)

  ```c++
  int insertSearch(Rank lo, Rank hi)
  {
      while(lo < hi)
      {
          mi = 二分mi/插值mi; // 二分(lo+hi)/2
              
          if(e < A[mi])
          {
              hi = mi; //[lo, mi)
          }
          else
          {
              lo = mi + 1; //(mi, hi)
          }
      }
      
      return --lo;
  }
  ```

- 总结

  - 大规模：插值查找
  - 中规模：二分查找
  - 小规模：遍历

### 题目

- 作为一个函数对象的类XXX，它必须显式定义以下哪个成员函数： operator()()
  - 对于函数对象来说，()是用于执行函数调用的操作符 
- T & Vector< T >::operator[ ] ( Rank r ) { return _elem[r]; } 中的返回值T&是什么意义？ 
  - 这是类型T的引用，使用它是因为返回值可作为左值
- 在binsearch(e, lo, hi)版本A中，若V[mi] < e，则下一步的查找范围是：
  - V(mi, hi) (注意右区间是开)

- 对于二分查找版本C，当e<V[mi]不成立时下一步的查找范围是： 
  - V(mi, hi) (并不会忽略V[mi]  因为返回--lo所以若是区间为零返回的要么是非法地址要么是V[mi])


## 列表(链表)

- 从秩到位置
  - 循秩访问 ×
  - 循位置访问 √

### 列表ADT接口

- pred()  当前节点前驱节点的位置
- succ()  当前节点后继节点的位置
- data()  当前节点所存储的对象
- insertAsPred(e)  插入前驱节点，存入被引用对象e，返回新节点位置
- insertAsSucc(e)  插入后继节点，存入被引用对象e，返回新节点位置
- first() ，last() 返回首、末节点的位置
- remove(r) 删除位置为r的元素，返回其引用
- sort()
- find(e)
- search()
- deduplicate()，uniquify()
- traverse()

### 特殊位置

- header 头元素，前于首元素，不在列表当中
- first 首元素，列表第一个元素
- last 末元素，列表最后一个元素
- trailer 尾元素，后于末元素，不在列表当中

### 初始化(构建哨兵节点)

```c++
template <typename T> void List<T>::init(){
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    
    header -> succ = trailer;
    header -> pred = NULL;
    trailer -> succ = NULL;
    trailer -> pred = header;//header跟trailer互联
    
    _size = 0;
}
```

### 题目

- 对于列表接口中的 find(e) 与 search(e)，其中一个重要区别在于 find 普适于所有列表，而 search 适用于有序列表。 
- 如果一个列表的 visible list 部分长度为 n，则头、首、**末、尾**节点的秩分别为 -1, 0, **n-1,n** 



## 排序



### 冒泡排序  最差o(n^2)

- 优化代码

  ```c++
  template <typename T> void Vector<T>::bubbleSort(Rank lo, Rank hi)
  {
      while(lo < (hi = bubble(lo, hi)));//直接根据最后的逆序对进行排序
  }
  template <typename T> rank Vector<T>::bubble(Rank lo, Rank hi)
  {
      Rank last = lo;//最右侧逆序对初始化为[lo - 1, lo]
      
      while(++lo <= hi)
      {
          if(_elem[lo - 1] > _elem[lo])
          {
              last = lo;
              swap();
          }
      }
      
      return last;//返回最右侧逆序对位置
  }
  ```

### 归并排序  稳定o(nlogn)

- 二路归并

  ```c++
  template <typename T> void Vector<T>::Merge(Rank lo, Rank hi)
  {
      T* A = _elem + lo;//合并后的向量A[0, hi - lo) = _elem[lo, hi)
      int lb = mi - lo;
      T* B = new T[lb];//前子向量B[0, lb) = _elem[lo, mi)
      for(i=0; i<lb; B[i] = A[i++]);//复制前子向量B
      int lc = hi - mi;
      T* C = new T[lb];//后子向量B[0, lc) = _elem[mi, hi)
      for(i=0, j=0, k=0; (j<lb) || (k<lc);)//B[j]和C[k]中小者转至A的末尾
      {
          if((j < lb) && (lc <= k || (B[j] <= C[k])))//C[k]已无 或 更大
              A[i++] = B[j++];
          if((k < lc) && (lb <= j || (C[k] < B[j])))//B[j]已无 或 更大
              A[i++] = C[k++];
      }
      delete[] B;
  }
  ```

### 题目

- 试用以下算法对V={19, 17, 23}排序:

  先按个位排序

  在上一步基础上，再按十位排序

  这个算法的是否正确？

  - 若第2歩用的排序算法是稳定的，则正确

  - 若第2步不稳定，可能的情况是：{19, 17, 23} -> {23, 17, 19} -> {19, 17, 23}

    以上算法称为“基数排序（radix sort）“，适用于被排序元素可分为若干个域的情况，它的正确性要依赖于对每个域分别排序时的稳定性

## 代码习惯

- 尽量用小于号
- 注重稳定性

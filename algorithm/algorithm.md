## 算法笔记(大部分是STL)

### binary_search()

- 头文件**<algorithm>**

- 重载

  - (first, last, val)
    - first 数组(vector)头
    - last 数组(vector)尾
    - val 查询数值
  - (first, last, val, comp)
    - comp 比较函数

- 举例

  ```c++
  // binary_search example
  #include <iostream>     // std::cout
  #include <algorithm>    // std::binary_search, std::sort
  #include <vector>       // std::vector
  
  bool myfunction (int i,int j) { return (i<j); }
  
  int main () {
    int myints[] = {1,2,3,4,5,4,3,2,1};
    std::vector<int> v(myints,myints+9);                         // 1 2 3 4 5 4 3 2 1
  
    // using default comparison:
    std::sort (v.begin(), v.end());
  
    std::cout << "looking for a 3... ";
    if (std::binary_search (v.begin(), v.end(), 3))
      std::cout << "found!\n"; else std::cout << "not found.\n";
  
    // using myfunction as comp:
    std::sort (v.begin(), v.end(), myfunction);
  
    std::cout << "looking for a 6... ";
    if (std::binary_search (v.begin(), v.end(), 6, myfunction))
      std::cout << "found!\n"; else std::cout << "not found.\n";
  
    return 0;
  }
  ```

### qSort()

- 头文件**<cstdlib>**

- 重载

  - (base num, size, compar)
    - base 基准数组(头指针)
    - num 数组长度
    - size 每个元素的大小
    - compar 比较函数

- 例子

  ```c++
  /* qsort example */
  #include <stdio.h>      /* printf */
  #include <stdlib.h>     /* qsort */
  
  int values[] = { 40, 10, 100, 90, 20, 25 };
  
  int compare (const void * a, const void * b)
  {
    return ( *(int*)a - *(int*)b );
  }
  
  int main ()
  {
    int n;
    qsort (values, 6, sizeof(int), compare);
    for (n=0; n<6; n++)
       printf ("%d ",values[n]);
    return 0;
  }
  ```

### stack // queue

- 头文件**<stack> // <queue>**
- 内容
  - pop() // 删除
  - push() // 压入

### pair

- 头文件**<iostream>**






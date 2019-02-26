# C++(入门教学)

[TOC]

### STL

[教程 + 详解](http://www.cnblogs.com/biyeymyhjob/archive/2012/07/22/2603525.html)



### 内联函数

```c++
#include <iostream>

using namespace std;
const double PI = 3.14159265358979;

inline double calArea(double radius) {

          return PI * radius * radius;
}

int main() {

          double r = 3.0;
          double area = calArea(r);
    
          cout << area << endl;

          return 0;
}
```

-   声明时使用关键字 inline
-  编译时在调用处用函数体进行**替换**，节省了参数传递、控制转移等开销
- 注意：
  - 内联函数体内不能有循环语句和switch语句； 
  - 内联函数的定义必须出现在内联函数第一次被调用之前； 
  - 对内联函数不能进行异常接口声明。 

### constexpr函数

- 初始化常量
- 只允许一条return语句
- constexpr修饰的函数在其所有参数都是constexpr时，一定返回constexpr； 
- constexpr变量的值必须在编译时便可以确认

```c++
constexpr int get_size() { 
    
    return 20;
}

constexpr int foo = get_size();  //正确：foo是一个常量表达式`

```



### 带默认参数值的函数

- 有默认参数的形参必须列在形参列表的最右，即默认参数值的右面不能有无默认值的参数； 
- 调用时实参与形参的结合次序是从左向右。
- 如果一个函数有原型声明，且原型声明在定义之前，则默认参数值应在函数原型声明中给出(main之前声明)；如果只有函数的定义，或函数定义在前，则默认参数值可以函数定义中给出。 

### 函数重载

- 同java

### C++系统函数

- 头文件
  - iostream
  - cmath
  - vector
  - string
  - iterator
  - algorithm
  - functional

### 面向对象基本特征

- 抽象

  - 对同一类对象的共同属性和行为进行概括，形成类。 
  - public, private,protected

- 封装

  - 将抽象出的数据、代码封装在一起，形成 类。 
  - private

- 继承

  - 在已有类的基础上，进行扩展形成新的类。 

- 多态

  - 同一名称，不同的功能实现方式。 
  - 达到行为标识统一，减少程序中标识符的个数。 

- 例子（钟表类）

  ```c++
  //类的定义
  #include<iostream>
  using namespace std;
  class Clock{
  
  public:         
  
       void setTime(int newH = 0, int newM = 0, int newS = 0);
  
       void showTime();
  
  private:  
  
       int hour, minute, second;
  
  };
  
  //成员函数的实现
  void Clock::setTime(int newH, int newM, int newS) {
  
     hour = newH;
  
     minute = newM;
  
     second = newS;
  
  }
  
  void Clock::showTime() {
      
     cout << hour << ":" << minute << ":" << second;
      
  }
  //对象的使用
  int main() {
  
       Clock myClock;
  
       myClock.setTime(8, 30, 30);
  
       myClock.showTime();
  
       return 0;
  
  }
  ```

### 构造函数

- 类似java

- = default 默认构造函数

- 示例

  ```c++
  class Clock {
  
  public:
  
     Clock() =default; //指示编译器提供默认构造函数
  
     Clock(int newH, int newM, int newS);     //构造函数
  
  private:
  
     int hour, minute, second;
  
  };
  ```

#### 委托构造函数

```c++
Clock(int newH, int newM, int newS):hour(newH),minute(newM),second(newS){
}

Clock(): Clock(0, 0, 0) { }
//调用上面的构造函数(同Clock::Clock():hour(0),minute(0),second(0))
```

#### 复制构造函数

- 复制构造函数是一种特殊的构造函数，其形参为本类的对象引用。作用是用一个已存在的对象去初始化同类型的新对象。 

> ```c++
> class 类名 {
> 
> public :
> 
>     类名（形参）；//构造函数
>     
>     类名（const  类名 &对象名）；//复制构造函数
>     
>     //       ...
> 
> }；
> 
> 类名::类（ const  类名 &对象名）//复制构造函数的实现
> 
> {    函数体    }
> 
> ```

- = delete 如果不希望对象被复制构造 
- 定义一个对象时，以本类另一个对象作为初始值，发生复制构造； 
- 如果函数的形参是类的对象，调用函数时，将使用实参对象初始化形参对象，发生复制构造； 

### 析构函数

- ~ 类名

### 类的组合

- 示例

  ```c++
  //例4-4 类的组合，线段（Line）类
  #include <iostream>
  #include <cmath>
  
  using namespace std;
  
  class Point {
      //Point类定义
      public:
      Point(int xx = 0, int yy = 0) {
          x = xx;
          y = yy;
  
      }
  
      Point(Point &p);
  
      int getX() { return x; }
      int getY() { return y; }
      private:
      int x, y;
      
  };
  
  
  Point::Point(Point &p) {	//复制构造函数的实现
  
  x = p.x;
  
  y = p.y;
  
  cout << "Calling the copy constructor of Point" << endl;
  
  }
  
  
  //类的组合
  
  class Line {	//Line类的定义
  
  public:	//外部接口
  
  Line(Point xp1, Point xp2);
  
  Line(Line &l);
  
  double getLen() { return len; }
  
  private:	//私有数据成员
  
  Point p1, p2;	//Point类的对象p1,p2
  
  double len;
  
  };
  
  
  //组合类的构造函数
  
  Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2) {
  
  cout << "Calling constructor of Line" << endl;
  
  double x = static_cast<double>(p1.getX() - p2.getX());
  
  double y = static_cast<double>(p1.getY() - p2.getY());
  
  len = sqrt(x * x + y * y);
  
  }
  
  Line::Line (Line &l): p1(l.p1), p2(l.p2) {//组合类的复制构造函数
  
  cout << "Calling the copy constructor of Line" << endl;
  
  len = l.len;
  
  }
  
  
  //主函数
  
  int main() {
  
  Point myp1(1, 1), myp2(4, 5);	//建立Point类的对象
  
  Line line(myp1, myp2);	//建立Line类的对象
  
  Line line2(line);	//利用复制构造函数建立一个新对象
  
  cout << "The length of the line is: ";
  
  cout << line.getLen() << endl;
  
  cout << "The length of the line2 is: ";
  
  cout << line2.getLen() << endl;
  
  return 0;
  
  }
  ```

### 前向引用声明

> 例子：
>
> class B;  //前向引用声明
>
> class A {
>
> public:
>
>   void f(B b);
>
> };
>
> class B {
>
> public:
>
>   void g(A a);
>
> };

#### 注意事项

- 当使用前向引用声明时，只能使用被声明的符号，而不能涉及类的任何细节。 
-  在提供一个完整的类声明之前，不能声明该类的对象，也不能在内联成员函数中使用该类的对象。 

- 例：

  ```c++
  class Fred; //前向引用声明
  
  class Barney {
  
     Fred x; //错误：类Fred的声明尚不完善
  
  };
  
  class Fred {
  
     Barney y;
  
  };
  
  /*
  上面的是错误程序
  */
  ```

### 结构体与类

- 结构体是一种特殊形态的类

1. 与类的唯一区别：类的缺省访问权限是private，结构体的缺省访问权限是public
2. 结构体存在的主要原因：与C语言保持兼容

- 什么时候用结构体而不用类

1. 定义主要用来保存数据、而没有什么操作的类型
2. 人们习惯将结构体的数据成员设为公有，因此这时用结构体更方便

### 联合体union(不常用)

- 用处：成绩模式（百分制 等级制 通过制）

### 枚举类enum

- 语法形式

  > enum class 枚举类型名: 底层类型 {枚举值列表};

- 转换限制，枚举类对象不可以与整型隐式地互相转换。（不同枚举类之间无法比较）

- 可以指定底层类型

### 友元

- 尽量不使用
- 友元函数是在类声明中由关键字friend修饰说明的非成员函数，在它的函数体中能够通过对象名问 private 和protected成员 
- 友元类若一个类为另一个类的友元，则此类的所有成员都能访问对方类的私有成员。声明语法：将友元类名在另一个类中使用friend修饰说明。 
- 如果声明B类是A类的友元，B类的成员函数就可以访问A类的私有和保护数据，但A类的成员函数却不能访问B类的私有、保护数据。(友元类是单向的)

### const

- 常对象，常函数，常引用，常数据
- 常对象：必须进行初始化,不能被更新。

  - const 类名 对象名
- 常成员

  - 用const进行修饰的类成员：常数据成员和常函数成员
- 常引用：被引用的对象不能被更新。

  - const  类型说明符  &引用名
- 常数组：数组元素不能被更新(详见第6章)。
  - *类型说明符  const  数组名[大小]...*
- 常指针：指向常量的指针(详见第6章)。

### foreach

- fori

  ```c++
  int main()
  {
  int array[3] = {1,2,3};
  int *p;
  
  for(p = array; p < array + sizeof(array) / sizeof(int); ++p)
  {
      *p += 2;
  
      std::cout << *p << std::endl;
  }
  
  return 0;
  }
  ```

- foreach

  ```c++
  int main()
  
  {
  int array[3] = {1,2,3};
  for(int & e : array)//类型 : 数组名
  {
      e += 2;
      
      std::cout<<e<<std::endl;
  }
  
  return 0;
  }
  ```

### 动态内存分配（不同于 C ）

- 动态变量
  - new 类型名 T
  - delete 指针 p

- 动态数组
  - new 类型名T[数组长度]
  - delete[] 数组名p

- 多维数组

  - 类似c

- 动态数组封装成类

  ```c++
  #include <iostream>
  #include <cassert>
  using namespace std;
  
  class Point { //类的声明同例6-16 … };
  class ArrayOfPoints { //动态数组类
  
  public:
  
  ArrayOfPoints(int size) : size(size) {
  
  points = new Point[size];
  
  }
  
  ~ArrayOfPoints() {
  
  cout << "Deleting..." << endl;
  
  delete[] points;
  
  }
  
  Point& element(int index) {
  
  assert(index >= 0 && index < size);
  
  return points[index];
  
  }
  
  private:
  Point *points; //指向动态数组首地址
  
  int size; //数组大小
  
  };
  
  int main() {
  int count;
  
  cout << "Please enter the count of points: ";
  
  cin >> count;
  
  ArrayOfPoints points(count); //创建数组对象
  
  points.element(0).move(5, 0); //访问数组元素的成员
  
  points.element(1).move(15, 20); //访问数组元素的成员
  
  return 0;
  }
  
  运行结果：
  
  Please enter the number of points:2
  
  Default Constructor called.
  
  Default Constructor called.
  
  Deleting...
  
  Destructor called.
  
  Destructor called.
  ```

### vector

> #include < vector >

- vector<元素类型> 对象名[]
- 具体指令可以看**数据结构**笔记

- 例子（重要理解）

  ```c++
  #include <iostream>
  #include <vector>//vector类导入
  
  using namespace std;
  //计算数组arr中元素的平均值
  
  double average(const vector<double> &arr)
  {
  
  double sum = 0;
  
  for (unsigned i = 0; i<arr.size(); i++)
  
  sum += arr[i];
  
  return sum / arr.size();
  }
  
  int main() {
  unsigned n;
  
  cout << "n = ";
  cin >> n;
  
  vector<double> arr(n); //创建数组对象
  
  cout << "Please input " << n << " real numbers:" << endl;
  
  for (unsigned i = 0; i < n; i++)
  
  cin >> arr[i];
  cout << "Average = " << average(arr) << endl;
  
  return 0;
  }
  
  //基于范围的for循环配合auto举例
  
  int main()
  {
  
  std::vector<int> v = {1,2,3};
  
  for(auto i = v.begin(); i != v.end(); ++i)
  std::cout << *i << std::endl;
  
  for(auto e : v)
  std::cout << e << std::endl;
      
  }
  ```

### 浅层复制与深层复制

- 浅层复制

![浅层复制图示](data:image/png;base64,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)

- 深层复制

![深层复制图示](data:image/png;base64,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PXjwoIvNUlJSiouLd+/eHRUVxXm2iYjIN0yKRIHX1tZWVFQUGxs7ffp0tXoPCS8jI8OiqfDzgd1uX7NmDRYuXbrkOv+lpqYiKba3t0dERBQWFs6fP1+2R9m6urqQIG/evOlzMYiIaIRgUiTqE+ooFp3IyMj09HTtmoSEhMrKSt1m2qf2aWfb3rhxowxqDgoKshjEx8efOHFClufMmVNfXx8dHY2wiFdfr4OIiEY0JkWiwJOUVl1dfeHCBZmC26LEuC1btvg587Y8QtpDONedO3cQWGtqarTFCAsLW7dunT/FICKiEYJJkahPLFd4suUJhYeH9faZ0VOmTNmr8GovIiIiwaRIREREROaYFImIiIjIHJMiEREREZljUiQiIiIic0yKRERERGSOSZGIiIiIzDEpEhEREZE5JkUiIiIiMsekSEQ0bGkfC0lE5AMmRSKi4cnbJ/oQERkxKRIRERGROSZFIiIiIjLHpEhERERE5pgUiYiIiMgckyIRERERmWNSJCIiIiJzTIpEREREZI5JkYiIiIjMMSkSERERkTkmRSIiIiIyx6RIREREROaYFImIiIjIHJMiEREREZljUiQiIiIic0yKFEijRo0a6CIQERFRwDApUsA8efJkoItAREREgcSkSERERETmmBSJiIiIyByTIhERERGZY1IkIiIiInNMikRERERkjkmRiIiIiMwxKRIRERGROSZFIiIiIjLHpEhERERE5pgUiYiIiMgckyIRERERmWNSJCIiIiJzTIpEREREZI5JkYiIiIjMMSkSERERkTkmRSIiIiIyx6RIREREROaYFImIiIjIHJMiEREREZljUiQiIiIic0yKRERERGSOSZGIiIiIzDEpEhEREZE5JkUiIiIiMsekSERERETmmBSJiIiIyByTIhERERGZY1IkIiIiInNMikRERERkjkmRiIiIiMwxKRIRERGROSZFIiIiIjLHpEhERERE5pgUiYiIiMgckyIRERERmWNSJCIiIiJzTIpEREREZI5JkYiIiIjMfZEUX3/99T179hg/2717Nz6SDbSv3Jgbc2NuzI25MTfmxtx4JGz8FdlI3jij/ZQbc2NuzI25MTfmxtyYG4+Qjb/i4jMiIiIiGsmYFImIiIjIHJMiEREREZljUiQiIiIic0yKRERERGSOSZGIiIiIzDEpEhEREZE5JkUiIiIiMsekSERERETmmBSJiIiIyByTIhERERGZY1IkIiIiInNMikRERERkjkmRiIiIiMwxKRIRERGROSZFIiIiIjLHpEhERERE5pgUiYiIiMgckyIRERERmWNSJCIiIiJzTIpEREREZI5JkYiIiIjMMSkSERERkTkmRSIiIiIyx6RIREREROaYFImIiIjIHJMiEREREZljUiQiIiIic0yKRERERGSOSZGIiIiIzDEpEhEREZE5JkUiIiIiMsekSERERETmmBSJiIiIyByTIhERERGZY1IkIiIiInNMikRERERkjkmRiIiIiMwxKRIRERGROSZFIiIiIjLHpEhERERE5pgUiYiIiMgckyIRERERmWNSJCIiIiJzTIpEREREZI5JkYiIiIjMMSkSERERkTkmRSIiohHB4XCMHz/ek5VEKiZFIiKiIWD27NmHDh0KDw/XriwrK8NrbGysJ2mvu7s7IiLi9OnTs2bNstvtU6ZMwcqWlpacnBwcGStd756dnR0fHz9nzhxnGyB04pW5c5hhUiQiIhrs2tra7t27N2nSJN368vJyi5IUXexbWFgYFRUlCS8kJEQS4Te/+c1jx44tX7785s2b9+/ft1qtrguAFIhAGRkZqa5ZsmRJYmKidhuEzo6OjoqKCsmgNDwwKRIRkb/sdvvKlSux8N577zEl9IWurq6ioiJdtR9ue3Nzc2trq+tqvHXr1k2dOhWbqWsaGhq2bduGmIjl2tpaREm3FYGNjY0pKSmyi8Cp9+/fr6tiDAoK4i/AMMOkSERE/qqvr29vb5eFV155ZaCLM6zYbLbw8PDu7u5du3ZZlMh4+/ZtSWxXr17VNQe3tbUZW4cR3RDysKMETYfDcfPmzb1791qUrPnhhx/Onz/fbTF2796NPwMs7vo1jhs3zpeLpEGMSZGIiPwVHR0dEhIiCz4fJDU1Fa9FRUV+Fmb27NmIrVar9d69e34eqh80NDTk5OQ0NzeXlpaahuyFCxdmZWXNnDlTuiTW1dU1NTVdv34d+Q/pbfHixbJeJCUlmR4HR8D2yJHyFqGzsLBw9erVCJ3btm3TJj+UB4WRHKnCjjiyVBbm5+dfvHjx/Pnzgbl+GvSYFImIyF/IEDdv3vTzIMXFxfHx8X4epKurCzExJSUFR5PaOD8P2HeQyZDYpC7WNV3F4YoVK3DDsTvSuTZYOxwO5Dldn0U1R/b29qalpWGX6upqi1L5h/xXWVmp3Qa7SypVKyAFzpKbmyunKCkp8T/N0xDCpEhERMPHmTNn8IpYg6R49uzZQZsUEcWk/hXJbOLEichw3h4hJyenpqZGu6a7u9tiGHqs1i+mpqZGRkbev3//1q1bWFi+fDli34EDBxITE2UbCZoI2bqOhlVVVcuWLcNhUWbc3qVLl8bFxclHCJrXrl1Tt6yrq0OK9fZCaJBjUiQiGokSEhLwNf/kyZOysrKCgoL29vaQkJDCwkLtkAWL0uxYVFSE1GVRhs3GxMSkp6drs4gcR33b2tqq6ycnG3z22WfV1dUZGRk9PT26E40aNUrduFKhvtU1pNpstvLycrUwSFfGZlbsgqyDEuK1pKRE14qKi0UYkrEdcl1Wq3Xbtm3ai1LvjNoubDyX1Mbh+LgcvMW5kMPUC8/OzsaO9fX1upu5ZMkSHO3OnTuIYrNmzYqPj0dMxF7a5mMPYZf9+/d7Ph8NioQ8il1QsE2bNi1atEjqBRGpOzo6ZBsJmrqYiPgovQJu3LiBfIntr1+/rn7qetIcGh6YFImIRi7JLrKMsBgdHX358mW1Hg5RSdvvsF2BeNTZ2entnHmImLoTGTOla4iJCxcu1BYGmW/evHnag2AbrEcMxfKyZcucNUAj5CEwyTKiHpaRomS8iErSnvZcwcHB6qFCQ0O1GxcrJAJalPyEfQ8fPqxNijJOWVtjd+LECc8vX6u3tzcsLAwXjivdvHmz258FrmXu3LlxcXHSTxEh9dKlS7dv30Z5sFJNio8ePZLOplo4+Llz56ZNm4YFnA75kkObRxomRSKikQtZoaCgYN26dfj6r6qqWrt2bWZmpgxWcDgcGzZswMKpU6eioqKk8XHr1q3YJT8/X62rO6GwGCoXjSfKyspKT0+3KEMiEKSuXbsmIe/JkyeyzahRo5CxnOWnffv2WTR1ltISqtvm7NmzeJWRvAsWLLAo0w0akyLOrtbnITwh9uXm5uqSIrbBBhLspCZSeyjsvmXLFpwItwUREDFRKhGl3hGHjYyMxN1466231Fx18uRJy5ejdryFi1WXb926NXPmTCkJ8iIieE1NjbOwiB/ikSNHNm3aJJ0OcZydO3dalLB4//59+XHggLIxIqMxKcrlWJRqVPyFoLtLNBIwKRIRjVxIgWqfMywg36g1fy0tLT09PciR6gaIFwglTz31FF51rbpuIXWpu0iVW11dnVfz6UjWaWxslPotvDWmlpKSElyCxCZENCwjwyEF6oKUtjCIQSiPMeNq245RTiTFBw8eqJ9q4yxOJFekOwXu5NWrV9WkWFpaivIEtq0WeRGBr7q62tmdfPjwofYuIafiLwFJmcHBwXJbkDtlbh38xJ31MkTi3LFjh65bJI0QTIpERCOXbibnyZMnW76ck+/OnTtYjoqK0m6AbGGaq9zyf1Bzenr6xYsX0xQpKSmxsbFSpaduYLPZEG23b9+ursEy4hoCkK6/oK4warWolm4XteJTPZfaY9IUyma1Wnfv3i05W5rFkT49vdr/CT8mNWJqR5DA4sWL1UpBo7Fjx6qdILGZ9KrEGnmYilRGzps3D/kbx6+qqjKt8kRMjImJQeDu7u5GKh03btyCBQskAWsrOy1f1nf6do00aDEpEhHR/zBhwoSBLoIJZJrz588jcp09e7akpEQGo5w7d06NUNL0vHbtWt2OCDe62OcnXY9JZ6XNzMxEqJXpZlA2lDawxRA4xejRo10UA1FS/h5ISEhQO6HW1dUhRkvOxg1cv359WFiY5cuGZh1cCAL31q1b9+zZEx0dzX6KIw2TIhERfcHhcDQ1NSHQSBSQh22ovQmF3W6vrKzUPvw3sO7evet6g3DF3r17ZbQNIo46jyPio+kupg3Q/pAek6WlpbGxsXJY6eyo22zdunWIcUePHk1PT8/JycH2gSqAlq5W2Pj4ZtlAxrJITMRye3u72qnAoow3WrNmDRKh6SmysrK0I7t1B9eu19V30vDApEhENHJ1dXWpA0Sys7N7enoQC+QjGRGSlJSEyKgd0YKViYmJfVEYpJzm5uaqqiptiFEtWbIEZQsODpYgO3369JCQEHXaaml6Ligo0HVeLCwsRFwzNkD7T/r5IV53dHRIdtSR/ovIr3PnzrX49/QaD+EHtHTpUtOPEMHDwsJwN/DTxF06dOiQ9tOZM2fi7km1otEUhfoWt/rjjz82/RnRsMSkSEQ0cunaaiMjI2U8rEXJB6WlpUiKxm204ye0syFaNNPHeDsJjkVp5USq055OO59is0K3C0KPLEjT8+rVq3UbYA2OGdgGaKmlc9sADVu2bKmsrMQVGaezthhuXZLCYphF0nO9vb3OPlqusNvtK1euXLx4MQqvpuqGhoaMjAyk8DVr1ly6dElXSSna2tquXbtWV1c3YcKE1NRUxsQRhUmRiIj+eyJrtTlVIK8EBwdLNzWL88muA2Xz5s1S42X6gDtET+1k1zJPjZr/sB7FM6YcrLFarYFtgEaYnjhxIg6IksjE3QiCU6dONW6J4knFp5+1sNpHoeieg9LV1XX79m0ZioRbJ1nTVFVV1YEDB44fP44Ej5/j1q1bo6KisDtWylOksc2iRYvy8vK0vwbYICgoyKK0QWsn/XFB6qd9ni2SBhsmRSKikcttzV94eLhMr+iMblCwkXFkMc5ouhfSySsK0+PMUTibnefevXvOCqD9yMXxXRTYWM5dCu1K0yuy2+04O8Ki6UMF3d46le5RKNKFVCAKP378eMeOHZLm161bZ9y9oaGhuroa+U/9UcqER/n5+TNnzlRXyr1F1kTilEApW546dUod7CxHk3HxKFVjY6O2b6KMwm5paZHN+mIED/U/JkUiIqLAa2trQ4Dr6empra315zj19fXamKir97UoGVpi36ZNm3R1flLjOH36dHl2n3A4HAhzn3/+ue7BjBYlLEZGRuqmH9K1NWunmfTnumioYFIkIiIKJG0HxKysLNMKRc/pauZM29Cx0rS2dZbC7TE9/IhGJiZFIiKiwIuMjERMHITBK4ATBtFIwKRIRDQSue2NRz7zvAMi0eDHpEhERERE5pgUiYiIiMgckyIRERERmWNSJCKiQLLb7Z7Mz2zK4XAM9fEW/lzCMLh8Gn6YFImIyBVvk9/GjRvXrFmjm5jac7Nnzz506JCHM8vYbDZ5/rLrzdra2izKvIPOPs3Jydm7d69uQpnU1NTY2FhvBy8nJyfjOMapCj3R3d0dERGhznpNNBgwKRIRjWiSopx59OgRYt+2bducPRzFaPLkyVFRUbpTIIodPHjQbXjCBu3t7aZPxjPV0dGxb98+7dPtent7r1y5ol0D5eXleHX2sJlr167dvXvXarVqVzocjuLi4okTJ/owzQ328q1qsLGxEa/Tpk0zfsRHntBAYVIkIhrRkAUfPnwoDw42GjNmzLlz5yxOGkYRX27evKl9uBwg6mmfUywQ3ZDqPKwp9KoKE0fWPiwEqTQtLc2rCYBaWloOHTqkuzqsRHZMT0/3/Dgq3Q0xZbPZcEN0K3Nzc5977rnq6mpjCRFbs7KyPM/rRIHCpEhENKL58wSR5Qrdyrq6Ou1zihGJJk2aZPqkEK/40/3R2QEfP36MggUFBUnxEHynT58uy4hreXl52viIDKprFPa8W6Gx8MHBwVOnTtWuxNnxWlNTYzwmorD2cXxE/YlJkYiIfNfV1ZWdna1t7dXVKSI4hoWFedVt0dggjgOWlJRcunTJ/8SpevDgQWhoaGlp6bhx48rKyrCmoKAAofb8+fMIdsXFxUiQsh5u3bqVk5PT2tqqDYuIdAkJCbqWbly+7kS9vb25ubnnzp3T7atLhIcPH9ZlU6LBgEmRiIjcc1Z/huima+rV1SmqTcPIlFar1bckFK/wYUe3tC3XKHlWVhYWEBORILUf2Wy2ixcvGgeaIMIaL9+0Qdy096GqoaEBERNnN+02ajrghqh/MCkSEZEbyDEbNmzQVumZdrMTpv0UISMjw8ORMV6N/EUy0769desWXtW6QHUbXc2fC3a7HaFWV05crLOunDq4/J07dxrXu4jIuJm7du06fvy4aZ/RSoW39bJEgcKkSEQ0EkmrMfKHOvyioKAAr2lpaZYvG1tLS0vV7fPy8tra2tSkGBwcPGbMGG2kczgcMTExERERFy9elFSk65ynrWYLIGMFHkruz7lkmLZv++ImeDV2WyxcuBA33zQfI6N/+umnd+7cCWwfTSLPMSkSEY1Epq3GCI6SsdzmLV03OwSa6urq3NxcdXwM1kRHR1++fNmfETP9DwEaWfnhw4e4HB/iZktLS0hISH19fWxsrIft7DabDa+6eYUsX9baIsdzLAsNLCZFIiL6b55M76Jjt9tXrlyJeCTz4EiTdHl5+f3793XjP0whmd2+fdv1TIGpqalIb6a99JDM5s+f722ZtbT9Au/evTtLYVGGoWRnZ3s7K82uXbsKCwunT58eERHhyfzhuHtbt241/Qh3MiMj4/r1614VgCjgmBSJiOgLlZWVph3sXJsyZUpSUtK0adMQCpGxbDZbZmbm9u3b4+Li2hSuw+Ljx4+jo6O1zdxY1vUylBmwTUPbgwcPvC2wh9atWzd16lTt0By3qqqqJk2aJKn39OnTixYtct0v0+Fw/OhHP8KWQUFBphssXbpU2+gc8HmCiDzBpEhERF/U7eHV2w52QkZaIBSmpqbOnz9fnREQGSs7O7uoqCg3N9d1U6zrdl4kURcDn1taWrRvvR3Rog2C2qEkyGRWq/Xu3bsuCqaFG3jgwAFcu7xFaD527BhC8Ny5c01rQxETk5OTtSOacQTkZu2F4OxqlWdfzBNE5AkmRQqYUaNGDXQRiHzx5MmTgS7CwEMiCQkJcV1lZVpBiHyD9bt378buO3fulB5+8hGyzsyZMxGeYmJinD1Jz09NTU26eQr9H9Giqq2t9bCTpQwP0k2avXz5cgTc3t5e4/aIifn5+bqJb0aPHq1Nijp9N08QkWtMihRI/MalIYd/4QhEPRn17MK1a9eMSfHo0aNIZoiJEyZM6OjoCA4OLi8v1w5tiY6O9q2q0i273d7T0+PVlDpe0cVEXKDpZg0NDZ9//rnp8wOl6dmY/5Cnja3SUxTqW9xtBNC+uzoiDzEpEhGNdMg69+7di42Ndb2ZafVYenr6pk2bbt++bVFq0SxKG+6YMWMsSr+9BQsWIP3cuXMn8IVWxnykpKT0xZGNXAydwXpnbetSZWicTJvdDWkIYVIkIhrRurq6NmzYUFtb63ZWl7S0NOPkz9gLKSo6OjorK0uXmaKioo4cOdLZ2ZmYmNgX2ai5uTk1NTXghzXlYugMn79HwxuTIhHRyIWY+PLLLx87dsy0Q562Y2JVVZVFqX3UzWiDNTk5OYiDxpEWiFBIljabbc2aNc8999yhQ4ecjcbQDUDxhMPhcNs4q1bmuRjRoj217pHNMtPhmDFjHj165MPAcJx99OjRuGR5jKFX+xINHkyKREQjFJJQeXn56dOnjQFu2rRp8fHxoaGh2pWRkZHTp09X3yKrHTlyZNy4cTJaBVHyxo0bSEUIVfL0ZIEMeunSpUWLFl24cMFZUnQ79tm4srq62tkENGosmzBhQn19fUZGRk9Pz5YtW9yeGoES2U5bcuRgxFzsHhIS4u0U4jgULhkXjt09byW32+3FxcUXL1788MMP4+LivDojUV9gUiQiGnEQ8pC0pk6d6uz5H+PHjz+hcHGExsbGzZs3q22viDVRUVExMTFIRbqqPgTE2tpaZ4fSxkpnG+hGkyBOBQcHm+ZOZNzOzk5ZnjJlCoIgtrxy5Ypxcm8cs7W1Vbvm4MGDuqZk7HXu3Dm5UuO5cBNcjEeWSbwXL16cnZ2dm5vr4gIRwdULRJmRgBG4t27d6naMEVE/YFIkIhpxkIf8nEcGRzDWeGGls9lwnFXIzVG4PpfbYcK6MhhPbXp240FMexy6KKHkaWfFFsanJhoZbxr26qN5hYi8xaRIREREROaYFImIiIjIHJMiEREREZljUiQiIiIic0yKRIOCw+FITk6urKyMj483DsAkIiIaEEyKRINCd3c3YiIWZC66QCXFwsLC2tra/fv38+mxRETkAyZFokFBJjqWOkUsB+qwnI9tGHv48OHYsWMHuhRENMwxKRINCm4nOibS+cY3vvGVr3zl+eefX7BgAV7nzZvnYVX0qFGj+rpsNDI9efJkoItAgcekSEQ0VP1ecerUKXn77LPPhoWFvfDCC0iNyI4uahz5jU4Bx79AhismRSL32tra5AG4+H7t6uo6evRoSUlJT0+P1WrNzMzUPtBMJY/Era2tbW5uxtuQkBB5ypnumRDqkbVMv8V1ZSgoKKiqqjItQ0JCgnR5VBlP0draquu5iONjr5qamvb2dovyeLE1a9asW7fO9EkYr7/++p49e0zv1VA0bL7hJDhWVFTIW6TGTZs2fec73+EAKSLyGZMikRcaGhqio6PVtwhqaWlpiIO6524hyS1atAifqmvaFTk5OfX19cbnz/pfhitXrvjTco3QuXbtWu2aZoWzw76u8Pl0gwpi4hCtYJsxY8bt27e1a5AIpTbxhRdemK0YoKIR0fAx6JIivgU3bNiAhWPHjvn5hUoUcIhoVqu1qKgoKioK38oSsJCosKA+A9dut0tMjIyMVAcd22y2zMxMbIkjaOvzsKDGlLKysqSkJM/LgDM6HI78/HwE0MrKyr17986aNQsbaPs7Sm2ZsQZRCwWWmFhaWoqDSyUiwm5bW9uNGzd8vVXUH9RoKF0Vn3322YEuEREFxic9vU9bxw10Kb4w6JLi4cOHpSYGC4FKikifONqKFSteeeWVgBxQhe/pp556SpYLCgp27doV2OMPLISbrVu3tre3x8fHc6SFQES7dOmSBDJAVsvKykJQO3DggJoUi4uL8TscEhJSU1OjtvqFh4fjbUREBO5nkSIgZcDxERClKfzChQtqwbzy4MEDWdD+BzJLoV4UDUL4L/Tpp58e6FIQDQeIZS8nH3jj1bil4cF9cfyDx8/f/J09deOLz816xsNdOn7/8daMI2lbVvRFkT7s+vju/V4PjzzokuKWLVuamppkIVDHREysrKxEUgzUAVUtLS0WpQsavv5LS0uHTVJsa2uTaqqBLsigU1tbq0tjkZGRuFfSGVHgrUWZyFDXOQxv9+zZs3btWkRJf5KisQxLly7154c1evRoWcjOzk5PT2eftqGCMZEoUCpqbFdufPTi+p8e/1nKd/9+gSe7NNk6PM9w//HoP39e3oiFrB++5HlN4Zn3W+9/9vD0we2BqlxEQLzQ0nmxpRPXO/Gpsf/nyK5vhc50u9egS4rLly+/d+/eQJfCU9XV1XiVr3+Exa6uLt8qdQYPu92OoIMoY1FqSa9cucK8qDVmzBjdmsmTJ8sCbt2UKVMQsuXt9OnTjburvx6ycaDK4CeUSmpGoaSkZNu2batWrQoODmZkJKKRAPkpr+gsFq7W/KMnyQnefufq+n8o/mFi1IE9G50dc8L4MbqEF7vyBW8zX9zfznOxi9sWamzQ8fuPf33zj60fdv9r879/+tlD9SMsn2lsnfbMRLdFGnRJcQhxOBySqKKiolJSUrB85syZoV6tePLkSVyI1Wo9d+7cnDlzEhISBrpEQ8aDBw+04c/13wy6jQfc3r17586du3v3bhl2I9WiiI/GwdpERMNM7i/PIDZNfGrsT/a/4+EuZ95vxatUE5qGxbv3e7+dkJuRumpjTHjfdTesqLH90X4/64cvWZTWarx2/uHufzz6T+RCx+d/kkKGzf36pKfGzg35GgrzwuyvYY23zdneJUWZfaO0tPSVV16pqqo6cOCANLppe+7rYLNKhUXpXxUXF5eammrc0jivh5zFdRnKysrKy8tNy2AcHJCkcH0KhL/GxkZdgWNjY017TErTM75Kx48fj20QsEwboKUkci7t5CYhISFpaWm6AsjVyfgDm822b98+KQmuLjc3Nzw8XLux3W6vr6+vq6tramqSzp0ys4l2whRsM3XqVCycOnXK2OdM7Wepfrpu3brOzk6ci/VJ3tI9WMV1BXMAn8ISKHEKFBt/8ODXVSJjSUnJ9evXGRaJaLh6t/E3yFuIU2+86kW37LQt/68/m2nFHhKbVOB5HhM/7PrY816MKqTV+gvtQTMmIwt+9S+/6Er0V5OfkkT4bulOb49mypc6xd7e3iVLlmg7ZmE5NDT08uXL2iiDFBITE6PdDGmmWJGVlbV3715/yu2sDK7HeLqGAsuAA2OBTQ8rTc/Lli3Da3DwFwnddQO0bnITbCzJ1TQQZ2dnS72OenULFy7UFUMioJbMbIKcp36741WeEacdcqGSsItAHBUVJWuwvT9d6Eaga9euWZS+qpKt1Qh4+/Zt428C/g7RbjwIocy7FPhDBb9y+E8Af40EfCgYEdFggHC2+dXSoBlPe94X8IPWW560UF9s6cRh07eudHaQn+x/51DeZu1JQ6KzfpgY9b3YhR62gKu2fjfS2YkCwpekKE+SRf6QWTnsdvvGjRsRUNasWaPtYigxESlEne9GatQQvJCBZs6cqf36Mc7r4WEZ3nrrLekchsSGbzV1VOkrCtlYWw3p4pj5+flIb9raO2THjo6Os2fPGjdWm54XLPii6yvKgB1xvc4aoHHhOLh6N7B7ZmYmjoCwGBsbq8sN69evl5JILSnu8MqVK7Fmx44d2nn7pFZy3rx5Eh9xTCS/DRs2SMBVs/iWLVtw+SibMcVKGN22bdugDS6DHO55RkaGRamxljW4kxLN8Wtw8eJF7Y3FxvjVsvTvs5jxK4ffByRUb/+Cwn8CciF9VDAiooH1SU9v0o/LZk2f/NoPVm/NOLJt/ZKxf/Fnrnd5+Kf/QrL87ksLXA9MwZEramyrXwzNP/SerGm+8lu8Vr/361/f/CMW8orOfvrZw5eTD+gSav2FdmlKHlR87KeorRRESKqoqJg6dSq+kGw2m2SshoYGqfDTTimCBYlxyDH4fvWzokJbBnwL4sh+jipFkMJrYmKiWjOKr/lwhXFjqY1DmFMb5rZv345LdjYCWpKfOm0KXlF+yZrd3d26oIaNdXe4sLAwOjpaW4cKN2/e1L7FQZBB8/LykFpKSkrU3bFSRmfrUiwCqBwwJSXF03s04l27dm3ChAnyQ5cpEuUpKZs3b1a3wc8OAQs3HH8s6eZTlI3xt0G/FTguLg6/Zkios2fPnj9/vumfBFVVVTdu3Fi1ahX+K5ZLU7thWMyqromIhjqZFmfSU2MP5W3u+P3HZ95vtd34KHzu113vdf+zh0h4Py9vnP3XU5LXL3G2WZPttxOfGqttof6j/T5esVfQjC8GQZ78xfdl/QPHI21SxKeDZA5FLV+SIhKPru0Y3y6SRTo6OiRXHT582KJ8ZRob4NLS0mTCuba2Np9bio1l8H/QMRIAXhFh1Vo6F6TpGelQXSO7OGuA1s2uZ1FumrODI7rprk4dYOsh7dNBLMo9l76S2qR49epVi1Ivy15onjPOjC2zG2p/svhNqK+vl2Sve4yecWNjD13L/6xW9/PxIfjRS79Ybc8Hy/+ci7u3t1cdxaKD/4Q5AT4RDTMSE5dHhPxT2suWL8eCICa67djXZOt4cf1PV78Y6iImwv5/aTjyZpJ24IhUJSII9tF8jT6Qik9Pmq19SYqmqUWS4q1bt+StfPnNnTvXuKWaou7evevD2V2UwU/qdyq+3ZFEkQLxVWoaQNWmZ22gxJamVXfCtGuasxAwf/583Rrtkzy0xdCOv3FBUgLKplb6wu7duy0BnbdypMEvSWJiorHzgEWpx0UUw89F5sR2vXGfwq/l9evX8euqPtDZCKUaN24cSqsOjXIx+IyIaEj7sOvjH+dVvvaD1S9FPd8Xx0eanPeN6Z4cHFmt++NPve2VaPRH+32c1Nu9Xnuz6sqNj7Cvs4l+VAGeJUcacFWu6/nu3LkT2LP7Sb5TZTZBGRpiURJeYWGhrlpFnXBbd4FJSUmIm/0zBbdxwJALU6ZMkXl8zp49K0kRPynkBlwCa4y84vmQqTkKtyO3tD103R7Q2Z8Wrg+Cn/5ehbMNEF5l4LMnxSAiGtJaO+7ohpKIzj/cVbsVOiONyK7hOJ70NZR6za7bdz2c/tqF+gvttz0omM6kp8aufjEUO779zlXXk40HOCmGhYVp3yKOuPhalfHCg4qM/M3NzUUWrK6uRrRCnIqOjtY9qU+anvGR6eCb/pmCOz8/X2Ki9lm9FufPDk5MTJSxRPIQjjNnzlj6d2gFERHRgPPwESy++aD1VlZ+Ff7pujwiPlqUajzkM3UllvHvwL+ce/O1BH+6Jw7Gsc+mpAF09uzZ8lYGAt+4ccNYUWGz2WRh0PaUl6EhgMiYnJyMS0OiUpOi2vTsQj9MwV1SUmJRupF5ODAoPDxcGscRguXSLEqzY58WkoiIaEgImjHZbd5qsnXIbNvOfCt05v3rB4zr8w+99+obJ/ruudJ9KjBJsaysTBbUDnaJiYlIijk5OZs2bdLVru3bt8/SvwMpZKhKeXm5t6OtZYSyrhegOgeh6VMHZR7EfmiAlv5kEydO1K5EisVlOttFxrUcPnx47Nix2B2XxslxiIiIBoTbZ/F5SObZ7ju+JMX29nZ12LI8JkSaOxGP1OQRGxubkZGBOLJo0SLdfIoSvBBTAnYR7ixbtky6HiLRahtqdZYsWbJ9+3bkWrXFHAXesWOHRemSqG4mw7q3bdtmepBVq1YhKfZDA7TU2ubm5kZFRcmci1evXk1NTdWNetaScS0ygQsWEOL7rnhERERDSKD6KVqUqsdPej533cz9buNv3vjFmZ/tXu//iBaV59ETJfS8dtPHpKib+8NiaAZFZLx06RJionF6DkC41PZfRO40HlD78D23k2a7hiwlucr10/zUUSw6Vqv19OnTsoxAJkkXidD0XOrI4r5ugEZGlEdo6G6djFwx3QURGT8mCbLG4TjC9GehHV4dHx/v4QiM4cTFaBIiIhoGvhU6o/XD7tDnprmoovvLMX++MSY8fvW33B5t/T8U459u5Yvrf6pbc6axNYBJcWvGkelTJsWufMH1ZtXv/frn5Y3Hf5biYZdNf1ufXcymIUOJT548Kc+QtSg1czExMYgy/TyBH2JrTU1NdXW1+pBoUzKtycWLF9VtjDObyByEFpfDcSSr9XUDNCLp5cuX1QdDy73dtGnT48ePXXSjRM6TafMKCwv7rmxERERDxeRJ494//r/wGhKdVVFje/O1BGcdFoOffeaZyeM9nF4Hx1Tr7aSfonGNTOjos8//4zFex2geLYMIeO3fb2vHzRjZbnxkUSZ9XBr+N57UQfqSFD2vVUIilGfIut7MqwobZxOCuD4Iop72+X7OiuF2AhTEYrdFVZ8oKNyeV8vzOVMsSlgE4/YuSihzWCLfG6dsFKw8IyKiEeW5Wc/g3/bdFVgOU8YsO2uGrvrXa1dufOR5bVxfu9H+xYTeulpJt+NmXkrad+b9VmzmYVN1gGfJocHMbrdv2LDBomRZjmUhIiISMqh5osuquNYPu694WRvX1+5/9jBoxtN9fRYmxZGioaEBMbGnpyc+Pp5zLBMREYlPenpTssrD5n799MHtWzOOfPtbQca+gx+03sorOouFwVOhCEiuG2PC+/osTIrDnG4i7sjIyIMHDw5geYiIiAYVpMMJ48cgJj5tHffPGfEvJx/4VeFWbVhETPy7zYWffvawr2Pi+K/+hecbyxP8IuYH9Vlx/huT4kghT7JmbSIRgenzpYhGoO27K+5/9lBiokXps5iflYBcqD5k7+13rm5//YsujH0dE12MpDElz31ZPNiSolfjLWgw8Go8DRGNEBy4RgE3FP/8kFEsakwUL0U9n5G6akHMT4pzNv3fTz77yYF3gmY8ratl9JlUBFqUXo+6j7x9It+/nLq4MSYc0db/UrnGOkUiIiIaWT7p6f3lr96f/ddTktcvMX6K0IYkl5J1FMtIY34+l1nr4Z/+q+T4+TPvt1q+eH6g74NRPmi9deXGR2+82h/thEyKRIOCw+GQh4zHx8cfPHiQg9OJiPpOk+2333lpgWmFHEJkRY0N/2Qo9L82/3voc9OQF70Ni9ppDlUvRT2Pf9/bVYLD/qpwq2+Fh19VX/5hYpTpbDjV7/361zf/6GJfabb2HJMi0aDQ3d0tk6jjlY/kJiLqU6Y9DiUjyhjnN19LQDp84Hj047zKV984gZXffWlB9Ldnz58zw21kREZsr89x0S6c+f3VbuspXeS5JlvH2+9evVm313UxAoVJkWhQmDZtWnx8vNQpYnmgi0NENIK82/ib+n+7+fPyxqAZT+ekx61ZPldiHF7fLd2JZFZwuA6f4p9FmZ173jemf23KpL+a/NTT1q9alKe8aHOh2x6NpiHyw66Piyrer7/Q3vmHT9SVpo8WfO3NqiNvJjkLmrErX3A983bzld9qT+EWkyINJUuXLj1//rzPuy9ZsqSpqSlwxQmk8ePHc8QYEVG/QTJr7bhz+dddb797deL4sQmrv3W15h9NQx6CF/590HrrTGPriTMfXLnxkUzBLd58LeHvlrh5wJsnEB8P7NloUaoM1/3gl58qs2obM9//Ljj9/62NcPZEwR8mRiG2uj7R6qjn/3HH33s+QIdJkYYYRD0EPh92RMTcs2dPoItDRERDydvvXEU6vG2/j+W5IV9b+MKs1I0vejKCGNEK//4p7WVExhvt3Td/Z8dB1q8J93DqHGS44Gc9GqeMdHjyF99PySo3dmR8t/E3n/U+cva06EN5mz3pTGk6iMcFJkWiPuFwOBobGysVFuVZ23FxcbGxscuXL9du1tbWFhoaqtvX2QwmriehaG1tNT64vKqq6sCBA83NzVgOCQmJiYlJSUmZMmWKt5dDRDQ8INj5OS2iREavdvF2BhyExd+9n2tcP3/ODGe1iRalrdyrs3iISZEo8BATIyIi2tvb1TU9PT3FCtM85z8k0QkTJujKgFwoGVG0K3Jycurr63WBlYiIBr8Bedg0kyJR4OXn5yOTRUZG5ubmhod/8VBO5LaOjo6zZ8/qtkRqVGsQdY9eNDLWNaqRtLa2VldTmJycjJioLUNXV1d2dnZlZeWGDRuuX7/OmkUiInKLSZEo8JDJ8JqYmCgRzaIMWAlXBPZEmZmZiIkFBQW6Izc0NCARWq3WmpoadcKdWbNmnThxQmoW6+vr+fAeIiJyi0mRKPCkITgjI2PevHl90dYsysrKiouLIyMjd+3apfuourraouRI47yMSUlJaWlpdXV1TIpEROQWkyJR4CGKVVVV9fT0hIaGIslt374deXHWrFkBPEVbWxsyn9VqraioMH564cIFKQYE8KRERDTSMCkSBR5C4fXr13NycoqLi5sVFmXocWFhYUCGkjgcjmXLlmHh3Llzpt0NtYNpiIiIfMakSNQnEOCKiopyc3NbWlqqq6sRGZHeoqOjCwoKjI3F3kpOTu7p6SktLXXWtG21WmUDNjETEZE/mBSJ+tD48eOXKxAZEe8qKyvT0tL8TIqFhYXy0D8XKXDp0qXYBiGVSZGIiPzBpEjUHxAZs7KyZBZuf9hsNmRNq9V68OBBF5vJI6SLi4uxcWD7RxIR0YjCpEgUeEuWLNm+fTsimto63NXVtWPHDovSW9Hnw9rt9jVr1mDh0qVLxkHNWlFRUdIAvWjRory8vOjoaOnOiGLcvn378OHDiK19NyibiIiGDSZFosBTR7HoIL2dPn1auyYhIcFY0ah9ap92tu2NGzci/GEhKCjIePD4+PgTJ07IMnIk0iRiIrY3nc0bSdHTiyEiohGMSZEo8FpbW5H/Ll68qObFyMjIxMTE2NhY13WBrpmmT2dmzZrV2dlZXV1dXl6uLUZERAQyJSsUiYjIE0yKRIE3R/H/t3f/MVHde/7Hp0n/aFNyZVVum42atlEjF7e2ezFCxUCDAgk2UlTarFwtahGjtgpsCgHTa1aCZhloSxt+KP6K3awgFBNN+SER4g8wGFtZXRq56TXIH6uoGTY27R8m3ff3fHLP99wzZ4ZhfjHDPB9/TObHmXM+5ww6r/l8zud9PFnyjMbD1Tpfzc89SaVbNVN6FwAAOpIiAAAArJEUAQAAYI2kCAAAAGskRQCIOMb59QDgBkkRACLLVKdGAYhkJEUAAABYIykCAADAGkkRAAAA1kiKAAAAsEZSBAAAgDWSIgAAAKyRFAEAAGCNpAgAAABrJEUAAABYIykCAADAGkkRAAAA1kiKAAAAsEZShD8999xzgd5Eb2+vL28PQgsBAJgxSIrwm99++y3Qm3jnnXc+++yzlJQUL94rEfPAgQOXLl3yd6MAAJixSIoAAACwRlIEAACANZIiACAS+XjWchDOtwFCAUkRABChvE57zI1D5CApAgAAwBpJEQAAANZIigAAALBGUgQAAIA1kiIAAACskRQBAABgjaQIAAAAayRFAAAAWCMpAgAAwBpJEQAAANZIigAAALBGUgQAAIA1kiIAAACskRQBAABgjaQIAAAAayRFAAAAWCMpAgAAwBpJEQAAANZIigAAALBGUgQAAIA1kiIAAACskRQBAABgjaQIAAAAayRFAAAAWCMpAgAAwBpJEQAAANZIigAAALBGUgQAAIA1kiIAAACskRQBAABgjaQIAAAAayRFAAAAWCMpAgAAwBpJEQAAANZIigAAALBGUgQAAIA1kiIAAACskRQBAABgjaQIAAAAayRFAAAAWCMpAgAAwBpJEQAAANZIigAAALBGUgQAAIA1kiIAAACskRQBAABgjaQIAAAAayRFAAAAWCMpAgAAwBpJEQAAANZIigAAALBGUgQAAIA1kiIAAACskRQBADPQo0ePzp8/H7j1nzhxws2rGRkZr7zySuC2DgQNSREh5Ndff33rrbfk1tUC//M//+PL+gcGBl577TU3C/zXf/1XVFSUL5sAECKio6NLS0sXaiwX+PDDD71euby3r6/P8qV79+798MMPH3zwgdcrB0IKSREh5IUXXpg3b97777+/evVqV8t4/TM9ISFheHjY1as3btyw2+3ERGDGeP755z/99FPJc8ePH/f7yt2sMy8vLzk5Wf438/tGgWlBUkRoSU9Pv3Xr1vbt2/2+ZvmP+9VXX3X16okTJ2TTft8ogGkk/5McOHDgxx9/XLJkSXC2ODY2dvbs2ZGRkeBsDggCkiJCy9q1a999993gb7ezs7Ompib42wUQOFFRUbt37z58+HAguhUt2e32Dz/8kDMUMZOQFBFa5Kf/s2fP/vKXv7g6tSgQHj16JFtMSEgI2hYBBMeuXbtiY2MrKyuDkN4cDseJEycGBwcDvSEgmEiKCDkZGRkdHR27d+8O2hZlc7LRoG0OQNBIQPzggw/sdvu///u/B3pbX3311erVq4P5KxcIApIiQk5mZubXX38dzKTY2dnJSYrATFVUVJSYmFhWVhYdHR24rfz666/yH9d3330XuE0A04KkiJCTkpLypz/9Sf7bDdrkwY6ODk5SBGaqhQsXJiUlHT16tLi4OHBbOXHixJIlS958883AbQKYFiRFhJyoqKj4+Pje3t7gjAgPDAzIF8ncuXODsC0A06KsrOzdd9/dvXt3gH5/Pnv2zG6319bWBmLlwPQiKSIUpaenX7hwIThJsaOjg6FnYGaTH59Lliz5z//8T1+qbbtx/vx5+YnL6c6YkUiKCEXBrJVDfRwgEhQVFf3rv/5rgJJiRUWFrD8QawamHUkRoShotXKojwNECPn9uX///vb29qysLP+uube3V/4n4fJ9mKlIighRwamVI5twc+VAADPJJ598Yrfb/Z4UZZ2y5uef5/sUMxN/2QhRwamVQ30cIHLk5ubu37//ypUrSUlJ/lrnDz/8ICtsaWnx1wqBUENSRIgKTq2cjo6OINTjBRAKnn/++aKiIrvd7sek+MUXX3zyySdBK+kFBB9JESEqCLVyBgYGXn31Va7QCkSO7du3Hzhw4Mcff1yyZInvaxsbGzt79uzIyIjvqwJCFkkRoSvQtXK4iB8QaeQn6O7duw8fPnz8+HHf12a32z/88EN+bWJmIykidAW6Vk5nZydDz0Ck2bVrV2xsbGVlpY8Jz+FwnDhxYnBw0F8NA0ITSRGhS9XKuXfv3quvvur3lT969OjHH3+kPg4QaSQgfvDBB3a73ccfil999dXq1asDXckLmHYkRYQ0VSunoKDA72tWQ88UtgAiUFFRUWJiYllZWXR0tHdr+PXXX7/++uvvvvvOvw0DQhBfkwhpmZmZDQ0NgUiK1McBItbChQuTkpKOHj1aXFzs3RpOnDixZMmSN998078NA0IQSREhLSUlJS8vLxC1cqiPA0SysrKyd999d/fu3V783/Ls2TO73V5bWxuIhgGhhqSIkBYVFSW/2q9cueLfK6lQHweIcPHx8UuWLDl9+vT27dun+t7z58/Lf01UTkCEICki1KWnp3d2dvo3KVIfB0BRUdG+ffu8SIoVFRWffvppIJoEhCCSIkLd2rVr33vvPf+OFFMfB4D837J///729vYpXQm6t7fX4XBs2LAhcA0DQgpJEaFuyZIlT58+9WOtHOrjAFA++eSTw4cPTykp2u32Xbt2UTYBkYO/dYQB/9bKoT4OACU3N3f//v29vb0pKSmeLP/DDz8MDAy0tLQEuF1ACOHLEmEgPT395MmT/kqK1McBoMgvxqKioi+++MLDpChL7tq1y++lGIBQRlJEGMjIyPjoo4/8VSuH+jgAdNu3bz9w4MDt27eXLl3qfsmxsbGzZ8/+9a9/DU7DgBBBUkQY8GOtHOrjADCS/152795tt9uPHz/ufklZRmLl3Llzg9MwIESQFBEe/FUrh/o4AEx27dq1aNGiyspKN78hHQ7HiRMnBgcHg9kwIBSQFBEe1q5du3HjRt9HjamPA8BEAmJubu7hw4drampcLfPVV1/Jj8yFCxcGs2FAKCApIjwsXbrU91o51McBYKmoqCgxMfGzzz6Ljo52fvXXX3/9+uuvv/vuu+A3DJh2JEWEDd9r5VAfB4ClhQsXJiUl1dfXl5SUOL964sQJ+bH65ptvBr9hwLTjKxNhw/daOdTHAeBKWVnZu+++u3fvXlONhWfPntnt9rq6uulqGDC9SIoIG77XyqE+DgBX4uPjlyxZcvr0adOVoM+fPx8VFeXfS88DYYSkiLDhY62cgYGBefPmUR8HgCtFRUX79u0zJcWKiopPP/10upoETDuSIsKJL7VyLl68SH0cAG6sXbt2//797e3t+pWge3t7HQ7Hhg0bprdhwDQiKcJvnnvuueBsqKqqyuv3Hjp0yI8twczw22+/TXcTECo++eSTw4cP60nRbrfv2rWLaXCIZPz1w5+C8I07f/78y5cvT7VWjsPheO2118bHx/kfHyZB+4WDsJCbm7t///7e3t6UlJQffvhhYGCgpaVluhsFTCe+NRFmvKuVI29ZvXo1MRGAe/K/RFFR0RdffCFJUW537drll8vNA+GLL06EGe9q5VAfB4CHtm/ffuDAAfl5efbs2b/+9a/T3RxgmpEUEWa8q5Uj/+n/27/9W+BaBWDGiIqK2r1798aNGyUyzp07d7qbA0wzkiLCjBe1cm7cuCH/3c+bNy+gDQMwY+zatevzzz+X2+luCDD9SIoIP1OtldPR0bF27dqANgnATPLKK698++23CxcunO6GANOPpIjwI7Fv48aNnl9tRWIlQ88ApoSLsgAKSRHhZ+nSpU+fPr13754ntXIcDsft27eTkpIC3y4AAGYakiLCkue1cqiPAwCA1/j6RFjyvFYO9XEAAPAaSRFhafXq1R7WyqE+DgAAXiMpIixFR0cvXbp00lo5YVQfx+Fw7Nixo7m5OScnp6GhQXZwulsEAABJEWHLk1o5YVQfZ3R0VGKi3JHbsrIyfyXFmpqac+fOffnll2+88YZfVggAiCgkRYSrjIyMP/3pT+5r5YRRfZwFCxbk5OSoPkW576/VFhYW+mtVAIAIRFJEuIqPj3c4HG5q5YRXfZzo6OgzmuluCAAA/x9JEWHMfa0c6uMAAOAjvkQRxtLT01tbW10lRT/WxxkaGlq2bJnc+e2330ZGRk6ePNnY2Dg+Ph4TE1NaWpqXl+d8WqHD4Th+/Pi5c+f6+vrkYVxcXFZWljTVNL1GX7ORbGXSNlRXV8u+W7bh/fffV6c86pw3cevWLdOZi7J+eVd7e/udO3fkYXJy8rp16zZu3BgW84Ei09OnT6Oiorx443PPPef3xgA2F/93IdyRFBHGMjIydu7c+ezZM8uOw0DUx+nu7k5LS9MfSlArLCyUONjb22tcTJLcypUr5VX9mTuaioqKrq6uNWvW+L0NAwMDvoxcS+jcsGGD8Zk+jY+rRUD90z/9k/zlv/nmmytWrJDb+Ph4zydC8Y0Ov+MXyEwVoklRvmjfe+89+Watrq7et2/fdDcHIUqvlZOSkmJ6KUD1cSSixcTE1NXVpaamytZVwJJEJXfWr1+vlhkbG1MxMTk5WZ903N/fX1paKkvKGoz9eXJH/84+duzYtm3bPG+DbNHhcFRVVUkAbW5uPnjw4KJFi2QB4/mO6v9u5x5EI2mwiolNTU2ycnXQ5N/g0NDQ999/7+2hQjD8RXP27Fn1cOHChQkJCX/84x8lNUp29K7HEQCMQjQpXr58WQ2BFRYW+ispyteefLnKHXXrR/Jt/Q//8A/q/kyKthIgWlpaJD3ow5GbN2/Ozs4OqVJ/qlaOc1IMUH0ciWhXr15VgUxIVisrK5OgVltbqyfF+vp6iYlxcXHt7e36sUpMTJSHSUlJcjDrNH5pg6xfAqIaCpd/NXrDpuTJkyfqztatW/UnF2n0nTL585//fODAAS+2FZpmTF+ICo6nT59WDyU1btmy5YMPPgipf7MAwkuIJsVVq1bJF63qU/TXOm/cuCFf4Tk5Of5aoW5wcNCmnYgmDZZcNTOSYnd396ZNm4zjp2o48tSpU8YANO0yMjLy8vIqKytNzweoPs65c+dMaUwCtCRFdTKiIg9tWiFD01GSh5KuNmzYIH+HviRF5za88847phMTp+TFF19Ud8rLy4uLiz35cP+s8XqLIUViYpgOxb722mv37t0zPiOfnepN/OMf/7hUM01NAzBzhGhSlC/C27dvT3crPNXW1ia3KgRIWBwZGfGuayd0OBwOFRMLCgoKCwtld/RRTolEx48fD500LN+Ljx49GhsbMw40B64+zksvvWR65uWXX1Z3VBuGhobUQ8vaPfofhqnBPrbBR9Iq1TMqGhsb8/PzMzMzY2NjQ+f3AFzRo6E6VXHhwoXT3SIAM02IJsUwIqGkvr5e7qSmpkqukvvnz58PnSDlHfn6+eabb+SOPvdCjXJKCG5ubq6srAypHVS1crZv364/Iw8lJga5Ps6TJ0+M4c/9rwXTwtNOPty33nrrs88+U9NuVLeoxEfnydoIHf39/a+88sp0twLADOfNV6mqwdHU1LR169bW1tba2lo19GY8f99E/kc7deqUKuohD3NycuR73XkGqPMZ/bKk5dRLYxvkXbJyyzY4lyBp1ky6ie7u7ra2NmODhZrEYFpSDT3LF6q8lJ2dLUnRcgBatURtS/XPqXIkMTEx+fn5piE/dRzU3hnrocTFxRUWFhpPJrNpvVNdXV2dnZ2XLl1SrVX1TUylW5YuXSqbk3ZajnumpKTIATS+ajk/Nz09XY6ecUg6FKhaOcakKEcjMzMzyM0wXVjFfdeyH6/C4i/rNdJs+amjTk5VXYw3b94kLIYmYiKAIPC+02ViYkLFC/0ZuS9h6Nq1a4mJicYly8vLVReFTsU1CTQ+nvHmqg3uZ3pOaufOnaqb0NRgFd1MC6uhZ3X14djYWJtWD8VNSjDVT5E7cnDkSctAbKqHImtWSdrYjPnz55vepU4orKysNH7HS8SU98p+yfOmYy5ZUx1D2XHrIxLanGvldHR0fPbZZ8HZ+o0bN2zaWarqqOoR8N69e85/Az09PcaFQ5C0eZ9Gft29/fbb8vcpv0Oc/+wBABHC+6Soriebk5OjanNI2sjNzZXAsW7duocPH+qL1dTUqJgoMUtNm1V9YJJaZOEdO3YYE9JWjbrvXD3YTRvsdrs6RUwSm3y36XNLnUuQuOqk1Ek4kzgVExPzzTffLF++XH2jy5rlO37WrFmmhfWh5xUrVsittEHir+yXqwFoiXqLFy82Hg3VKtnTvXv3mhJ2dXW16nSUlqxZs0a2VVpaKpuT5Y0TkFVHY3x8vArHstjg4KA6y1AWlk9HLaYnTtkR04TWlpYWtZ5J4/VPP/1k0+beul8syEy1ciS6yTOuLvHnX3K0S0pK5I7eFy6bVpdvlj8AaZIxEcrCauZNMK/FLB+W/CXIhz7V307y16h2JEANAwCEBZ9O5CorK9ODiISk06dPz58/X76W+vv7VeiRUKi+FM+ePaunE1lS4qCkrg0bNhiLwPneBvkulIDo49zS+/fv27TJpMbh1zc0zguroWdJh3rX3Z49eyQpupoBrZKfscyKHAqVCIeHh01JUZ40drvKreysCqajo6N6BDFN/ZHnpeWHDh2S7NLY2Gj8gJzruSjSWpuW6d0fGfk0VejPz893v2TwGWvlBKg+jiIxdPbs2erjViUS1VVS8vLy9GXkOMsftnx8WVlZpnqKamEJ+gFqnjP5rFVHsoRp/ZePSWtr6/fff5+ZmSn/ftWuSaiVcKlionOnNQAgcnifFCXE6ClEke8YVSlGDz1dXV02rbPKuSqbPKN6O7wuAmfZBt8nHauOQ/mOzMnJcVVMTqeGniUd6s+oWOBmANoYExV10JyXNBXks2lHeAp7og1tGx/KHqnJy8aJt9JOlV8lRrhfW25urk3royouLp5SM4LAWCtHImPghp6dK2Or6G/8mORvQP7y09LS1LkQ7he27Ds3lvfzsYCL/FRTJ7kaT2Ow/X0t7omJCX0Wi4mkXh+vKAMACGveJ0W9OIiRCj1qjNKmfWfbtOKIlmtQReD0hf3VBh+lpqaqEeQNGzbI7kgykGcsOxT1oWfjq5IC1UFwNQDtHB+NV9QwsjybzTk36N0/kw4USjtV21paWvS2nTx50qZ1E7o/c668vFydy3jx4sUQPMdOr5UTFRUVoPo4ztyUIpd0JVFMPhFVE9v9wgElf283b96UP1T9gs7OpFXyA0laq0+KkkQrP5N27tzpy/m+AIAZICBlREZGRowP3XdWmRaedvJFLt+px48fr6yslG9WNXouX5yHDh0yfc3rBbdN4U/CpbwrOCW4JSZmZWUZ5/S4p4o+GtsmUcamzd128y59TlJXV1fIRgdVK0eSosTEF154IUBb8XyylDpjwdTn7czV7wTLFbrqX3S/knnz5h3UuFpA/qrVxGdPmgEAiCgBSYoJCQnGh5Ko3MydNC0cCuSLU5/+eeHCBdUtJPnv1KlTvb29+mJq6FnSpOWlwIJTgruqqkrFROMVe22uryCcmpqq2qbOJZVb2bWcnBw349rGmBjKA5GqVo4kxeDXxwEAYKbyc1JUA6D6JaQkBcozly9fdl7S4XCYFg5BiZqDBw/W1NQUFhZKJhsaGtKnGJsq6TgLQglu1SNYVlbmYR0TNS1Gkp8kYNk1yb7y5N69e10tHy4x0fa3WjkvvPBC0OrjAAAw4/kzKR47dkzd0Yeb9R6s1tZW09iW6pDzZCKFv+hTVRoaGqZ6rpgEPlNlEzX0LO03lgTSqYAVhAFodVbZnDlzjE9KilUR0JKa1yIRU11RJi4uzjTnWhdGMdH2t1o5jx49Ck59HAAAIoH3SVHyn97BppdItGnDoHoOk1dVSTZ1bpypnqIscOjQoaCd4K+fXlZaWqquZWy5mMQjCV6ScRcsWKDaJg3Wuw9nz56t7hw9etTmul5MZmamZKwgDECryTeVlZVq2o009fr16zt37nRzGRV9XktGRoZNO3PRcrHwiomKHISff/55ulsBAMDM4VNSNFUAsVkNgzY0NDx48EDSzDaN+4WdT/gzTumdtGi2e5LY1MBrvUZ/3rRayXaW5UJsWmZS5/NJIFOtcnVKnN5LF+gBaMmI6kIaps9C9Re6eldNTU1aWpqaCatqhpvIbwD9IJiqq+h8rN4SCGvXrn306FEg1uxmNgkAADOYf0af3dTUUFOJe3p69MtDT2MBjoMHDyYnJx89etRNQRm73Z6QkDAwMKAvExcXl5WVJdlLn/Zx/fp1dUddvs+SymqBHoCWSHrt2rXPP/9ctVY1dcuWLb/88oubpLh8+XJVzFKi80y6pG98fPzTp0+nuxUAAMwc3idFz3v4PK/B4Xm3jauyIJP2/azRuC8porKdm2VkXyZtqn5FQQ8bZmS8quGk1LQb59a62ZzEKTU8LR+i5QLh24UWFRU13U0AAGDmCEiVHIQ4dbWVgoKCkC2OCAAAQgFJMbIMDQ19/PHHfX19MTEx6tp3AAAArpAUI4IEROOUF+erDwMAADgjKUYWdSXrvLw8YiIAAJiUN0nR8yvVIkSE7wwVAAAwjehTBICIY3m1egBwRlIEQoLD4dixY0dzc3NOTo4XF5wEpoRBBvgdPz9mKpIiEBJGR0dV+XS5LSsrIykCAEIBSREICQsWLFAXSZdbuT/dzQEA4P8hKQIhITo6mrliAIBQQ1IEAACANZIiEBAOh6Onp6dZY9Oqna9fvz47O3vNmjXGxUxF0RVXsw3cnzB+69Yt58sztra21tbW9vX12bRqmllZWQUFBfPmzZvq7gAAIhNJEfA/iYlJSUl37tzRnxkfH6/XWOY530kSnT17tqkNkgtVRlTuaCoqKrq6ukyBFQAASyRFwP+qqqokkyUnJ1dWViYmJtq03DY8PHzhwgXTksai6MeOHdu2bZub1Tr3NeqR9Ny5c6aewh07dkhMNLZhZGSkvLy8ubl506ZNN2/epGcRADApkiLgf5LJ5Hbz5s0qotm0CSuJGv9uqLS0VGJidXW1ac3d3d2SCGNiYtrb2/WCO4sWLTpz5ozqWezq6tq6dat/GwMAmHlIioD/qYHgkpKS+Pj4QIw1K8eOHauvr09OTt63b5/ppba2NpuWI53rMm7btq2wsLCzs5OkCACYFEkR8D+JYq2trePj48uWLZMkt2fPHsmLixYt8uMmhoaGJPPFxMScPn3a+dXLly+rZgg/bhQAEGlIioD/SSi8efNmRUVFfX19n8amTT2uqanxy1QSh8OxevVquXPx4kXL0w2Nk2kAAPAaSREICAlwdXV1lZWVg4ODbW1tEhklvaWlpVVXVzsPFk/Vjh07xsfHm5qaXA1tx8TEqAUYYgYA+IKkCARQdHT0Go1ERol3zc3NhYWFPibFmpoaddE/NynwnXfekWUkpJIUAQC+ICkCwSCRsaysTFXh9kV/f79kzZiYmIaGBjeLqUtI19fXy8L+PT8SABBRSIqA/6WkpOzZs0cimj46PDIy8vHHH9u0sxW9Xu3Y2Ni6devkztWrV50nNRulpqaqAeiVK1ceOnQoLS1Nnc4ozbh3797Ro0cltgZuUjYAYMYgKQL+p89iMZH09u233xqfef/99507Go1X7TNW287NzZXwJ3cWL17svPKcnJwzZ86o+5IjJU1KTJTlLat5S1L0dGcAABGMpAj4361btyT/XblyRc+LycnJmzdvzs7Odt8X6J5l+nRl0aJFd+/ebWtrO3XqlLEZSUlJkinpUAQAeIKkCPjfGxpPljyj8XC1zlfzc09S6VbNlN4FAICOpAgAAABrJEUAAABYIykCAADAGkkRAAAA1kiKAAAAsEZSBICIY6zZCQBukBQBILJMtdwSgEhGUgQAAIA1kiIAAACskRQBAABgjaQIAMDM5HA4nK81b/kk4ApJEQCAkHPs2LGffvqpuLjYmOok5O3YsaOsrMzDK8vLwgkJCfv27ZM32rRrwcttUlJSYWHhpFeEHxoa6unpycvLcxMrx8bG5s2b59H+IGyRFAEACDmdnZ2LFi0ypbTh4eHm5ubt27e7eePIyMj58+f1hJeamiq3kvlqa2vb29vl/p07d2bNmjVpA+Qt586dk/Woh5JcJyYmTG8sKSmpq6tbv379FHcO4YSkCACYMskN27Zta2pqmrRrCt558OBBQ0OD6ckLFy7k5OSsWbPGzRslXz5+/HjHjh1nzpzRn5SYeOTIEcmO/f39cXFxnmS7ysrKq1evGqPqwMCAcZ1C/gZUEsUMRlIEAEyZRAR1S1L0r6GhoQULFoyPj5eVlamUJqE8Oztb3W9sbLx48aK+sMPhkCUlGppWsmXLlpUrV+oPW1tbJSaqxSRrFhYWTtqM7u7u/Px89Rb35zVyyuOMR1IEAExZU1OT6lP0eg39/f2lpaVffvmlh6fcuTI2NjZ//ny5U1BQUFdX58uqAm1kZKS6urq+vl7ux8XFSWLTI6Duxo0b//Iv/6LCnGREmxbHJyYm9u3bJ+lNLSDUwp2dnZcuXbp7965pJZLwbt68qT9MTU2VQFlTUyMraW9v7+jo0F9SJz4ePHjQFDfb2tokqtr+dnivXbvm1yOBcEJSBABM2VaNL2sYHh7u6+vzvSXXr1+3aTFRElhlZWXIdnFJMn777bf1h3fu3JEIKFHPNJ5r00Kk8djKYpLw5I7cXrx40RisJUEmJCQYd1mdpKjOJjx16pQcYYmAr7/+ujyUJ1tbW2W7XV1damHZujyUVDo0NGRMivJw+fLlaqqKLCztiY2Nlc/LfwcD4YSkCH/iYrIAgqy2tjYnJ2fz5s2SFAcHB92fwzeN5s6dK+3cu3dvYmKiTRveTUtLa25udu7PsyTLS6Qz9b8ODAykp6cbn5FVqVgpkbGkpERC3uPHj+fMmbNx40ZJfjU1NcnJyXoMlaApy5sSv8PhqKioaGhokDujo6OyEomnKoxKrFTdnIgoJEX4DReTBUKZ/JCTpCIJoKqqqrGxcXx8XEKDfvqaIuGgra2turpaMoE8NCYbZWhoaNmyZfpDWcC5S0xtyG63S3STzCHPGDekpsLoCxvXZvv7/0akMcePH29qalKNKSgokKhkClVjY2N9fX1nz56VRsbExEjjTUlR32t9v6QxlZWV+k6pPZKtSG6TBqsj47wtCWqyBjVwLBvKz8+XZVSvmxqflUx2+/Zt46ZVJ2JZWZlkQZuW4YzHStopL8nx+eWXX5w+KzP1uXg+ti4x8b333rt69Wp5efnOnTslj/7zP//zw4cPJVnKRvXSNs5B06aNO8vyDx482LNnj2TE0tJSPZ6aOjttfztdFTMbSREAIoXkpMWLF0sSUg8lY61cufLmzZsqN0gcycrKMo4IN2u8mOAsG5JoYtqQ8+l07pkaIyntyZMnpmDa0tIitytWrJDb9evXWw5AS+gxrkrurFu3Tt9rZXBwsKSkRG+wrGd4eLi3t1c9lDQpOVJfWBaThNfe3q6ioaxHwqgcKFnM2Od34cIFmza5xNUOPn782MNDIY2R/ZLoKfeNwd2SxEQJiB0dHfoOSlSdM2eOhF116qEcRvWSHBl1iqdRdnZ2fHy87IgEytraWtmuh43ETEVSBIBIIQEuJibm7NmzqrJJVVWVJB4JW2q8sq2tTVKU3v8nwbGnp2fDhg3btm2TnKSyhQQI1e1n6lx03pDcyoYkvUngyM3NlTWPjo5KhtNPcFSdi7du3bKc0SLrl7cUFBSo5CeNkTBn6rSzaRNrpMGqbRJxJOFJm00lYGQ9steypCwgD0tLS2Wx69evG5OiPBMXF/fNN9+sWbNGGpyRkSHvksildytKxsrMzFQpTZ7/6KOPZAE9Gu7du1elan1f1BiuJEhXI8uyQGtrqzTMefclwMmajc+o7cptSkqKtMTNCLvEwf/93/9VeVp2JCEhYcGCBTbtHEd5SeW/rq4utVHZhS+//NK0hmiN3CkqKlKFdVxtCxGCpAgAEeTq1at6dikuLpY0MzAwoB5WV1fLbXt7uwoHciuRS54sLCwcHh6e6qU4JI6oQCNv3Lx5s4SSGzdueD7Nefbs2XJ7+fJllS/FGo1xGUlsEklVs8Xy5ctt2mmLpqQoacy41zt37pRcODExYVxG4qa+49Jg2WVJsfq48BsafWFZldoj/RnJcBI0Gxsb1UCzTeuktGkJ0tUOSmAdHx+f6pxiiYmbNm1y0zsbGxurf1KShiVnb9y4UUVt/ePo7OyUsC5HT+2a5Xokx7uJuYgoJEUAiCDG736VNpqbm1UXlKQuCQemCKJ6H+/fvz/VDfk4s0QCjWTNtLS0ZcuWSQiT3LZ27VpTcDl//rzcyvPqobRczYA2XWLunXfeMb5R7xY1kuRn3HHnmd2tra2SQd1M1lbhsru7W+24RHBptquR4vLycmmn7KDlAi+//LKrAPfqq69Kvnz69KmrpCiflD61WTL0H/7wB/WwpKRE9ZiqlyQ4Dg0NycdtuRLZC0m6EqlVD+Xvfvc79Ubnzk5EApIiAEQ0CTTT3QRrkk4k91y/fl0iWqHGVDFRVXNcvHix6Y2mkWXf1dTUTFqtOjs7W5KimlKjz7NxXkwimhr+1vtcp0Qi77Vr19zsXWxs7Pz582UBiXRz585Vp1rK/d///veqz9WmzUNSF/fbs2eP8xpGRkbUSZlz5szJzMwM2bnkCBqSIgBEKNU/tGrVKvUwJibm0qVLpgtyNDc327T8EaA2/Pzzz25enadRJzsWFRVJwJJAprKLGnq2fJfzALSPVEyUiKZ3AZpmcNu0Hk01l1luW1pa5GA6X+ZOnzPkXUxUTN2Qpgsx62cZSkv0cxDlvoRd/WNdsWKFmm+kLgNtosKofOLO3ZZuOjsxg5EUASCC6LM0+vv7P/roI5vWGaZeys/Pl0ghUcY4o0WekdATiKSoIk5paenp06edO8laW1u///77nJwcFU2ioqLS09Mlturj4Gro2ZjelJSUFIlipgFo38lBUNOEZc3Dw8P6yZFG0lo5XJICm5qa5GCakpaqXPPw4UNfYqKJJHs1ndlEGimHq0fz+PHjBw8eGLcoB9OmnZrpagjbeEhlVdevXycgRjKSIgBEENNYrXEibXFxcWNjo8Qs0zLnzp3TI4WpL01N+LW5KKzo3ooVKyR+yeaMhVr0MwgnJiYqNMa3yPJ6tRpJY/LQ+Ty/PXv2yDr9OwAdFxd3584d54IyJhKn1CmVcv/bb781vVpeXq46QY0FdxSvi9HqZX1MZN/1Ceby8T169Gjp0qXSJPUDQH4MSJCVz1qapE/BMVJpWM3+lsSpLjl4+fJl7xqJcEdSBIBIlJycbKq3Imng7t27el1um4ti1/4iaebixYt1dXWqnLWJpJNZs2bpk0gkgUm+0Ytdq6Fny+401fvl3wHojo4OyazG6zXHxsYaL82nq6mpkSAox9aXg+b+Uiitra1q5erqz6oIjjM1Xp+QkKDmdMsKJRfa7fbc3FwJ03JwtmzZsnLlSjmSchiNXYZqbrjspuyLZY50JmvWSwhh5iEpAkAEcd99JZHioMbVAp5c7tl5E67eJQGlTmPZkvUay01IVHK1I6aXJu2us5wKbSLx1Lmdlu9SFR8tI+wZjfsNKaZLoZSUlBhfTU1NbWtrUz2XsiHnEWTJiC0tLY8fP5ZcqHesygol3Ure1S+WI7dXr16VsNjc3KxfSEatc/Xq1fqRV1fKkdT+008/zZ492xRhc3JyJFBK3Dx16pTlqY2YAUiKAAD4Sl1wr7CwMDk52ZfTEOPj403D03fv3jU+VNXL1Vmezkm6u7s7KioqLy/PGNqGhobU+ammsCvPyMpNF8tWs4iMm1OF2S1N9eI9CEckRQAAvGc8dzMmJubIkSO+rM157ohlR52r3lbLkLpgwQJXU1JUSfMpthGRhaQIAICvJCPm5+frZ1KGFAaF4QuSIgBEBK8n2MI9T87dBMIXSREAAADWSIoAAACwRlIEAACANZIiAMB7Pl43z3SZ6bDjY/vDffcRCUiKAIC/M6Xwd//+/YyMDHWlOC+2dfz48cePHxcXF3sYmLq7uz2p6iKLxcbGutqLnTt3Ll++3DQNpb+//8KFC1OdvDw6OpqUlHTkyBHvrlDS1tbW2dlpLJENhBqSIgBEEIfDIeHGzQIjIyMbNmzo6urysMzeSy+9FBcXZ4yJsomqqioPC1DPmjVLkqLn/WpHjx7t6+t7/fXX9Wd++uknWYMkP+NiJSUlpaWlrkpG19fXZ2dnm54cGBhobGzcsmWLhy3R3blzR1LpVN+lqEubOMdEOYbDw8NcHw+hgKQIABFEMllPT88//uM/SsKzXEAy361btyxfUhHQmNJsWlBzvk6xLHP//n0Ph1ZNK5xUTk6OsY60bFrSramDsLOzMzU11fLtsnBBQYFzim1qajp06JB3PaOe7GZra+vExITxGXkoqVeSovNVniVBykue53UgcEiKABBZXF3eY1LqqtCmJ9WV4vSgJulQkqjXm9D5ePqjpf7+/sTERGmwui6zuv6earnswsOHD40djfJMTEyMKQJ6mH0tG79ixYqoqCjj28vLyyX1Wl72mgKNCB0kRQDAFNTU1Dx+/FjvCDT1KcpDyVhvvPGG551z8hZJb8Znfv7553Xr1uXn5zsHU198rklPT+/q6lLbraioiI2Nlfh48uTJP/zhDxIc9YWrq6vj4uLOnDljXIOE4NHRUXXNZb3xNq1f07iYGlM2RUBTdpTQ2djYePHiRf/tHxAQJEUAgAVX/Wemk/9MfYqml1xdbti9l156SUUov08NlpioN1W1XGLi2NiYhLa7d+8atyVpb+/evaa3T0xMSEw07qysROKm89j34sWL3bekqqpK9byaUrJNC8qSaBsaGpgWjVBAUgQAmJWXl1+5cqW9vV2FFTVQa7mk5XmKYnBwsLW19erVq5N2Lr7++utTCpTNzc03btzQH0osc26APOP5Cuvr6yWYmmJZX1+fq1M5jR48eJCcnOz8vLHf0USC6f3791U2tTxntLS09L//+7/lAHKSIkIBSREAIkJ3d/fRo0fT09P1Z7Zt25aTk6OeUXmrsLBQvfS6Rp9+Kylq1apVL774onEIVVa4adMmyVhqjNh0ct7WrVstz8DznWlGi74540PZHQ/XNjQ0NNWoanT79u2kpKQpveXJkydvv/32tWvX5Kg6n9ApGX3z5s3Z2dl0KCJEkBQBICKs0RifkaS4d+9eYykWNxMpjF2DEgrr6+slYN28eVOlQ4fDkZubK3d6e3v93vKAevDggex1a2vrlM6t1DU1NUmGntI4e09Pj9w6V8CRNoyOjlrmYGAakRQBIHJ5MsBqcuzYMVWtUO7rU0MaGxvlmby8vEnfLnloxYoVbuY1S+pqbm52NZfl0qVLauayd4yzZ0ZGRmxagJbb1NTUxYsXezJWbtTd3S23dXV15eXlcltZWTlpR2B/f78sZvmS7LXcenIMgWAiKQJAJFKBacGCBVN946pVq/Lz8xMSElS56aqqKolcqnNRUqBELvdpqVljHAS3/f3c4c7OTomDW7ZssQxt4+PjU22wJ6TNslMS+EyTnd1wOBz79u07cuSI3JdcK++dNGvKgfr888/PnTv39ttvWy4gh0U/erJ+m2eVGoGAIikCQCSS1BIXF+dFEJEkJMFIzXEZHBzcuXOnPloqdzy5tJ1xArKbrbh6qaenx+sZLW5OSXzrrbfa29vdt8pIIvKBAwf0PS0uLr5y5crKlSsfPnxoubwccEmTDQ0N+jVyTLOeHzx4YOzy/Pjjj+VWn1QETBeSIgBEoosXL2ZlZblfxvn0O3WVuQsXLjQ2Nh46dEhi4g2NTRvYlRwm61TTNQJxJTo1Xmx5jT6vZ7ToUlNTPR96lsxnulyh5Lkvv/xy2bJllstLy0+ePKkK3+hJ8cUXX/zll19cbULWJrdPnz4lKWJ6kRQBIOKoKSmurtqnkwhoSooSXNTIaU5OzsTEhASgWbNm1dbWmiayBOiaxffu3ZPt+n21SrTG+IwkOefFJBAfO3bMcnBcjpU6cdOZrMr5zEvTGl5++WVfZmEDAUJSBICIIzFx0jm26jw5k3nz5t29e1dyj6whLy9PotXQ0JBEHJvWAfnzzz9LQCwuLg5Qs/v6+gKXFI1U56VlF+OcOXPcDJ27qoDo9ysTAkFDUgSAyNLd3d3Y2Hjz5k33i42OjnZ2djqnopiYmKysrEePHmVmZho7DiV3Slh8//3309PT09LSAjFmeuXKlcDFUCM3g8JuSmoDMxJJEQAiiMTEffv2Xb161bmX686dO3r1bIfD0dzcfOnSpZGREWPXmjwvMXHz5s2W/WoSFhsaGkpLS7dt29bU1OSq7839SYSuXu3v75ftugmg0jb9FEBXxXSMK1eXbDa+vaenR+1sXV2d5ZVX3JBD9+TJEzWXXI5kcPo+gSAgKQJApDh27JjEoytXrjjnrVWrVlVXV8+fP9/4ZEFBQUxMjP5waGhIItSRI0ckTqmLJkualFQUFxenLyNrlmXmzJkjYdFVUpx07rNlWLxw4YKrDsXZs2erTY+Pj588ebKiokJ/0s2m1e4YW75ixQp5b319ve1vpSI9FxUVdf/+/R07dqiyiJ6fbqiuHG3T6geRLxGCSIoAMPNJqrt8+XJ8fLyriCbh7/bt227W0N/f/9JLL+nR6g3N7373u02bNv3Hf/yHaWGJdBIWXW1ImuFmQ5JWt2/fbnpS4tSWLVssOxTT0tL0nVIVfF5//XVZiXOn6d69e1UNSGXBggWm6w3KW+SZxYsXJyQkuJqRY1yDkbQtUSNtSE5Odj+NWiK4fl8O45kzZ1pbWyXapqamunkXMC1IigAw8y3S+LIGy+S0Zs0ay/KBEpssa9nYtCLV7jdkOSnETRedcyJ0lYZNu+BqINtVy92s2WjSHZR9cb4i9nrNpCsHgo+kCAAAAGskRQAAAFgjKQIAAMAaSREAAADWSIoAAACwRlIEAACANZIiAAAArJEUAQAAYO3/APbsrPhLa3LgAAAAAElFTkSuQmCC)

- 移动构造函数

![](data:image/png;base64,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qkP8jgytnvoeoh5ZtGhRdHS0JMgffvihZ8+eklnVFQZWr14tEx0XKIlK3dH3JUhNTVVzOh19QE/ruuCFyMhIlVYVv8msPXr0eO211+TTqYcrVqx44oknlixZ8vzzzwcFBZlbNgBAACKtlpoLFy5cf/315f++6tz2kpBoJRnLMFFdul8yq2H6V199VdRykpKS5LZJkya2vzoMqL4E8pLPP//c9RF5/fI7dOhw9OhRyZGNGjWaNGmS6nW6cuXKadOmefCp7FRUdTou1/r16y9evKifLlkzMzPT/YVfunTJcaI+s/porb137976h/fcc4/8QzZv3ixp1awiAdBzvBTgvHnzhg4dWqFCBa+XOXbs2C5dusj67rpSKu8i27e+ffvq32v58uXbt2+fPHnyDTfc4HWddtiwYRMnTizJEuDHLJFWW7duPX78+B49eqiH33///VNPPZWQkPC3v/2thEtetmzZDz/88MQTT8gK4N0S1q1b17Bhw2JLImWOiYmRmWVV9+6NvLZkyZISLqFbt26GtDpw4EBJ3hIQk5OTDW2Tx44dK6rbwIkTJySkqrSqJz/B6dOn3SmJGhm1QYMGklZVMbTpERERd999d3Z2tgRfT4eElZh78OBBQ/KWlF+7dm39or744ouNGzd6tOSiSGDdvXv3jTfeWCpLM8W+ffvkI0gdzMZ1oADLyMjIkJp8SkrKhAkTZPOlIqOERdlpRkZGPvjgg15HvV27dsmG+q677qpYsaKL2WQX8Oeff/bp00c/UcqTmpoq223Xu1oJxP/85z8NeVQ2NbL3lClpaWmrV6+WGUircGSJtPrdd9/pI9GhQ4eOHDni2KrnnS+//HLkyJFev/zixYtjxoxZsWKFi3ZT2aPLqispLTg4WF19SaxZs0YiYDmE11dffbWES6hevbphilQe2rdvL3feffddw1NOL3Gq0foP6K8JUFTnAUdJSUmSLLU31Y77v/HGG4mJiTZ7W6lqo/U0sPbq1cvQsUE+yH333aef0rt3b61fgTveeeed//mf/3GcXqVKle7du8vSvGgMtgLZeYwePVqdwVarVi25zczMVHcAlL+cnBwJgp988slXX30l9/v37z9x4sRWrVppqW7RokWyOerRo4c2RUJtVFSUi9gnq/kHH3wwY8YMfTYtanBBg/r16xumSP28X79+d999t+ugefvtt3fu3Fky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)

- 移动构造函数: class_name ( class_name && ) //&& 右值引用
- 什么时候该触发移动构造？
  - 有可被利用的临时对象

### 字符串

#### 1.同C

#### 2.string类

> #include < string >

- string(); //默认构造函数，建立一个长度为0的串
  - 例：string s1;

- string(const char *s); //用指针s所指向的字符串常量初始化string对象
  - 例：string s2 = “abc”;

- string(const string& rhs); //复制构造函数
  - 例：string s3 = s2;

**上面的只用看例子就会懂了**

**下面是基本操作(笑)**

- s + t 将串s和t连接成一个新串
- s = t 用t更新s
- s == t 判断s与t是否相等
- s != t 判断s与t是否不等
- s < t 判断s是否小于t（按字典顺序比较）
- s <= t 判断s是否小于或等于t （按字典顺序比较）
- s > t 判断s是否大于t （按字典顺序比较）
- s >= t 判断s是否大于或等于t （按字典顺序比较）
- s[i] 访问串中下标为i的字符

> 例：
>
> string s1 = "abc", s2 = "def";
>
> string s3 = s1 + s2; //结果是"abcdef"
>
> bool s4 = (s1 < s2); //结果是true
>
> char s5 = s2[1]; //结果是'e'

#### 输入整行字符串

- getline可以输入整行字符串（要包string头文件），例如：
  - getline(cin, s2);

- 输入字符串时，可以使用其它分隔符作为字符串结束的标志（例如逗号、分号），将分隔符作为getline的第3个参数即可，例如：
  - getline(cin, s2, ',');
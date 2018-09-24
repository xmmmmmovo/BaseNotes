# C++(进阶教学 · A)

[TOC]

## 继承和派生

- 基类
- 派生类
- 直接基类
- 间接基类

- 语法

> class 派生类名：继承方式 基类名
>
> {
>
> 成员声明；
>
> }
>
> //多继承类似

### 继承方式

#### 共有继承(public) 

***注 ：public就完事儿了***

- 继承的访问控制
  - 基类的public和protected成员：访问属性在派生类中保持不变；
  - 基类的private成员：不可直接访问。
- 访问权限
  - 派生类中的成员函数：可以直接访问基类中的public和protected成员，但不能直接访问基类的private成员；
  - 通过派生类的对象：只能访问public成员。

#### 私有继承(private)

- 继承的访问控制
  - 基类的**public**和**protected成员：都以private**身份出现在派生类中；
  - 基类的private成员：**不可直接访问**。
- 访问权限
  - 派生类中的成员函数：可以直接访问基类中的public和protected成员，但不能直接访问基类的private成员；
  - 通过派生类的对象：不能直接访问从基类继承的任何成员。

#### 保护继承(protected)

- 继承的访问控制
  - 基类的**public**和**protected成员：都以protected**身份出现在派生类中；
  - 基类的**private**成员：**不可直接访问**。
- 访问权限
  - 派生类中的成员函数：可以直接访问基类中的public和protected成员，但不能直接访问基类的private成员；
  - 通过派生类的对象：不能直接访问从基类继承的任何成员。
- protected 成员的特点与作用
  - 对建立其所在类对象的模块来说，它与 private 成员的性质相同。
  - 对于其派生类来说，它与 public 成员的性质相同。
  - 既实现了数据隐藏，又方便继承，实现代码重用。
  - 如果派生类有多个基类，也就是多继承时，可以用不同的方式继承每个基类。

### 类型转换

- 公有派生类对象可以被当作基类的对象使用，反之则不可。
  - 派生类的对象可以隐含转换为基类对象；
  - 派生类的对象可以初始化基类的引用；
  - 派生类的指针可以隐含转换为基类的指针。
- 通过基类对象名、指针只能使用从基类继承的成员。

- 举例

  ```c++
  ** 定义文件 **
  #include <iostream>
  using namespace std;
  class Base1 { //基类Base1定义
  public:
      void display() const {
          cout << "Base1::display()" << endl;
      }
  };
  class Base2: public Base1 { //公有派生类Base2定义
  public:
      void display() const {
          cout << "Base2::display()" << endl;
      }
  };
  class Derived: public Base2 { //公有派生类Derived定义
  public:
      void display() const {
          cout << "Derived::display()" << endl;
      }
  };
  
  ** 实现文件 **
  void fun(Base1 *ptr) {  //参数为指向基类对象的指针
      ptr->display();     //"对象指针->成员名"
  }
  int main() {    //主函数
      Base1 base1;    //声明Base1类对象
      Base2 base2;    //声明Base2类对象
      Derived derived;    //声明Derived类对象
  
      fun(&base1);    //用Base1对象的指针调用fun函数
      fun(&base2);    //用Base2对象的指针调用fun函数
      fun(&derived); //用Derived对象的指针调用fun函数
  
      return 0;
  }
  /*
  
  最后都等同于 base1.display()
  */
  ```

### 派生类的构造函数

- 默认情况
  - 基类的构造函数不被继承;
  - 派生类需要定义自己的构造函数。
- C++11规定
  - 可用using语句继承基类构造函数。
  - 但是只能初始化从基类继承的成员。
    - 派生类新增成员可以通过类内初始值进行初始化。
  - 语法形式：
    - using B::B;

#### 建议

- 如果派生类有自己新增的成员，且需要通过构造函数初始化，则派生类要自定义构造函数。

#### 若不继承基类的构造函数

- 派生类新增成员：派生类定义构造函数初始化；
- 继承来的成员：自动调用基类构造函数进行初始化；
- 派生类的构造函数需要给基类的构造函数传递参数。

### 单继承

- 派生类只有一个直接基类的情况，是单继承。单继承时，派生类的构造函数只需要给一个直接基类构造函数传递参数

> 派生类名::派生类名(基类所需的形参，本类成员所需的形参):
> 基类名(参数表), 本类成员初始化列表
> {
> 	//其他初始化；
> }；

```c++
#include<iostream>
using namespace std;
class B {
public:
    B();
    B(int i);
    ~B();
    void print() const;
private:
    int b;
};

B::B() {
    b=0;
    cout << "B's default constructor called." << endl;
}
B::B(int i) {
    b=i;
    cout << "B's constructor called." << endl;
}
B::~B() {
    cout << "B's destructor called." << endl;
}
void B::print() const {
    cout << b << endl;
}

class C: public B {
public:
    C();
    C(int i, int j);
    ~C();
    void print() const;
private:
    int c;
};
C::C() {
    c = 0;
    cout << "C's default constructor called." << endl;
}
C::C(int i,int j): B(i), c(j){
    cout << "C's constructor called." << endl;
}

C::~C() {
    cout << "C's destructor called." << endl;
}
void C::print() const {
    B::print();
    cout << c << endl;
}

int main() {
    C obj(5, 6);
    obj.print();
    return 0;
}
```

### 多继承

- 多继承时，有多个直接基类，如果不继承基类的构造函数，派生类构造函数需要给所有基类构造函数传递参数。我们来看一下语法规定

#### 多继承时构造函数的定义语法

```c++
派生类名::派生类名(参数表) : 
基类名1(基类1初始化参数表), 
基类名2(基类2初始化参数表), 
...
基类名n(基类n初始化参数表), 
本类成员初始化列表
{
        //其他初始化；
}；
```

### 派生类与基类的构造函数

- 当基类有默认构造函数时
  - 派生类构造函数可以不向基类构造函数传递参数。
  - 构造派生类的对象时，基类的默认构造函数将被调用。
- 如需执行基类中带参数的构造函数
  - 派生类构造函数应为基类构造函数提供参数。

### 多继承且有对象成员时派生的构造函数定义语法

```c++
派生类名::派生类名(形参表):
基类名1(参数), 基类名2(参数), ..., 基类名n(参数), 
本类成员（含对象成员）初始化列表
{
        //其他初始化
}；
```

#### 举例

```c++
#include <iostream>
using namespace std;
class Base1 {//基类Base1，构造函数有参数
public:
    Base1(int i) 
  { cout << "Constructing Base1 " << i << endl; }
};
class Base2 {//基类Base2，构造函数有参数
public:
    Base2(int j) 
  { cout << "Constructing Base2 " << j << endl; }
};
class Base3 {//基类Base3，构造函数无参数
public:
    Base3() 
  { cout << "Constructing Base3 *" << endl; }
};

class Derived: public Base2, public Base1, public Base3 {
public: 
    Derived(int a, int b, int c, int d): Base1(a), member2(d), member1(c), Base2(b)
  //此处的次序与构造函数的执行次序无关
    { }
private:
    Base1 member1;
    Base2 member2;
    Base3 member3;
};

int main() {
    Derived obj(1, 2, 3, 4);
    return 0;
}

/*
基类的构造函数先执行
并且按照继承顺序执行
成员对象后执行
*/
```

### 构造函数的执行顺序

1. 调用基类构造函数。
   - 顺序按照它们被继承时声明的顺序（从左向右）。
2. 对初始化列表中的成员进行初始化。
   - 顺序按照它们在类中定义的顺序。
   - 对象成员初始化时自动调用其所属类的构造函数。由初始化列表提供参数。
3. 执行派生类的构造函数体中的内容。

### 派生类复制构造函数

#### 派生类未定义复制构造函数的情况

- 编译器会在需要时生成一个隐含的复制构造函数；
- 先调用基类的复制构造函数；
- 再为派生类新增的成员执行复制。

#### 派生类定义了复制构造函数的情况

- 一般都要为基类的复制构造函数传递参数。
- 复制构造函数只能接受一个参数，既用来初始化派生类定义的成员，也将被传递给基类的复制构造函数。
- 基类的复制构造函数形参类型是基类对象的引用，实参可以是派生类对象的引用
- 例如: C::C(const C &c1): B(c1) {…}

### 派生类的析构函数

- 析构函数不被继承，派生类如果需要，要自行声明析构函数。
- 声明方法与无继承关系时类的析构函数相同。
- 不需要显式地调用基类的析构函数，系统会自动隐式调用。
- 先执行派生类析构函数的函数体，再调用基类的析构函数。

#### 举例

```c++
#include <iostream>
using namespace std;
class Base1 {   
public:
    Base1(int i) 
   { cout << "Constructing Base1 " << i << endl; }
    ~Base1() { cout << "Destructing Base1" << endl; }
};
class Base2 {
public:
    Base2(int j) 
   { cout << "Constructing Base2 " << j << endl; }
    ~Base2() { cout << "Destructing Base2" << endl; }
};
class Base3 {
public:
    Base3() { cout << "Constructing Base3 *" << endl; }
    ~Base3() { cout << "Destructing Base3" << endl; }
};

class Derived: public Base2, public Base1, public Base3 {
public: 
    Derived(int a, int b, int c, int d): Base1(a), member2(d), member1(c), Base2(b)
  { }   
private:    
    Base1 member1;
    Base2 member2;
    Base3 member3;
};

int main() {
    Derived obj(1, 2, 3, 4);
    return 0;
}
```

### 访问从基类继承的成员

#### 作用域限定

- 当派生类与基类中有***相同(变量名)成员***时：
  - 若未特别限定，则通过派生类对象使用的是***派生类中的同名成员***。
  - 如要通过派生类对象访问基类中被隐藏的同名成员，应使用基类名和作用域操作符（::）来限定。

#### 二义性问题

- 如果从不同基类继承了同名成员，但是在派生类中没有定义同名成员，“**派生类对象名或引用名.成员名**”、“**派生类指针->成员名**”访问成员存在二义性问题
- 解决方式：用类名限定

![Derived类对象d的存储结构示意图](http://www.xuetangx.com/asset-v1:TsinghuaX+00740043_2x_2015_T2+sp+type@asset+block/ambigous.png)

### 虚基类

- 需要解决的问题
  - 当派生类从多个基类派生，而这些基类又共同基类，则在访问此共同基类中的成员时，将产生冗余，并有可能因冗余带来不一致性
- 虚基类声明
  - 以virtual说明基类继承方式
  - 例：class B1:virtual public B
- 作用
  - 主要用来解决多继承时可能发生的对同一基类继承***多次而产生的二义性***问题
  - 为最远的派生类提供唯一的基类成员，而不重复产生多次复制
- 注意：
  - 在第一级继承时就要将共同基类设计为虚基类。

#### 虚基类举例

![img](http://www.xuetangx.com/asset-v1:TsinghuaX+00740043_2x_2015_T2+sp+type@asset+block/virtual-base.png)

#### 虚基类及其派生类构造函数

- 建立对象时所指定的类称为**最远派生类**。
- 虚基类的成员是由最远派生类的构造函数通过调用虚基类的构造函数进行初始化的。
- 在整个继承结构中，直接或间接继承虚基类的所有派生类，都必须在构造函数的成员初始化表中为虚基类的构造函数列出参数。如果未列出，则表示调用该虚基类的默认构造函数。
- 在建立对象时，只有最远派生类的构造函数调用虚基类的构造函数，其他类对虚基类构造函数的调用被忽略。

### 小结

- 虚基类
  - 在可控项目规模下 虚基类可用
  - 写公共类库软件包的时候 ***慎用虚基类***
- 主要理解面向对象的特点
- 主要理解构造析构函数的构建析构顺序

## 多态性

### 运算符重载

- C++ 几乎可以重载全部的运算符，而且只能够重载C++中已经有的。
- 不能重载的运算符：“.”、“.*”、“::”、“?:”
  - 重载之后运算符的优先级和结合性都不会改变。
- 运算符重载是针对新类型数据的实际需要，对原有运算符进行适当的改造。例如：
  - 使复数类的对象可以用“+”运算符实现加法；
  - 是时钟类对象可以用“++”运算符实现时间增加1秒。
- 重载为类的非静态成员函数；
- 重载为非成员函数。

### 双目运算符重载作为成员函数

#### 形式

> 函数类型 operator 运算符(形参)
>
> {
>
> }
>
> 参数个数 = 源操作个数 - 1 (后置++ 、--除外)

#### 规则

- 如果要重载 B 为类成员函数，使之能够实现表达式 oprd1 B oprd2，其中 oprd1 为A 类对象，则 B 应被重载为 A 类的成员函数，形参类型应该是 oprd2 所属的类型。
- 经重载后，表达式 oprd1 B oprd2 相当于 oprd1.operator B(oprd2)

#### 举例：复数类加减法运算重载为成员函数

- 要求:

  - 将+、-运算重载为复数类的成员函数。

- 规则:

  - 实部和虚部分别相加减。

- 操作数:

  - 两个操作数都是复数类的对象。

#### 源代码：

  ```c++
  #include <iostream>
  using namespace std;
  class Complex {
  public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) { }
      //运算符+重载成员函数
    Complex operator + (const Complex &c2) const;
      //运算符-重载成员函数
    Complex operator - (const Complex &c2) const;
      void display() const;   //输出复数
  private:
      double real;    //复数实部
      double imag;    //复数虚部
  };
  例8-1复数类加减法运算重载为成员函数
  Complex Complex::operator+(const Complex &c2) const{
    //创建一个临时无名对象作为返回值 
    return Complex(real+c2.real, imag+c2.imag); 
  }
  
  Complex Complex::operator-(const Complex &c2) const{
   //创建一个临时无名对象作为返回值
      return Complex(real-c2.real, imag-c2.imag); 
  }
  
  void Complex::display() const {
      cout<<"("<<real<<", "<<imag<<")"<<endl;
  }
  例8-1复数类加减法运算重载为成员函数
  int main() {
      Complex c1(5, 4), c2(2, 10), c3;
      cout << "c1 = "; c1.display();
      cout << "c2 = "; c2.display();
      c3 = c1 - c2;   //使用重载运算符完成复数减法
      cout << "c3 = c1 - c2 = "; c3.display();
      c3 = c1 + c2;   //使用重载运算符完成复数加法
      cout << "c3 = c1 + c2 = "; c3.display();
      return 0;
  }
  ```

### 单目运算符重载为成员函数

#### 前置单目运算符重载规则

- 如果要重载 U 为类成员函数，使之能够实现表达式 U oprd，其中 oprd 为A类对象，则 U 应被重载为 A 类的成员函数，无形参。
- 经重载后，表达式 U oprd 相当于 oprd.operator U()

#### 后置单目运算符 ++和--重载规则

- 如果要重载 ++或--为类成员函数，使之能够实现表达式 oprd++ 或 oprd-- ，其中 oprd 为A类对象，则 ++或-- 应被重载为 A 类的成员函数，且具有一个 int 类型形参。
- 经重载后，表达式 oprd++ 相当于 oprd.operator ++(0)

#### 重载前置++和后置++为时钟类成员函数例子

- 前置单目运算符，重载函数没有形参

- 后置++运算符，重载函数需要有一个int形参

- 操作数是时钟类的对象。

- 实现时间增加1秒钟。

#### 源代码：

  ```c++
  #include <iostream>
  using namespace std;
  class Clock {//时钟类定义
  public: 
      Clock(int hour = 0, int minute = 0, int second = 0);
      void showTime() const;
    //前置单目运算符重载
      Clock& operator ++ ();
    //后置单目运算符重载
      Clock operator ++ (int);    
  private:
      int hour, minute, second;
  };
  
  Clock::Clock(int hour, int minute, int second) {    
      if (0 <= hour && hour < 24 && 0 <= minute && minute < 60
          && 0 <= second && second < 60) {
          this->hour = hour;
          this->minute = minute;
          this->second = second;
      } else
          cout << "Time error!" << endl;
  }
  void Clock::showTime() const {  //显示时间
      cout << hour << ":" << minute << ":" << second << endl;
  }
  
  例8-2重载前置++和后置++为时钟类成员函数
  Clock & Clock::operator ++ () { 
      second++;
      if (second >= 60) {
          second -= 60;  minute++;
          if (minute >= 60) {
            minute -= 60; hour = (hour + 1) % 24;
          }
      }
      return *this;
  }
  
  Clock Clock::operator ++ (int) {
      //注意形参表中的整型参数
      Clock old = *this;
      ++(*this);  //调用前置“++”运算符
      return old;
  }
  例8-2重载前置++和后置++为时钟类成员函数
  int main() {
      Clock myClock(23, 59, 59);
      cout << "First time output: ";
      myClock.showTime();
      cout << "Show myClock++:    ";
      (myClock++).showTime();
      cout << "Show ++myClock:    ";
      (++myClock).showTime();
      return 0;
  }
  ```



### 运算符重载为非成员函数

有些运算符不能重载为成员函数，例如二元运算符的左操作数不是对象，或者是不能由我们重载运算符的对象

#### 运算符重载为非成员函数的规则

- 函数的形参代表依自左至右次序排列的各操作数。
- 重载为非成员函数时
- 参数个数=原操作数个数（后置++、--除外）
- 至少应该有一个自定义类型的参数。
- 后置单目运算符 ++和--的重载函数，形参列表中要增加一个int，但不必写形参名。
- 如果在运算符的重载函数中需要操作某类对象的私有成员，可以将此函数声明为该类的友元。

#### 运算符重载为非成员函数的规则

- 双目运算符 B重载后，表达式oprd1 B oprd2 等同于operator B(oprd1,oprd2 )

- 前置单目运算符 B重载后，表达式 B oprd 等同于operator B( oprd )

- 后置单目运算符 ++和--重载后，表达式 oprd B等同于operator B( oprd,0 )

#### 例8-3 重载Complex的加减法和“<<”运算符为非成员函数

- 将+、-（双目）重载为非成员函数，并将其声明为复数类的友元，两个操作数都是复数类的常引用。 

- 将<<（双目）重载为非成员函数，并将其声明为复数类的友元，它的左操作数是std::ostream引用，右操作数为复数类的常引用，返回std::ostream引用，用以支持下面形式的输出：

```c++
cout << a << b;
```

**该输出调用的是：**

```c++
operator << (operator << (cout, a), b);
```

#### 源代码：

```c++
    //8_3.cpp
    #include <iostream>
    using namespace std;

    class Complex {
    public:
        Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) { }  
        friend Complex operator+(const Complex &c1, const Complex &c2);
        friend Complex operator-(const Complex &c1, const Complex &c2);
        friend ostream & operator<<(ostream &out, const Complex &c);
    private:    
        double real;  //复数实部
        double imag;  //复数虚部
    };

	//传递const修饰的引用 效率高并且不易出错
    Complex operator+(const Complex &c1, const Complex &c2){
        return Complex(c1.real+c2.real, c1.imag+c2.imag); 
    }
    Complex operator-(const Complex &c1, const Complex &c2){
        return Complex(c1.real-c2.real, c1.imag-c2.imag); 
    }

    ostream & operator<<(ostream &out, const Complex &c){
        out << "(" << c.real << ", " << c.imag << ")";
        return out;
    }

    int main() {    
        Complex c1(5, 4), c2(2, 10), c3;    
        cout << "c1 = " << c1 << endl;
        cout << "c2 = " << c2 << endl;
        c3 = c1 - c2;   //使用重载运算符完成复数减法
        cout << "c3 = c1 - c2 = " << c3 << endl;
        c3 = c1 + c2;   //使用重载运算符完成复数加法
        cout << "c3 = c1 + c2 = " << c3 << endl;
        return 0;
    }
```



### 虚函数

#### 初识虚函数

- 用virtual关键字说明的函数
- 虚函数是实现运行时多态性基础
- C++中的虚函数是动态绑定的函数
- 虚函数必须是非静态的成员函数，虚函数经过派生之后，就可以实现运行过程中的多态。
- 一般成员函数可以是虚函数
- 构造函数**不能**是虚函数
- 析构函数**可以**是虚函数

#### 一般虚函数成员

- 虚函数的声明

  > virtual 函数类型 函数名（形参表）;

- 虚函数声明***只能出现在类定义中的函数原型声明中***，而**不能**在成员函数实现的时候。

- 在派生类中可以对基类中的成员函数进行覆盖。

- 虚函数一般不声明为内联函数，因为对虚函数的调用需要动态绑定，而对内联函数的处理是静态的。

#### virtual 关键字

- 派生类可以不显式地用virtual声明虚函数，这时系统就会用以下规则来判断派生类的一个函数成员是不是虚函数：
  - 该函数是否与基类的虚函数有相同的名称、参数个数及对应参数类型；
  - 该函数是否与基类的虚函数有相同的返回值或者满足类型兼容规则的指针、引用型的返回值；
- 如果从名称、参数及返回值三个方面检查之后，派生类的函数满足上述条件，就会自动确定为虚函数。这时，派生类的虚函数便覆盖了基类的虚函数。
- 派生类中的虚函数还会隐藏基类中同名函数的所有其它重载形式。
- 一般习惯于在派生类的函数中也使用virtual关键字，以增加程序的可读性。

#### 虚析构函数

- 为什么需要虚析构函数？
  - 可能通过基类指针删除派生类对象
  - 如果你打算允许其他人通过基类指针调用对象的析构函数（通过delete这样做是正常的），就需要让基类的析构函数成为虚函数，否则执行delete的结果是不确定的。
  - **防止内存泄漏**



#### 虚表与动态绑定

- 虚表
  - 每个多态类有一个虚表（virtual table）
  - 虚表中有当前类的各个虚函数的入口地址
  - 每个对象有一个指向当前类的虚表的指针（虚指针vptr）
- 动态绑定的实现
  - 构造函数中为对象的虚指针赋值
  - 通过多态类型的指针或引用调用成员函数时，通过虚指针找到虚表，进而找到所调用的虚函数的入口地址
  - 通过该入口地址调用虚函数

### 虚表示意图

![示意图](http://www.xuetangx.com/asset-v1:TsinghuaX+00740043_2x_2015_T2+sp+type@asset+block/8-1.png)

### 抽象类(类似java)

#### 纯虚函数

- 纯虚函数是一个在基类中声明的虚函数，它在该基类中没有定义具体的操作内容，要求各派生类根据实际需要定义自己的版本，纯虚函数的声明格式为：

> virtual 函数类型 函数名(参数表) = 0;
>

- 带有纯虚函数的类称为抽象类

#### 抽象类
- 带有纯虚函数的类称为抽象类:
>
>class 类名 { virtual 类型 函数名(参数表)=0; //其他成员…… }
>
#### 抽象类作用

- 抽象类为抽象和**设计的目的**而声明
- 将有关的数据和行为组织在一个继承层次结构中，保证派生类具有要求的行为。
- 对于暂时无法实现的函数，可以声明为纯虚函数，留给派生类去实现。

#### 注意

- 抽象类只能作为基类来使用。
- 不能定义抽象类的对象。

#### 抽象类举例

```c++
//8_6.cpp
#include <iostream>
using namespace std;

class Base1 { 
public:
    virtual void display() const = 0;   //纯虚函数
};

class Base2: public Base1 { 
public:
    virtual void display() const; //覆盖基类的虚函数
};
void Base2::display() const {
    cout << "Base2::display()" << endl;
}

class Derived: public Base2 { 
public:
     virtual void display() const; //覆盖基类的虚函数
};
void Derived::display() const {
    cout << "Derived::display()" << endl;
} 
void fun(Base1 *ptr) { 
    ptr->display(); 
}
int main() {    
    Base2 base2;    
    Derived derived;    
    fun(&base2);    
    fun(&derived);  
    return 0;
}
```



### C++11新功能：override 与 final

#### override

- 多态行为的基础：基类声明虚函数，继承类声明一个函数覆盖该虚函数
- 覆盖要求： 函数签名（signatture）完全一致
- 函数签名包括：函数名 参数列表 const

下列程序就仅仅因为***疏忽漏写了const***，导致多态行为**没有如期进行**

![疏忽](http://www.xuetangx.com/asset-v1:TsinghuaX+00740043_2x_2015_T2+sp+type@asset+block/8-2.png)

#### 显式函数覆盖

- C++11 引入显式函数覆盖，在**编译期而非运行期捕获此类错误**。
-  在虚函数显式重载中运用，编译器会检查基类是否存在一虚拟函数，与派生类中带有声明override的虚拟函数，有相同的函数签名（signature）；若不存在，则会回报错误。

#### final

- C++11提供的final，用来避免类被继承，或是基类的函数被改写 

- 例：

  >  struct Base1 final { };
  >
  > struct Derived1 : Base1 { }; // 编译错误：Base1为final，不允许被继承
  >
  > struct Base2 { virtual void f() final; };
  >
  > struct Derived2 : Base2 { void f(); // 编译错误：Base2::f 为final，不允许被覆盖 };

#### 小结

- 主要内容
  - 多态性的概念、运算符重载、虚函数、纯虚函数、抽象类、override 和 final
- 达到的目标
  - 掌握运算符重载原理和方法
  - 理解动态多态性的原理，掌握通过虚函数实现的多态性的方法
  - 掌握纯虚函数和抽象类的概念和设计方法



## 模板与群体数据

### 函数模板

#### 模板

![平均值](http://www.xuetangx.com/asset-v1:TsinghuaX+00740043_2x_2015_T2+sp+type@asset+block/9-1.png)

![原理](http://www.xuetangx.com/asset-v1:TsinghuaX+00740043_2x_2015_T2+sp+type@asset+block/9-2.png)

### 函数模板定义语法

- 语法形式：

  > **template <模板参数表>**

#### 函数定义

- 模板参数表的内容
  - 类型参数：class（或typename） 标识符
  - 常量参数：类型说明符 标识符
  - 模板参数：template <参数表> class标识符

#### 函数模板的示例

```c++
//9_1.cpp
#include <iostream>
using namespace std;

template <class T>  //定义函数模板
void outputArray(const T *array, int count) {
    for (int i = 0; i < count; i++)
        cout << array[i] << " "; //如果数组元素是类的对象，需要该对象所属类重载了流插入运算符“<<”
    cout << endl;				 //原因是如果传入的参数是类或对象的话那么无法正常输出
}

int main() {     
    const int A_COUNT = 8, B_COUNT = 8, C_COUNT = 20;
    int a [A_COUNT] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    double b[B_COUNT] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8 };
    char c[C_COUNT] = "Welcome!";

    cout << " a array contains:" << endl;
    outputArray(a, A_COUNT);    
    cout << " b array contains:" << endl;
    outputArray(b, B_COUNT);    
    cout << " c array contains:" << endl;
    outputArray(c, C_COUNT);    
    return 0;
}
运行结果如下：
a array contains:
1 2 3 4 5 6 7 8
b array contains:
1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 
c array contains:
W e l c o m e!
```

#### 注意

- 一个函数模板并非自动可以处理所有类型的数据
- 只有能够进行函数模板中运算的类型，可以作为类型实参
- 自定义的类，需要重载模板中的运算符，才能作为类型实参

### 类模板

#### 类模板的声明

> 类模板 template <模板参数表> 
>
> class 类名
>
>  {类成员声明};

如果需要在类模板以外定义其成员函数，则要采用以下的形式：

>  template <模板参数表> 类型名 
>
> 类名<模板参数标识符列表>::函数名（参数表）

#### 类模板示例

```c++
#include <iostream>
#include <cstdlib>
using namespace std;
struct Student {
  int id;       //学号
  float gpa;    //平均分
}; 
template <class T>
class Store {//类模板：实现对任意类型数据进行存取
private:
    T item; // item用于存放任意类型的数据
    bool haveValue;  // haveValue标记item是否已被存入内容
public:
    Store();
    T &getElem();   //提取数据函数
    void putElem(const T &x);  //存入数据函数
};

template <class T>  
Store<T>::Store(): haveValue(false) { } 
template <class T>
T &Store<T>::getElem() {
    //如试图提取未初始化的数据，则终止程序
    if (!haveValue) {   
        cout << "No item present!" << endl;
        exit(1);    //使程序完全退出，返回到操作系统。
    }
    return item;        // 返回item中存放的数据 
}
template <class T>
void Store<T>::putElem(const T &x) {
    // 将haveValue 置为true，表示item中已存入数值   
    haveValue = true;   
    item = x;           // 将x值存入item
}

int main() {
    Store<int> s1, s2;  
    s1.putElem(3);  
    s2.putElem(-7);
    cout << s1.getElem() << "  " << s2.getElem() << endl;

    Student g = { 1000, 23 };
    Store<Student> s3;
    s3.putElem(g); 
    cout << "The student id is " << s3.getElem().id << endl;

    Store<double> d;
    cout << "Retrieving object D... ";
    cout << d.getElem() << endl;
   //d未初始化，执行函数D.getElement()时导致程序终止
    return 0;
}
```



### !!!!模板不支持分离编译。你需要把所有的申明和定义放在一个文件里实现!!!


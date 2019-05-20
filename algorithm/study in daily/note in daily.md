# 笔记

## TinghuaOJ

- 非常难受的OJ，不仅不支持C++11，还不支持STL用起来很头大

### tutorial

- 用double，哪怕是简单的int类型输出如果需要int那就`.0f`
- 尽量多用变量保险，因为内存是足够的
- 处理多个空格的时候，如果需要从空格中间读取char类型，只需要利用空格，如下

> scanf("%lf %c %lf", &num1, &op , &num2);
> 这一句就直接把num1与num2中间空格全部无视，直接读取operator

- 可能大部分OJ不支持c++11
- 缓冲区
  - [缓冲区的知识](http://www.cnblogs.com/pricks/p/3821832.html)
  - [流与缓冲区](http://www.cnblogs.com/chunlanse2014/articles/4420525.html)
  - [setvbuf()函数](http://c.biancheng.net/cpp/html/268.html)
  - 输入是文本流
  - 不同硬件会被映射成一个文件
  - [C动态分配内存1](https://www.cnblogs.com/chunlanse2014/articles/4421942.html)
  - [C动态分配内存2](https://www.cnblogs.com/chunlanse2014/articles/4422153.html)

## BlueBrige2019

- 蓝桥杯笔记

### 计蒜客网课

- 全局变量数组会被初始化为0(GCC)
- 日期计算星期几

> w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7
> 每年1，2月为上一年的13，14月，除法均为整除

- lower_bound() 返回第一个大于等于值val的位置
- upper_bound() 返回的是最后一个大于val的位置，也是有一个新元素val进来时的插入位置
- 返回值可转换为vector<T>::const_iterator类型

- %02d用0补齐2位，同理%04d用0补齐4位

- 直接读取到尾部直接如下操作

> while(scanf("") != EOF);

- set遍历时是按照从小到大遍历得，就是说set会帮助你排序
- map[""] = ;这样可以更改map中的值
- map中的遍历也是根据key从小到大访问的

> vector<int> v[10005]; 这里是比较常见的二维vector写法

- 不要忘了左移右移，(1LL << n)这个是1 * 2 ^ n的意思，用于整型，LL代表longlong
- 注意细节T_T

- DP
    - 最优化原理
    - 无后效性

### 计蒜客模拟赛

### 蓝桥杯题库

- 输出到int中

> istringstream is("12");
> int isINT;
> is >> isINT;

- 输出到string中

> ostringstream os;
> int osINT;
> os << osINT;
> cout << os.str() << endl;

- 另一种方式

> sstrram s;
> ss << num;
> ss >> str;

### 2019.03.24 real 蓝桥杯

- 已凉，勿念
- 好多题能做对还是错了
- 自己还是学的太不扎实了

## VOJ

### 纳新题目

- 一定要考虑清楚，像是盐水，水滴什么的毫升数有可能是`有小数的`
- map真好用, 大数据小数据分开考虑
- 精度问题：涉及到小数计算一律使用`%n.mlf`进行输出(就算是整型也用`%.lf`输出)

### 日常

#### 快速幂

- 普通快速幂

```c++
int poww(int a, int b) {
    int ans = 1, base = a;
    while (b != 0) {
        if (b & 1 != 0)
            ans *= base;
            base *= base;
            b >>= 1;
    }
    return ans;
}
```

- 斐波那契数列快速幂模板

```c++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod = 10000;
const int maxn = 35;
int N;
struct Matrix {
    int mat[maxn][maxn];
    int x, y;
    Matrix() {
        memset(mat, 0, sizeof(mat));
        for (int i = 1; i <= maxn - 5; i++) mat[i][i] = 1;
    }
};
inline void mat_mul(Matrix a, Matrix b, Matrix &c) {
    memset(c.mat, 0, sizeof(c.mat));
    c.x = a.x; c.y = b.y;
    for (int i = 1; i <= c.x; i++) {
        for (int j = 1; j <= c.y; j++) {
            for (int k = 1; k <= a.y; k++) {
                c.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % mod;
                c.mat[i][j] %= mod;
            }
        }
    }
    return ;
}
inline void mat_pow(Matrix &a, int z) {
    Matrix ans, base = a;
    ans.x = a.x; ans.y = a.y;
    while (z) {
        if (z & 1 == 1) mat_mul(ans, base, ans);
        mat_mul(base, base, base);
        z >>= 1;
    }
    a = ans;
}
int main() {
    while (cin >> N) {
        switch (N) {
            case -1: return 0;
            case 0: cout << "0" << endl; continue;
            case 1: cout << "1" << endl; continue;
            case 2: cout << "1" << endl; continue;
        }
        Matrix A, B;
        A.x = 2; A.y = 2;
        A.mat[1][1] = 1; A.mat[1][2] = 1;
        A.mat[2][1] = 1; A.mat[2][2] = 0;
        B.x = 2; B.y = 1;
        B.mat[1][1] = 1; B.mat[2][1] = 1;
        mat_pow(A, N - 1);
        mat_mul(A, B, B);
        cout << B.mat[1][1] << endl;
    }
    return 0;
}
```

## HDU OJ

### 日常

- 注意输入数据：
    - 有些时候给你的样例是有迷惑性得(2007)</br>这个题中，给你得样例都是从小到大得 但是其实测试样例有左边大于右边的情况
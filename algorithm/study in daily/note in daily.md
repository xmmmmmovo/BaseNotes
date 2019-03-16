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
- upper_bound() 返回的是最后一个大于等于val的位置，也是有一个新元素val进来时的插入位置
- 返回值可转换为vector<T>::const_iterator类型

- %02d用0补齐2位，同理%04d用0补齐4位

- 直接读取到尾部直接如下操作
> while(scanf("") != EOF);

## VOJ

### 纳新题目

- 一定要考虑清楚，像是盐水，水滴什么的毫升数有可能是`有小数的`
- map真好用, 大数据小数据分开考虑
# C++日常笔记

## 2019

### NULL & nullptr in C++

#### NULL in C

在C语言中，我们使用NULL表示空指针，也就是我们可以写如下代码：

```c
int *i = NULL;
foo_t *f = NULL;
```

实际上在C语言中，NULL通常被定义为如下：

```c
#define NULL ((void *)0)
```

也就是说NULL实际上是一个void *的指针，然后吧void *指针赋值给int *和foo_t *的指针的时候，隐式转换成相应的类型。而如果换做一个C++编译器来编译的话是要出错的，因为C++是强类型(所有变量对象都需要在编译阶段确定)的，void *是不能隐式转换成其他指针类型的，所以通常情况下，编译器提供的头文件会这样定义NULL：

```c
#ifdef __cplusplus ---简称：cpp c++ 文件
#define NULL 0
#else
#define NULL ((void *)0)
#endif
```

#### 0 in C++

在之前的版本中，推荐使用0而非NULL来表示空指针

为什么，举个例子

```c++
void test(type f, type *p); // 注意这里第二个是指针

//但是后来我们又重载了这个方法
void test(type f, int a);
```

这里应该就很明白了，如果我们使用`test(a, &b)`之类的是完全没有问题的，然而，如果我们使用`test(a, NULL)`呢？

我们知道，在C++里面，`NULL = 0`，所以调用出现了问题，这个问题是难以察觉到的，因为这个并不会报错，如果使用NULL的话，基本难以察觉。所以推荐`0`，这会让你更具有“警觉性”。

#### nullptr in C++ 11

但是这里如果用`test(a, nullptr)`就完全没有问题，一切都完美运行。

当然，在没有C++11的时候人们是怎么避免的呢？

在`《Imperfect C++》`上有个实现:

```c++
const
class nullptr_t
{
public:
    template<class T>
    inline operator T*() const
        { return 0; }

    template<class C, class T>
    inline operator T C::*() const
        { return 0; }
 
private:
    void operator&() const;
} nullptr = {};
```




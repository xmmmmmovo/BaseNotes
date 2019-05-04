/**
 * author: xmmmmmovo
 * generation time: 2019/04/24
 * filename: complex class.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

/**
 * 类内不含有指针的
 * 70%不需要写构造函数
*/
class Complex
{
private:
    double re, im;
public:
    Complex(double r, double i);
    /**
     * 如果内容不需要改变一定要加const
     * 这里代表着内部数据不会改变
    */
    double real() const { return re; }
    double imag() const { return im; }

    /**
     * 可以直接调用的原因
     * 相同class的各个objects互为friends(友元)
    */
    int func(const Complex& param) { return param.re + param.im; }
};

// 构造函数
Complex::Complex(double r = 0, double i = 0) : re(r), im(i) {}

int main(int argc, char const *argv[]) {
    const Complex c(1, 2);
    /**
     * 这里，如果没有把函数+const的话会报错
     * 因为编译器认为函数可能会改变值
    */
    cout << c.real() << endl;
    cout << c.imag() << endl;

    system("pause");
    return 0;
}
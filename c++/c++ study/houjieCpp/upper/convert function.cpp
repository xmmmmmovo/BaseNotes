/**
 * author: xmmmmmovo
 * generation time: 2019/05/03
 * filename: convert function.hpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    // Fraction(){};
    explicit Fraction(int num, int den);

    /**
     * 这个是转换函数
     * 意思是告诉编译器如果需要转换为double时调用这个重载
    */
    operator double() const{
        return m_numerator * 1.0 / m_denominator;
    }
};


inline
Fraction::Fraction(int num = 1, int den = 1)
    : m_numerator(num), m_denominator(den) {}

int main(int argc, char const *argv[]) {
    Fraction f(2, 3);
    double r = f + 4;
    cout << r << endl;

    system("pause");
    return 0;
}
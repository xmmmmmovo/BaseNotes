/**
 * author: xmmmmmovo
 * generation time: 2019/03/11
 * filename: expr.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
// #include <algorithm>

using namespace std;
/**
 * question:简单表达式(Expr)
 * 任给一个形如“A op B”的表达式,计算它的值。其中操作数 A 和 B 都是正整数,运算符 op 可以是+、‐或*,分别表示加、减、乘。
 * 运算符有且只有一个,除了 A 和 B 的内部不能有空格外(例如 123 不能写成 12 3),
 * 其余位置均可能有空格甚至多个空格,但不包含制表符 TAB。
 * 
 * 记住用double 然后
*/
int main(int argc, char const *argv[])
{
    double num1, num2, res;
    char op;
    scanf("%lf %c %lf", &num1, &op, &num2);

    switch (op)
    {
        case '+':
            res = num1 + num2;
            break;
        
        case '-':
            res = num1 - num2;
            break;
        
        case '*':
            res = num1 * num2;
            break;
    
        default:
            break;
    }

    printf("%.0f", res);

    // system("pause");
    return 0;
}
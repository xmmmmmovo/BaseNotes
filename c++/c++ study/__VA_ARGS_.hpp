#include <cstdio>
#include <cmath>
#include <iostream>

/**
 * # 号的用处：
 * 将参数转换为字符串%s
 * __VA_ARGS__则是把...替换
*/
#define P(A) printf("%s:%d\n",#A,A);

int main(int argc, char **argv)

{
    int a = 1, b = 2;

    P(a);
    P(b);
    P(a+b);

    system("pause");
    return 0;
}

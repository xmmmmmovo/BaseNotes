/**
 * author: xmmmmmovo
 * generation time: 2019/04/20
 * filename: Variadic Templates.cpp(参数不定模板)
 * language & build version : C++ 11
*/
/**
 * 用途：
 * 可用于递归
 * 
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

void print() {
}

template <typename T, typename... Types> // 模板参数包
void print(const T& firstArg, const Types&... args) { // 函数参数包
    cout << sizeof...(args) << endl; // 这里计算包的数量(参数数量)
    cout << firstArg << endl;
    // 这里调用的还是它本身而不是上面那个重载的函数
    // 当最后args...是空的时候才调用上面的函数
    print(args...); // 这里注意...
}

int main(int argc, char const *argv[]) {
    /**
     * ...
     * 可以接受任意个数参数
     * 在C++11中作为包
    */

    print("114536", "test", "123123");

    system("pause");
    return 0;
}
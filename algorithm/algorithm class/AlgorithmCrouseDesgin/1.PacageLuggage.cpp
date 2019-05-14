/**
 * author: xmmmmmovo
 * generation time: 2019/05/14
 * filename: 1.PacageLuggage.cpp
 * language & build version : C++ 14
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * 物件结构体
*/
typedef struct PC{
    string content_name;
    int content_volume;
    int content_value;
    PC(string name, int volume = 0, int value = 0)
        : content_name(name), content_volume(volume), content_value(value) {}
}package_content;

/**
 * 所有物件
*/
package_content objs[6]{
    package_content("laptop", 4, 7),
    package_content("camera", 2, 10),
    package_content("xbox", 6, 6),
    package_content("grinder", 4, 7),
    package_content("dumbbell", 2, 5),
    package_content("encyclopedia", 10, 4)
};

/**
 * 运算符重载 方便输出
*/
ostream& operator<< (ostream &o, const package_content &con) {
    return o << con.content_name << " " << con.content_volume << " " << con.content_value << endl;
}

/**
 * 主函数
*/
int main(int argc, char const *argv[]) {
    int N = 0;
    cin >> N;

    while (N--) {
        int w = 0; // 能够放进去的物品总体积
        
    }

    system("pause");
    return 0;
}
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
int count = 0;
int dp[10000][10000]; // dp数组开大点
vector<package_content> pcs;

/**
 * 运算符重载 方便输出
*/
ostream& operator<< (ostream &o, const package_content &con) {
    return o << con.content_name << " " << con.content_volume << " " << con.content_value << endl;
}

int solve() {
}

/**
 * 主函数
*/
int main(int argc, char const *argv[]) {
    // 重定向
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    int N = 0;
    cin >> N;

    while (N--) {
        string name;
        int cvo = 0, cva = 0;
        int num = 0, w = 0; // 能够放进去的物品总体积
        cin >> num >> w;
        for (int i = 0; i < num; i++) {
            cin >> name >> num >> w;
            pcs.push_back(package_content(name, cvo, cva));
        }
        solve();
    }

    system("pause");
    return 0;
}
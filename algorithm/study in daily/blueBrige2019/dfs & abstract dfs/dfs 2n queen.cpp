/**
 * author: xmmmmmovo
 * generation time: 2019/03/22
 * filename: dfs 2n queen.cpp
 * language & build version : C++ 11
*/
/**
问题描述
　　给定一个n*n的棋盘，棋盘中有一些位置不能放皇后。现在要向棋盘中放入n个黑皇后和n个白皇后，使任意的两个黑皇后都不在同一行、同一列或同一条对角线上，任意的两个白皇后都不在同一行、同一列或同一条对角线上。问总共有多少种放法？n小于等于8。

输入格式
　　输入的第一行为一个整数n，表示棋盘的大小。
　　接下来n行，每行n个0或1的整数，如果一个整数为1，表示对应的位置可以放皇后，如果一个整数为0，表示对应的位置不可以放皇后。

输出格式
　　输出一个整数，表示总共有多少种放法。

样例输入
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
样例输出
2

样例输入
4
1 0 1 1
1 1 1 1
1 1 1 1
1 1 1 1
样例输出
0
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n = 0, ans = 0;
int map[10][10];
int vy[10], vd1[20], vd2[20];

// x是棋子数量也是第几行
void dfs(int x, int p) {
    if (x == n && p == 2) {
        ans ++;
        return;
    }
    if (x == n) {
        dfs(0, p + 1);
        return;
    }

    // 对于y进行检测
    for (int i = 0; i < n; i++) {
        if (map[x][i] && 
            vy[i] != 3 && vy[i] != p &&
            vd1[x + i] != 3 && vd1[x + i] != p &&
            vd2[x - i + n] != 3 && vd2[x - i + n] != p) {
                map[x][i] = 0;
                vy[i] += p;
                vd1[x + i] += p;
                vd2[x - i + n] += p;
                dfs(x + 1, p);
                map[x][i] = 1;
                vy[i] -= p;
                vd1[x + i] -= p;
                vd2[x - i + n] -= p;
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    dfs(0, 1);

    cout << ans << endl;

    system("pause");
    return 0;
}
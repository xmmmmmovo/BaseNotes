/**
 * author: xmmmmmovo
 * generation time: 2019/03/27
 * filename: 2010 水仙花数.cpp
 * language & build version : C++ 11
*/
/**
Problem Description
春天是鲜花的季节，水仙花就是其中最迷人的代表，数学上有个水仙花数，他是这样定义的：
“水仙花数”是指一个三位数，它的各位数字的立方和等于其本身，比如：153=1^3+5^3+3^3。
现在要求输出所有在m和n范围内的水仙花数。
 
Input
输入数据有多组，每组占一行，包括两个整数m和n（100<=m<=n<=999）。
 
Output
对于每个测试实例，要求输出所有在给定范围内的水仙花数，就是说，输出的水仙花数必须大于等于m,并且小于等于n，如果有多个，则要求从小到大排列在一行内输出，之间用一个空格隔开;
如果给定的范围内不存在水仙花数，则输出no;
每个测试实例的输出占一行。

Sample Input
100 120
300 380

Sample Output
no
370 371
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;


bool check(int n) {
    int sum = 0, temp = 0, backup = n;

    while (n) {
        temp = n % 10;
        sum += temp * temp * temp;
        n /= 10;
    }

    return sum == backup;
}

int main(int argc, char const *argv[]) {
    int n, m;
    while (~scanf("%d %d", &m, &n)) {
        vector<int> flnum;
        for (int i = m; i <= n; i++) {
            if (check(i)) {
                flnum.push_back(i);
                // printf("%d", i);
            }
            // printf("%d", i);
        }

        if (flnum.empty()) {
            printf("no\n");
            continue;
        }
        
        for (int i = 0; i < flnum.size(); i++) {
            printf("%d", flnum[i]);
            if (i != flnum.size() - 1) {
                printf(" ");
            }
            
        }
        printf("\n");
    }

    // system("pause");
    return 0;
}
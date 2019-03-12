/**
 * author: xmmmmmovo
 * generation time: 2019/03/12
 * filename: Range.cpp
 * language & build version : C / C++98
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m); // 点的数量
    vector<double> nums(n, 0); // 所有点
    
    // 输入
    for(double& i : nums){
        cin >> i;
    }
    
    // 快排
    sort(nums.begin(), nums.end());
    
    int a = 0, b = 0;
    for(size_t i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        for(size_t i = 0; i < nums.size(); i++){
        }
    }
    

    system("pause");
    return 0;
}
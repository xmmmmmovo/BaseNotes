/**
 * author: xmmmmmovo
 * generation time: 2019/03/12
 * filename: Range.cpp
 * language & build version : C / C++98
 * 
 *      未完成
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int bisearch(){
}

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
        // 这里其实没写完，需要判断一下元素是不是vec原本就有的点
        auto iterle = lower_bound(nums.begin(), nums.end(), a); // 必须是const_iter
        auto iterri = upper_bound(nums.begin(), nums.end(), b);
        printf("%d\n", iterle - iterri - 2);
    }
    

    system("pause");
    return 0;
}
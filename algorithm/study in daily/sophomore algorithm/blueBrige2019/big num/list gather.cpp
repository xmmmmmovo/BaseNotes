/**
 * author: xmmmmmovo
 * generation time: 2019/03/16
 * filename: list gather.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0, digit = 0, temp = 0; // 阶乘n与进位digit
    vector<int> nums(10000, 0);

    scanf("%d", &n);

    nums[0] = 1;
    digit = 1; // 第一位
    
    // 从低位向高位乘
    for(int i = 2; i <= n; i++){
        int num = 0;
        // 这一步是对现有digit进行计算
        for(int j = 0; j < digit; j++){
            temp = nums[j] * i + num; // 计算位数额
            nums[j] = temp % 10; // 每一位进行储存
            num = temp / 10; // 为了下一位进行储存
        }

        // 这里是对digit进位进行计算
        while(num){
            nums[digit] = num % 10;
            num = num / 10;
            digit ++;
        }
    }

    for(int i = digit - 1; i >= 0; i--){
        printf("%d", nums[i]);
    }

    system("pause");
    return 0;
}
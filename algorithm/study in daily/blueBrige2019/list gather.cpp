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
    vector<int> reserve(4, 0);

    scanf("%d", &n);

    nums[0] = 1;
    digit = 1; // 第一位
    
    // 从低位向高位进位
    for(int i = 2; i <= n; i++){
        int num = 0;
        for(int j = 0; j < digit; j++){
            temp = nums[j] * i + num; // 计算位数额
            nums[j] = temp % 10; // 每一位进行储存
            num = temp / 10; // 为了下一位进行储存
        }

        while(num){
            nums[digit] = num % 10;
            num = num / 10;
            
        }
    }
    

    system("pause");
    return 0;
}
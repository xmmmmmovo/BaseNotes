/**
 * author: xmmmmmovo
 * generation time: 2019/03/14
 * filename: A A+B pro.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 传引用计算
void cacu(string &str1, string &str2, string &ans){
    int maxle = max(str1.length(), str2.length());
    vector<int> num1(maxle + 1, 0), num2(maxle + 1, 0);

    for(int i = str1.length() - 1, j = 0; i >= 0; i--, j++){
        num1[j] = (int)(str1[i] - '0');
    }
    for(int i = str2.length() - 1, j = 0; i >= 0; i--, j++){
        num2[j] = str2[i] - '0';
    }

    for(int i = 0; i < maxle; i++){
        num1[i] += num2[i];
        if (num1[i] >= 10){
            num1[i] -= 10;
            num1[i + 1] ++;
        }
    }

    if (num1.back() == 0) {
        num1.pop_back();
    }
    int size = num1.size();
    for(int i = size - 1; i >= 0 ; i--){
        ans.push_back(num1[i] + '0');
    }
}

int main(int argc, char const *argv[])
{
    int T = 0;
    scanf("%d", &T);

    string strs1;
    string strs2;

    for(int i = 0; i < T; i++){
        string ans;
        // 输入字符串
        cin >> strs1 >> strs2;

        printf("Case %d:\n%s + %s = ", i + 1, &strs1[0], &strs2[0]);
        cacu(strs1, strs2, ans);
        if (i == T - 1){
            printf("%s\n", &ans[0]);  
        }else{
            printf("%s\n\n", &ans[0]);
        }
    }

    // system("pause");
    return 0;
}
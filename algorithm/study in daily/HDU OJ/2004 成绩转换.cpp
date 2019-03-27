/**
 * author: xmmmmmovo
 * generation time: 2019/03/26
 * filename: 2004 成绩转换.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    int grade = 0;

    while (~scanf("%d", &grade)) {
        if (grade < 0 || 100 < grade) {
            printf("Score is error!\n");
        } else if (grade <= 59 && 0 <= grade) {
            printf("E\n");
        } else if (grade <= 69) {
            printf("D\n");
        } else if (grade <= 79) {
            printf("C\n");
        } else if (grade <= 89) {
            printf("B\n");
        } else if (grade <= 100) {
            printf("A\n");
        }
    }

    // system("pause");
    return 0;
}
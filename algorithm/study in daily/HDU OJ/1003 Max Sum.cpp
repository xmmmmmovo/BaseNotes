/**
 * author: xmmmmmovo
 * generation time: 2019/03/26
 * filename: 1003 Max Sum.cpp
 * language & build version : C++ 11
*/
/*
Problem Description
Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence.
 For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.
 

Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. 
Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).
 

Output
For each test case, you should output two lines. The first line is "Case #:", 
# means the number of the test case. The second line contains three integers, the Max Sum in the sequence, 
the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. 
Output a blank line between two cases.
 

Sample Input
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
 

Sample Output
Case 1:
14 1 4

Case 2:
7 1 6

此为O(N)解题方案，dp，最小前缀
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int nums[100005];

int main(int argc, char const *argv[]) {
    int n = 0, ten = 0;
    int len = 0;

    scanf("%d", &n);
    ten = n;
    while (n--) {
        int sum = 0, ans = 0, lflag = 0, rflag = 0, tag = 0;

        scanf("%d", &len);
        for (int i = 0; i < len; i++) {
            scanf("%d", &nums[i]);
        }

        ans = nums[0], sum = nums[0];
        for (int i = 1; i < len; i++) {
            sum += nums[i];
            // 这里为什么不能够按0判断?
            // 有可能会拖累后面的数
            // 这里如果判断是小于下一个数
            // 意思就是前面所有的数还没有下一个数大，肯定选下一个数
            if (sum < nums[i]) {
                sum = nums[i];
                // 这里为什么用一个变量标记左?
                // 因为sum不一定会更新ans
                // 如果直接更新了lflag
                // 那么如果最后没有ans的更改就会导致lflag的错误
                // 会WA
                tag = i;
            }

            if (ans < sum) {
                ans = sum;
                rflag = i;
                lflag = tag;
            }
        }

        printf("Case %d:\n%d %d %d\n", ten - n, ans, lflag + 1, rflag + 1);

        if (n) {
            printf("\n");
        }
        

        // printf("%d\n", nums.size());
    }

    system("pause");
    return 0;
}
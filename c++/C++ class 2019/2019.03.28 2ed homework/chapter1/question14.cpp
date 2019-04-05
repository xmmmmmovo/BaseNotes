#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

template <typename T>
void sort(T *nums, int start, int end) {
    if (start >= end)
        return;
    T mid = nums[end];
    int left = start, right = end - 1;
    while (left < right) { //在整个范围内搜寻比枢纽元值小或大的元素，然后将左侧元素与右侧元素交换
        while (nums[left] < mid && left < right) //试图在左侧找到一个比枢纽元更大的元素
            left++;
        while (nums[right] >= mid && left < right) //试图在右侧找到一个比枢纽元更小的元素
            right--;
        std::swap(nums[left], nums[right]); //交换元素
    }
    if (nums[left] >= nums[end])
        std::swap(nums[left], nums[end]);
    else
        left++;

    sort(nums, start, left - 1);
    sort(nums, left + 1, end);
}

int main(int argc, char const *argv[]) {
    int intnums[10] = {0, -1, 120, 23, -999, 3, 9, 87, 45, 9};
    float floatnums[10] = {0.12, -1.33, 120.23, 23.233, -999.022, 
                        3.233, 9.1234, 87.123, 45.123445, 9.1234};
    
    sort(intnums, 0, 9);
    sort(floatnums, 0, 9);

    for (int i = 0; i < 10; i++) {
        printf("%d ", intnums[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", floatnums[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}
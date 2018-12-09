#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

// 冒泡排序
int sort(int *num, int lo, int hi){
    int last = lo;
    int temp;

    while(++lo <= hi){
        if(num[lo - 1] > num[lo]){
            last = lo;

            temp = num[lo - 1];
            num[lo - 1] = num[lo];
            num[lo] = temp;
        }
    }

    return last;
}

void bubbleSort(int *num,int lo,int hi){
    while(lo < (hi = sort(num, lo, hi))); // 排序本体
}

// 快速排序
void qSort(int *num, int lo, int hi){
    if(lo >= hi){
        return; // 若最低位都比最高位高则排序完成
    }

    int first = lo;
    int last = hi;
    int key = num[first]; // 选取第一个未排序完成的数组元素作为基准点

    while(first < last){ // 判断是否符合顺序
        while(first < last && num[last] >= key){
            --last;
        }
        num[first] = num[last]; // 寻找第一个小于的
        while(first < last && num[first] <= key){
            ++first;
        }
        num[last] = num[first];
    }
    num[first] = key;
    qSort(num, lo, first - 1);
    qSort(num, first + 1, hi);
}

// 二分搜索
int biSearch(int lo, int hi,int searchNum, int *num){
    int mi = 0;
    while(lo < hi){
        mi = (hi + lo)/2; // 选取二分点

        if(searchNum < num[mi]){
            hi = mi;
        }else{
            lo = mi + 1;
        }
    }

    return --lo;
}

int main(int argc, char const *argv[])
{
    int i = 0, searchNum = 0;
    int num[] = {1, -1, 0, 12, 11, 34, 22, 1009, 122, -1233, 44, 122, 901, 1}; // length = 14
    // bubbleSort(num, 0, 13); // 冒泡排序(已优化)

    /*
    * 传递的参数
    * 1 待排序数组首地址
    * 2 数组中待排序元素数量　　
    * 3 各元素的占用空间大小
    * 4 指向函数的指针，用于确定排序的顺序
    */
    // qsort();// c++标准库中给的快速排序方案

    qSort(num, 0, 13); // 自写的快速排序
    for(i = 0;i < 14;i++){
        printf("%d ", num[i]);
    }
    printf("\n");
    scanf("%d", &searchNum);
    printf("%d\n", num[biSearch(0, 13, searchNum, num)]);

    system("pause");
    return 0;
}
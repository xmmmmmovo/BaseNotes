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

// 快速排序 未优化
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

void swap(int x[], int a, int b){
    int temp = x[a];
    x[a] = x[b];
    x[b] = temp;
}

int med3(int x[], int a, int b, int c) {
    return x[a] < x[b] ? (x[b] < x[c] ? b : x[a] < x[c] ? c : a)
            : x[b] > x[c] ? b : x[a] > x[c] ? c : a;
}

void vecswap(int x[], int a, int b, int n) {
    for (int i = 0; i < n; i++, a++, b++)
        swap(x, a, b);
}

void qsort7(int x[], int p, int r){
    if (p >= r)
        return;

    // 在数组大小小于7的情况下使用快速排序
    if (r - p + 1 < 7) {
        for (int i = p; i <= r; i++) {
            for (int j = i; j > p && x[j - 1] > x[j]; j--) {
                swap(x, j, j - 1);
            }
        }
        return;
    }

    // 选择中数，与qsort6相同。
    int len = r - p + 1;
    int m = p + (len >> 1);
    if (len > 7) {
        int l = p;
        int n = p + len - 1;
        if (len > 40) {
            int s = len / 8;
            l = med3(x, l, l + s, l + 2 * s);
            m = med3(x, m - s, m, m + s);
            n = med3(x, n - 2 * s, n - s, n);
        }
        m = med3(x, l, m, n);
    }

    int v = x[m];

    // a,b进行左端扫描，c,d进行右端扫描
    int a = p, b = a, c = p + len - 1, d = c;
    while (true) {
        // 尝试找到大于pivot的元素
        while (b <= c && x[b] <= v) {
            // 与pivot相同的交换到左端
            if (x[b] == v)
                swap(x, a++, b);
            b++;
        }
        // 尝试找到小于pivot的元素
        while (c >= b && x[c] >= v) {
            // 与pivot相同的交换到右端
            if (x[c] == v)
                swap(x, c, d--);
            c--;
        }
        if (b > c)
            break;
        // 交换找到的元素
        swap(x, b++, c--);
    }

    // 将相同的元素交换到中间
    int s, n = p + len;
    s = (a - p > b - a ? b - a : a - p);
    vecswap(x, p, b - s, s);
    s = (d - c > n - d - 1 ? n - d - 1 : d - c);
    vecswap(x, b, n - s, s);

    // 递归调用子序列
    if ((s = b - a) > 1)
        qsort7(x, p, s + p - 1);
    if ((s = d - c) > 1)
        qsort7(x, n - s, n - 1);

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

    // qSort(num, 0, 13); // 自写的快速排序
    qsort7(num, 0, 13);
    for(i = 0;i < 14;i++){
        printf("%d ", num[i]);
    }
    printf("\n");
    scanf("%d", &searchNum);
    printf("position is :%d\n", biSearch(0, 13, searchNum, num));

    system("pause");
    return 0;
}
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

// ð������
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
    while(lo < (hi = sort(num, lo, hi))); // ������
}

// �������� δ�Ż�
void qSort(int *num, int lo, int hi){
    if(lo >= hi){
        return; // �����λ�������λ�����������
    }

    int first = lo;
    int last = hi;
    int key = num[first]; // ѡȡ��һ��δ������ɵ�����Ԫ����Ϊ��׼��

    while(first < last){ // �ж��Ƿ����˳��
        while(first < last && num[last] >= key){
            --last;
        }
        num[first] = num[last]; // Ѱ�ҵ�һ��С�ڵ�
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

    // �������СС��7�������ʹ�ÿ�������
    if (r - p + 1 < 7) {
        for (int i = p; i <= r; i++) {
            for (int j = i; j > p && x[j - 1] > x[j]; j--) {
                swap(x, j, j - 1);
            }
        }
        return;
    }

    // ѡ����������qsort6��ͬ��
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

    // a,b�������ɨ�裬c,d�����Ҷ�ɨ��
    int a = p, b = a, c = p + len - 1, d = c;
    while (true) {
        // �����ҵ�����pivot��Ԫ��
        while (b <= c && x[b] <= v) {
            // ��pivot��ͬ�Ľ��������
            if (x[b] == v)
                swap(x, a++, b);
            b++;
        }
        // �����ҵ�С��pivot��Ԫ��
        while (c >= b && x[c] >= v) {
            // ��pivot��ͬ�Ľ������Ҷ�
            if (x[c] == v)
                swap(x, c, d--);
            c--;
        }
        if (b > c)
            break;
        // �����ҵ���Ԫ��
        swap(x, b++, c--);
    }

    // ����ͬ��Ԫ�ؽ������м�
    int s, n = p + len;
    s = (a - p > b - a ? b - a : a - p);
    vecswap(x, p, b - s, s);
    s = (d - c > n - d - 1 ? n - d - 1 : d - c);
    vecswap(x, b, n - s, s);

    // �ݹ����������
    if ((s = b - a) > 1)
        qsort7(x, p, s + p - 1);
    if ((s = d - c) > 1)
        qsort7(x, n - s, n - 1);

}

// ��������
int biSearch(int lo, int hi,int searchNum, int *num){
    int mi = 0;
    while(lo < hi){
        mi = (hi + lo)/2; // ѡȡ���ֵ�

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
    // bubbleSort(num, 0, 13); // ð������(���Ż�)

    /*
    * ���ݵĲ���
    * 1 �����������׵�ַ
    * 2 �����д�����Ԫ����������
    * 3 ��Ԫ�ص�ռ�ÿռ��С
    * 4 ָ������ָ�룬����ȷ�������˳��
    */
    // qsort();// c++��׼���и��Ŀ������򷽰�

    // qSort(num, 0, 13); // ��д�Ŀ�������
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
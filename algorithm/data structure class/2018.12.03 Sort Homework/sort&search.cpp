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

// ��������
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

    qSort(num, 0, 13); // ��д�Ŀ�������
    for(i = 0;i < 14;i++){
        printf("%d ", num[i]);
    }
    printf("\n");
    scanf("%d", &searchNum);
    printf("%d\n", num[biSearch(0, 13, searchNum, num)]);

    system("pause");
    return 0;
}
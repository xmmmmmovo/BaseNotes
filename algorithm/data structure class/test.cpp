#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;
double singerGrade[10];
int i = 0;

int sort(int lo, int hi){
    int last = lo;
    double temp;

    while(++lo <= hi){
        if(singerGrade[lo - 1] > singerGrade[lo]){
            last = lo;

            temp = singerGrade[lo - 1];
            singerGrade[lo - 1] = singerGrade[lo];
            singerGrade[lo] = temp;
        }
    }

    return last;
}

// �ɼ������� ��С����(С������������ð��)
void sortGrade(){
    int lo = 0, hi = 9;
    while(lo < (hi = sort(lo, hi))); // ������
}

int main(int argc, char const *argv[])
{
    for(i = 0;i < 10;i++){
        cin >> singerGrade[i];
    }

    sortGrade();

    for(i = 0;i < 10;i++){
        cout << singerGrade[i] << " ";
    }

    system("pause");
    return 0;
}
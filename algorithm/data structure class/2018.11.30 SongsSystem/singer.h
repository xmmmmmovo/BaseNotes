/**
 * ������
*/
#ifndef SINGER_H
#define SINGER_H
#include <iostream>
#include <string>

int i = 0;
using namespace std;

class Singer
{
    public:
        Singer(int singerNumber, string singerName, double *singerGrade);
        ~Singer();
        void sortGrade();
        double getArg();
        double getSum();

    private:
        int singerNumber = 0; //���ֱ��
        bool ifSorted = false; // �ж��Ƿ��Ѿ�����
        double *singerGrade; //�ü򵥵�����洢�ɼ�
        double arg = 0; // ƽ��������(��ͷȥβ)
        double sum = 0; // �ɼ��ܺ�
        string singerName; //stl�����string�洢����
        void caculateArg();
        int sort(int lo, int hi); // ������
};

//���캯��
Singer::Singer(int singerNumber, string singerName, double *singerGrade){
    this->singerNumber = singerNumber;
    this->singerName = singerName;
    this->singerGrade = singerGrade;
}

//��������
Singer::~Singer(){
    delete singerGrade; // ��ֹ�ڴ�й©
}

double Singer::getArg(){ // getter����
    return arg;
}

void Singer::caculateArg(){
    if(ifSorted){
        for(i = 1;i < 9;i++){
            sum += singerGrade[i];
        }
        arg = sum/8;
    }else{
        sortGrade();
        caculateArg();
    }

}

int Singer::sort(int lo, int hi){
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
void Singer::sortGrade(){
    int lo = 0, hi = 9;
    while(lo < (hi = sort(lo, hi))); // ������

    ifSorted = true;
}

#endif // SINGER_H
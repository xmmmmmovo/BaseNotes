/**
 * ������
*/
//�ȸ迪Դ���
#ifndef SINGER_H
#define SINGER_H
#include <string>

using namespace std;

class Singer
{
    public:
        Singer();
        ~Singer();
        void sortByGrade();

    private:
        int singerNumber = 0; //���ֱ��
        double *singerGrade; //�ü򵥵�����洢�ɼ�
        double argv = 0; // ƽ��������(��ͷȥβ)
        string singerName(); //stl�����string�洢����
};

//���캯��
Singer::Singer(){
    singerGrade = new double[10]; // ��̬�����ڴ�
}

//��������
Singer::~Singer(){
    delete singerGrade; // ��ֹ�ڴ�й©
}

void Singer::sortByGrade(){

}

#endif // SINGER_H
/**
 * 歌手类
*/
//谷歌开源风格
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
        int singerNumber = 0; //歌手编号
        double *singerGrade; //用简单的数组存储成绩
        double argv = 0; // 平均数储存(掐头去尾)
        string singerName(); //stl里面的string存储姓名
};

//构造函数
Singer::Singer(){
    singerGrade = new double[10]; // 动态分配内存
}

//析构函数
Singer::~Singer(){
    delete singerGrade; // 防止内存泄漏
}

void Singer::sortByGrade(){

}

#endif // SINGER_H
/**
 * author: xmmmmmovo
 * generation time: 2019/03/17
 * filename: question6.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
// #include <algorithm>
// #include <vector>

using namespace std;

class Cuboid
{
private:
    double length;
    double width;
    double height;
    double volume;

    bool isCacu;
public:
    Cuboid();
    Cuboid(double, double, double);
    void init();
    double getVolume();
};

Cuboid::Cuboid(){
    length = 0;
    width = 0;
    height = 0;
    volume = 0;
    isCacu = false;
}

Cuboid::Cuboid(double length, double width, double height)
{
    this->length = length;
    this->width = width;
    this->height = height;
    this->isCacu = false;
}

void Cuboid::init(){
    cin >> length >> width >> height;
    isCacu = false;
}

// 这里判断是否已经计算过了 如果计算过了直接返回值
double Cuboid::getVolume(){
    if (isCacu){
        return volume;
    }
    volume = length * width * height;
    return volume;
}



int main(int argc, char const *argv[])
{
    Cuboid *cub = new Cuboid[3];

    for(int i = 0; i < 3; i++){
        cub[i].init();
    }
    
    for(int i = 0; i < 3; i++){
        cout << cub[i].getVolume() << endl;
    }
    

    system("pause");
    return 0;
}
/**
 * author: xmmmmmovo
 * generation time: 2019/03/17
 * filename: arraymax.cpp
 * language & build version : C++ 11
*/
#include "arraymax.h"

using namespace std;

ArrayMax::ArrayMax()
{
    for(int i = 0;i < 10;i++){
        array[i] = 0;
    }
    max = 0;
}

void ArrayMax::set_value(){
    for(int i = 0; i < 10; i++){
        cin >> array[i];
    }
}

void ArrayMax::show_value(){
    cout << "max is " << max;
}

void ArrayMax::max_value(){
    max = array[0];
    for(int i = 1; i < 10; i++){
        if (max < array[i]) {
            max = array[i];
        }
    }
}
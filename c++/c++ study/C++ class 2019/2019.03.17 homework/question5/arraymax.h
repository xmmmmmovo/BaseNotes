/**
 * author: xmmmmmovo
 * generation time: 2019/03/17
 * filename: arraymax.h
 * language & build version : C++ 11
*/
#ifndef ARRAYMAX_H
#define ARRAYMAX_H

#include <iostream>

class ArrayMax
{
private:
    int array[10];
    int max;
public:
    ArrayMax();
    void set_value();
    void show_value();
    void max_value();
};

#endif // ARRAYMAX_H
/**
 * author: xmmmmmovo
 * generation time: 2019/05/29
 * filename: 1.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Point
{
private:
    int x, y;

public:
    Point(int xx = 0, int yy = 0)
     : x(xx), y(yy) {}

    Point & operator ++(int) {
        this->x++;
        this->y++;
        return *this;
    }

    Point & operator--(int) {
        this->x--;
        this->y--;
        return *this;
    }

    void print_xy() {
        cout << "now point is( " << x << ", " << y << ")" << endl;
    }
};

int main(int argc, char const *argv[]) {
    Point p1(1, 1);
    p1.print_xy();
    p1--;
    p1.print_xy();
    p1++;
    p1++;
    p1.print_xy();

    system("pause");
    return 0;
}
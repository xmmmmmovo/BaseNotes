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
#include <cmath>

using namespace std;

class Position
{
private:
    int x, y;

public:
    Position(int xx = 0, int yy = 0)
     : x(xx), y(yy) {}

    void set_x(int xx) {
        x = xx;
    }

    void set_y(int yy) {
        y = yy;
    }

    int get_x() {
        return x;
    }

    int get_y() {
        return y;
    }

    double distance(Position p) {
        double dis = 0;
        dis = sqrt((double)((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y)));
        return dis;
    }
};

int main(int argc, char const *argv[]) {
    Position p1(1, 1);
    Position p2(2, 2);

    cout << "x is " << p1.get_x() << " y is " << p1.get_y() << endl;

    p1.set_x(3);
    p1.set_y(3);
    cout << "x is " << p1.get_x() << " y is " << p1.get_y() << endl;

    cout << "distance is:" << p1.distance(p2) << endl;

    system("pause");
    return 0;
}
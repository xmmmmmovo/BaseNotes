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

class Shape
{
private:
public:
    Shape() {}
    virtual void draw() = 0;
};

class Point : public Shape
{
private:
    int x, y;
public:
    Point(int xx = 0, int yy = 0)
     : x(xx), y(yy) {}
    void draw() {
        cout << "Drawing Point (" << x << ", " << y << ") !" << endl;
    }
};

class Line : public Shape
{
private:
    // 懒得用point类了 这样写快
    int bx, by, ex, ey;
public:
    Line(int bxx, int byy, int exx, int eyy)
     : bx(bxx), by(byy), ex(exx), ey(eyy) {}

    void draw() {
        cout << "Drawing Line from ("
         << bx << ", " << by << ") to (" << ex << ", " << ey << ")" << endl; 
    }
};

class Circle : public Shape
{
private:
    int r, center;
public:
    Circle(int rr, int cen)
     : r(rr), center(cen) {}

    void draw() {
        cout << "Drawing Circle center = " << center << " r = " << r << endl;
    }
};

int main(int argc, char const *argv[]) {
    Shape* s[3];
    s[0] = new Point(1, 2);
    s[1] = new Line(1, 1, 2, 2);
    s[2] = new Circle(1, 2);

    for (int i = 0; i < 3; i++) {
        s[i]->draw();
    } 

    system("pause");
    return 0;
}
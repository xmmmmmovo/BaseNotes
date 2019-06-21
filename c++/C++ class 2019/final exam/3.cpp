#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
#define PI 3.1415926

class Shape
{
private:
public:
    Shape(){}
    virtual double PrintArea() = 0;
};

class Circle : public Shape {
private:
    double area = 0, r = 0;

    void cacuArea() {
        area = r * r * PI;
    }
public:
    Circle(double rr) {
        r = rr;
    }

    double PrintArea() override {
        cacuArea();
        return area;
    }
};

class Rectangle : public Shape {
private:
    double area = 0, x = 0;

    void cacuArea() {
        area = x * x;
    }
public:
    Rectangle(double xx, int yy) {
        x = xx;
    }

    double PrintArea() override {
        cacuArea();
        return area;
    }
};

class Triangle : public Shape {
private:
    double area = 0, board = 0, height = 0;

    void cacuArea() {
        area = (board * height) / 2.0;
    }

public:
    Triangle(double boardb, double heightb) {
        board = boardb;
        height = heightb;
    }

    double PrintArea() override {
        cacuArea();
        return area;
    }
};

int main(int argc, char const *argv[]) {
    Shape *sh[3]{
        new Circle(2),
        new Rectangle(4, 5),
        new Triangle(2, 3)
    };
    for (int i = 0; i < 3; i++) {
        cout << "Area is : " << sh[i]->PrintArea() << endl;
    }

    system("pause");
    return 0;
}
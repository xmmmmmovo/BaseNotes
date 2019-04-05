#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;
public:
    Date(int, int, int);
    void display();
};

Date::Date(int m = 1, int d = 1, int y = 2005) : month(m), day(d), year(y) {
}

void Date::display() {
    cout << month << '/' << day << '/' << year << endl;
}

int main(int argc, char const *argv[]) {
    Date d1(10, 13, 2005);
    Date d2(12, 30);
    Date d3(10);
    Date d4;

    d1.display();
    d2.display();
    d3.display();
    d4.display();
    system("pause");
    return 0;
}
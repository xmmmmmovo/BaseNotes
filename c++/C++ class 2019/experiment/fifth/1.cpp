#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

typedef struct Date
{
    int year;
    int month;
    int day;
    Date(){
        year = 0;
        month = 0;
        day = 0;
    }
    Date(int yy, int mm, int dd) {
        year = yy;
        month = mm;
        day = dd;
    }

    void display() {
        printf("%d/%d/%d\n", year, month, day);
    }
}date;


class People
{
private:
    string name;
    date birthday;
    double height;
    string address;
public:
    People(string name_, date birthday_, double height_, string address);
    void ChangeAddress(string newAddress);
    void display();
};

People::People(string name_, date birthday_, double height_, string address_) : 
            name(name_), birthday(birthday_), height(height_), address(address_) {
}

void People::ChangeAddress(string newAddress) {
    address = newAddress;
}

void People::display() {
    cout << "姓名：" << name << endl;
    cout << "出生日期：";
    birthday.display();
    cout << "身高：" << height << endl;
    cout << "住址：" << address << endl;
}

int main(int argc, char const *argv[]) {
    People pep("王大锤", date(2013, 12, 9), 178, "塔克拉玛干沙漠");
    pep.display();

    system("pause");
    return 0;
}
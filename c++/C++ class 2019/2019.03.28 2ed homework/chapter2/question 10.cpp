#include<iostream>

using namespace std;

class Date;
class Time {
public:
	Time(int, int, int);
	friend void display(const Date &, const Time &);
private:
	int hour;
	int minute;
	int sec;

};
class Date {
public :
	Date(int, int, int);
	friend void display(const Date &,const Time &);
private:
	int month;
	int day;
	int year;
};

Time::Time(int h, int m, int s) {
	hour = h;
	minute = m;
	sec = s;
}

void display(const Date &d, const  Time &t) {
	cout << d.month << "/" << d.day << "/" << d.year << endl;
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}

Date::Date(int m, int n, int y) {
	month = m;
	day = n;
	year = y;
}

int main() {
	Time t1(10, 13, 56);
	Date d1(12, 25, 2004);
	display(d1,t1);
	system("pause");
    return 0;
}

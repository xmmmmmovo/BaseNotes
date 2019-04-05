#include <cstdio>
#include <iostream>

class TDate {
private:
    int year;
    int month;
    int day;

public:
    TDate(int yy = 0, int mm = 0, int dd = 0) :
        year(yy), month(mm), day(dd) {
    }

    void SetDate(int yy, int mm, int dd) {
        year = yy;
        month = mm;
        day = dd;
    }

    void AddOneDay() {
        day ++;
        if (month == 1 || month == 3 || month == 5
            || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day > 31) {
                day = 1;
                month ++;
            }
        } else if (month == 2){
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                if (day > 29) {
                    day = 1;
                    month ++;
                }
            } else {
                if (day > 28) {
                    day == 1;
                    month ++;
                }
            }
        } else {
            if (day > 30) {
                day = 1;
                month ++;
            }
        }
        if (month > 12) {
            month = 1;
            year ++;
        }
    }

    void display() {
        printf("%d/%d/%d\n", year, month, day);
    }
};

int main() {
    int yy, mm, dd;
    scanf("%d%d%d", &yy, &mm, &dd);
    TDate td(yy, mm, dd);
    td.display();
    td.AddOneDay();
    td.display();

    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

class Student
{
private:
    int grade;
    int num;
public:
    Student(int, int);
    void setStu(int, int);
    int getGrade();
    void display();
};

Student::Student(int n = 0, int g = 0) : num(n), grade(g){
}

void Student::display() {
    cout << num << ' ' << grade << endl;
}

void Student::setStu(int n, int g) {
    num = n;
    grade = g;
}

int Student::getGrade() {
    return grade;
}

bool cmp(Student st1, Student st2) {
    return st1.getGrade() < st2.getGrade();
}

int main(int argc, char const *argv[]) {
    Student stu[5];

    for (int i = 0; i < 5; i++) {
        stu[i].setStu(rand() % 60 + 1707004500, rand() % 100);
        stu[i].display();
    }

    cout << "max element is :\n";
    (*max_element(stu, stu + 5, cmp)).display();

    system("pause");
    return 0;
}
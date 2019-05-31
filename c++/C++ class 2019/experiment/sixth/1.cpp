#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Animal
{
private:
    int age_;
public:
    Animal(int age);
    void SetAge(int age);
    void show() {
        cout << "now age is :" << age_ << endl; 
    }
};

Animal::Animal(int age) : age_(age) {}

void Animal::SetAge(int age) {
    age_ = age;
}

class Dog : public Animal
{
private:    
public:
    Dog(int a) : Animal(a) {}
};

int main(int argc, char const *argv[]) {
    Dog d(12);
    d.show();

    d.SetAge(123);
    d.show();

    system("pause");
    return 0;
}
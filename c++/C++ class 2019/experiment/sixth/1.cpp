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
};

Animal::Animal(int age) : age_(age)
{
}

void Animal::SetAge(int age) {
    age_ = age;
}

int main(int argc, char const *argv[]) {
    

    system("pause");
    return 0;
}
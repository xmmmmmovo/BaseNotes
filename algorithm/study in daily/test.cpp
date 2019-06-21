#include <iostream>
using namespace std;
class A{
public:
    virtual ~A() {cout<<"A::~A() is called. "<<endl;}
};
class B:public A{
public:
    B(int i) {buf=new char[i];}
    virtual ~B(){ delete [] buf; cout<<"B::~B() is called. "<<endl;}
private:
    char *buf;
};
int main(){
    A *p=new B(10);
    delete p;

    system("pause");
    return 0;
}

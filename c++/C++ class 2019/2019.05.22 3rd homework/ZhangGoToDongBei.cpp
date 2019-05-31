#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Address {
public:
	string address ;
	 Address(string addr) : address(addr) {
	}
};


class  Driver {
public:
	string name;
	Driver(string name1): name(name1) {
	
	}
};



class Vehicle {
public:
	virtual void go(Address dest, Driver dri) {}
};

class Car : public Vehicle{
public:
	void go(Address dest, Driver dri) { cout << dri.name << "开小汽车去" << dest.address; }
};

class Plain : public Vehicle {
public:
	void go(Address dest, Driver dri) { cout << dri.name << "开飞机去" << dest.address; }
};

class Train : public Vehicle {
public:
	void go(Address dest, Driver dri) { cout << dri.name << "开火车去" << dest.address; }
};

int main() {
	Address address("东北");
	Driver driver("老张");
	Vehicle ve;
	Car car;
	Plain plain;
	Train train;
	int i;
    while (cin >> i) {
        if (i == 1) {
            car.go(address, driver);
            cout << endl;
        }
        if (i == 2) {
            plain.go(address, driver);
            cout << endl;
        }
        if (i == 3) {
            train.go(address, driver);
            cout << endl;
        }   
    }
	system("pause");
}
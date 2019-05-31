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
	void go(Address dest, Driver dri) { cout << dri.name << "��С����ȥ" << dest.address; }
};

class Plain : public Vehicle {
public:
	void go(Address dest, Driver dri) { cout << dri.name << "���ɻ�ȥ" << dest.address; }
};

class Train : public Vehicle {
public:
	void go(Address dest, Driver dri) { cout << dri.name << "����ȥ" << dest.address; }
};

int main() {
	Address address("����");
	Driver driver("����");
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
#include <iostream>
using namespace std;
class A {
public:
	A(int i) { p = new int(i); }
	~A() { delete p; cout << "delete p!" << endl; }
	A(A& r) { p = new int(*r.p); cout << "copy complete!" << endl; }
	A& operator =(A& r) {
		if (this == &r)  return *this; *p = *r.p; cout << "evaluation complete!" << endl;
		return *this;
	}
private:
	int *p;
};
int main() {
	A a(1);
	A b(a);
	A c(2), d(3);
	d = c;
	// system("pause");
	return 0;
}

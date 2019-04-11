#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	int * const p = &a;

	a = 12;

	cout << *p << endl;
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;
template<class numtype>
class Compare {
public:
	Compare(numtype a, numtype b);
	numtype max();
	numtype min();
private:
	numtype x, y;
};
template<class numtype>
Compare<numtype>::Compare(numtype a, numtype b)
{
	x = a; y = b;
}
template<class numtype>
numtype Compare<numtype>::max() {
	return (x > y) ? x : y;
}
template<class numtype>
numtype Compare<numtype>::min() {
	return (x < y) ? x : y;
}


int main() {
	Compare<int> comp1(3, 7);
	cout << comp1.max() << " is the Maximum of two integer numbers. " << endl;
	cout << comp1.min() << " is the Minimum of two integer numbers. " << endl;
	Compare<float> comp2(45.78,93.6);
	cout << comp2.max() << " is the Maximum of two integer numbers. " << endl;
	cout << comp2.min() << " is the Minimum of two integer numbers. " << endl;
	Compare<char> comp3('a','A');
	cout << comp3.max() << " is the Maximum of two integer numbers. " << endl;
	cout << comp3.min() << " is the Minimum of two integer numbers. " << endl;
	system("pause");
    return 0;
}

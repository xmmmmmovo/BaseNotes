#include <iostream>

using namespace std;

class complex
{
public:
  complex (double r = 0, double i = 0): re (r), im (i) { }
  complex operator + (const complex &x){
      return complex(re + x.re, im + x.im);
  }
  complex operator - (const complex &x){
        return complex(re - x.re, im - x.im);
  }
  double real () const { 
      return re; 
    }
  double imag () const {
       return im; 
    }
private:
  double re, im;
};


ostream&
operator << (ostream& os, const complex& x)
{
  return os << '(' << x.real() << ',' << x.imag() << ')';
}

int main()
{
  complex c1(2, 1);
  complex c2(4, 0);

  cout << c1 << endl;
  cout << c2 << endl;
  
  cout << c1+c2 << endl;
  cout << c1-c2 << endl;
  
  system("pause");
  return 0;
}

#include<iostream>  
#include<math.h>  
#include<iomanip>  
using namespace std;
int main()
{
	cout << "���������" << endl;
	int n;
	cin >> n;
	cout << "��������꣺" << endl;
	if (n >= 2 && n <= 1000)
	{
		int d = 0, sum = 0;
		float temp, l, s;
		for (int p = n - 1; p >= 1; p--)
		{
			sum += p;
		}
		float*c = new float[sum];
		float*a = new float[n];
		float*b = new float[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i];
		}
		for (int j = 0; j < n - 1; j++)
		{
			for (int k = n - 1; k >= j + 1; k--)
			{
				l = a[j] - a[k];
				s = b[j] - b[k];
				c[d] = sqrt(l*l + s * s);
				d++;
			}
		}
		temp = c[0];
		for (int y = 1; y < sum; y++)
		{
			if (temp > c[y])
			{
				temp = c[y];
			}
		}
		cout.setf(ios::fixed);
		cout << "��С����Ϊ��" << setprecision(3) << temp << endl;
		delete[]a;
		delete[]b;
		delete[]c;
	}

	system("pause");
	return 0;
}

// ����console
// #pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
// �㷨��
#include <algorithm>
// �������ͷ�ļ�
#include <random>
#include <iomanip>
#include <windows.h>

using namespace std;

// ��������һ��һά�������ģ�����
vector<int> p;
// ����a�洢���Ǿ�������
vector<string> a;
// min_part[i][j]�洢����i+1��j+1����С�˴Σ���Ϊ�Ǵ�0��ʼ
// min_point[i][j]�洢����i+1��j+1֮����С�˴�ʱ�ķָ��
int min_part[100][100], min_point[100][100];

void PrintMatrix(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << setw(10) << min_part[i][j];
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << setw(10) << min_point[i][j];
		}
		cout << endl;
	}
}

int matrix_chain(int n)
{
	//min_part[][]��С�˴���
	//min_point[][]��С����ʱ�ĶϿ���
	for (int i = 0; i < n; i++) {
		min_part[i][i] = 0;
	}

	//rΪ���˾���ĸ���
	for (int r = 2; r <= n; r++) {
		for (int i = 0; i <= n - r; ++i) {
			int j = i + r - 1;

			min_part[i][j] = min_part[i + 1][j]
				+ p[i] * p[i + 1] * p[j + 1];
			min_point[i][j] = i;

			system("cls");
			PrintMatrix(n);
			Sleep(100);

			for (int k = i; k < j; ++k) {

				int tmp = min_part[i][k] + min_part[k + 1][j]
						+ p[i] * p[k + 1] * p[j + 1];

				if (tmp < min_part[i][j]) {
					min_part[i][j] = tmp;
					min_point[i][j] = k;

					system("cls");
					PrintMatrix(n);
					Sleep(100);
				}
			}
		}
	}

	return min_part[0][n - 1]; // ���ص��������Ͻǵ�
}

void print_chain(int i, int j)
{
	//�ݹ�ķ�ʽ������С�����ı��ʽ���
	if (i == j)
	{
		cout << a[i];
	}
	else
	{
		printf("(");
		print_chain(i, min_point[i][j]);
		print_chain(min_point[i][j] + 1, j);
		printf(")");
	}
}

void Print(int n) {
	// ��ʽ�����
	for (int i = 0; i < n; ++i) {
		cout << setw(5) << a[i];
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << setw(5) << p[i];
	}
	cout << endl;

	cout << "��ʼ�����������";
	for (int i = 0; i < 3; ++i) {
		cout << " . ";
		Sleep(1000);
	}
	cout << endl;
	system("cls");
}

int main(int argc, char* argv[]) {
	int n = 5, ret = 0;

	// system("color 08");
	cout << "����������" << endl;
	cin >> n;

	// �������������͹̶�������
	for (int i = 0; i < n + 1; ++i) {
		p.push_back(rand() % 450);
		a.push_back("M" + to_string(i));
	}
	// p.push_back(30);
	// p.push_back(35);
	// p.push_back(15);
	// p.push_back(5);
	// p.push_back(20);
	// p.push_back(25);

	Print(n);

	PrintMatrix(n);

	ret = matrix_chain(n);
	system("cls");
	PrintMatrix(n);
	cout << setw(5) << "Minest times:" << ret << endl;
	print_chain(0, n - 1);

	system("pause");
	return 0;
}
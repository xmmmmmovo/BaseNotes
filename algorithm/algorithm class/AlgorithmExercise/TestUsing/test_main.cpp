#include<iostream>
#include <windows.h>
#include <easyx.h>			// 引用图形库头文件
#include <conio.h>
using namespace std;

const int N = 7;  //此时6个矩阵，p[N]存储行列数

void initM(int m[N][N])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			m[i][j] = INT_MAX;
	}
}
void initS(int s[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			s[i][j] = 0;
	}
}
int Aarray(int *p, int m[N][N], int s[N][N], int i, int j)
{

	if (i == j)
	{
		return 0;
	}
	if (m[i][j] < INT_MAX)
	{
		return m[i][j];
	}

	for (int k = i; k < j; ++k)
	{

		int tmp = Aarray(p, m, s, i, k) + Aarray(p, m, s, k + 1, j) + p[i - 1] * p[k] * p[j];
		if (tmp < m[i][j])
		{
			m[i][j] = tmp;
			s[i][j] = k;
		}
	}
	cleardevice();
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (m[i][j] == INT_MAX)
			{
				printf("0     ");
				settextcolor(BLACK);
				TCHAR s[10];
				_stprintf(s, _T("%d"), 0);
				outtextxy((500 - 80 * (N - j - 1)), (200 - 30 * (N - i - 1)), s);
			}
			else
			{
				printf("%5d ", m[i][j]);
				settextcolor(BLACK);
				TCHAR s[10];
				_stprintf(s, _T("%d"), m[i][j]);
				outtextxy((500 - 80 * (N - j - 1)), (200 - 30 * (N - i - 1)), s);
			}
		}
		printf("\n");
	}
	printf("\n");
	Sleep(500);
	return m[i][j];
}
void printS(int s[N][N])
{
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			printf("%5d ", s[i][j]);
			settextcolor(BLACK);
			TCHAR s1[10];
			_stprintf(s1, _T("%d"), s[i][j]);
			outtextxy((500 - 80 * (N - j - 1)), (420 - 30 * (N - i - 1)), s1);

		}
		printf("\n");
	}
	printf("\n");
	Sleep(500);
}
void PrintAnswer(int s[N][N], int i, int j)
{
	if (i == j)
	{
		cout << "A" << i;
	}
	else
	{
		cout << "(";
		PrintAnswer(s, i, s[i][j]);
		PrintAnswer(s, s[i][j] + 1, j);
		cout << ")";
	}
}
int main()
{
	initgraph(640, 480);	// 创建绘图窗口，大小为 640x480 像素
	setbkcolor(WHITE);
	int p[N] = { 30,35,15,5,10,20,25 };
	int m[N][N], s[N][N];
	initM(m);
	initS(s);
	cout << Aarray(p, m, s, 1, N - 1) << endl;
	TCHAR a[10] = _T("矩阵m=");
	outtextxy(30, 120, a);
	printS(s);
	TCHAR a1[10] = _T("矩阵s=");
	outtextxy(30, 340, a1);
	PrintAnswer(s, 1, N - 1);
	_getch();				// 按任意键继续
	closegraph();	// 关闭绘图窗口
	return 0;
}
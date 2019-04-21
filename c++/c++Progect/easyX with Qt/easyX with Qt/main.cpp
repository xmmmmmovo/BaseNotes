#include <graphics.h>  // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <cstdio>
#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include <thread> // �̳߳�

using namespace std;

struct point
{
	int x;
	int y;
};

//������֮��ľ���

double Dis(point a, point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x)*1.0 + (a.y - b.y)*(a.y - b.y)*1.0);
}

//�����������ľ��룬Ч��O��n^2��
double ClosePooints(point pt[], int num)
{
	double d, max = 10000000;
	int i, j, x1, y1, x2, y2;
	for (i = 0; i < num - 1; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			d = Dis(pt[i], pt[j]);
			if (max>d)
			{
				max = d;
				x1 = pt[i].x;
				y1 = pt[i].y;
				x2 = pt[j].x;
				y2 = pt[j].y;
			}
		}
	}
	line(x1, y1, x2, y2);
	return max;
}

int main()
{
	initgraph(640, 480, SHOWCONSOLE);
	point pt[1000];
	int num = 0; // ������
	cin >> num;
	int i;

	for (i = 0; i < num; i++)
	{
		cin >> pt[i].x;
		cin >> pt[i].y;

		setfillcolor(WHITE);
		fillrectangle(pt[i].x - 1, pt[i].y - 1,
			pt[i].x + 1, pt[i].y + 1);
	}

	// ����ͽ���
	double t = ClosePooints(pt, num);
	cout << setiosflags(ios::fixed) << setprecision(4) << t << endl;

	// _getch();              // �����������
	// closegraph();          // �رջ�ͼ����

	return 0;

}
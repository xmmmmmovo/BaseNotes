#include <graphics.h>  // 引用图形库头文件
#include <conio.h>
#include <cstdio>
#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include <thread> // 线程池

using namespace std;

struct point
{
	int x;
	int y;
};

//求两点之间的距离

double Dis(point a, point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x)*1.0 + (a.y - b.y)*(a.y - b.y)*1.0);
}

//求两个最近点的距离，效率O（n^2）
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
	int num = 0; // 计数器
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

	// 计算就近点
	double t = ClosePooints(pt, num);
	cout << setiosflags(ios::fixed) << setprecision(4) << t << endl;

	// _getch();              // 按任意键继续
	// closegraph();          // 关闭绘图窗口

	return 0;

}
#include<iostream>
#include<string>
using namespace std;
#include<conio.h>
#include<graphics.h>

int n;
int min_p = 0, max_p = 0;
int min_t = 0, max_t = 0;
double a, b;

int m[20][20][10];//存放i -> j 之间上凸包的点
typedef struct {
	int x;
	int y;
	int next;//指向下一个点
}Point;

void line_point(Point pt[], int c1, int c2);//线连接的声明
//判断是否是上包
int judge(Point pt[], int left, int right, int middle) {
	int sum = 0;
	sum = pt[left].x*pt[right].y + pt[middle].x*pt[left].y + pt[right].x*pt[middle].y - pt[middle].x*pt[right].y - pt[right].x*pt[left].y - pt[left].x*pt[middle].y;
	return sum;
}
//寻找最大值最小值
void find(Point pt[]) {
	int min, max;
	min = pt[0].x;
	max = pt[0].x;
	// x 值
	for (int i = 1; i < n; i++) {
		min = pt[i].x < min ? pt[i].x, min_p = i : min;
		max = pt[i].x > max ? pt[i].x, max_p = i : max;
	}
	//y值
	min = pt[0].y;
	max = pt[0].y;
	for (int i = 1; i < n; i++) {
		min = pt[i].y < min ? pt[i].y, min_t = i : min;
		max = pt[i].y > max ? pt[i].y, max_t = i : max;
	}
}
//对点的划分 
void divide_point(Point pt[], int left, int right) {
	int i, index = -1;
	int c = 0;//寻找的点 m[left][right][i]
	int sum = 0, max = 0;
	int k1 = 0, k2 = 0;
	setlinecolor(YELLOW);//画三角形的底
	line_point(pt, left, right);

	for (i = 0; m[left][right][i] != '\0'; i++) {
		c = m[left][right][i];
		sum = judge(pt, left, right, c);
		if (sum > max) {
			max = sum;
			index = c;
		}
		setlinecolor(BLUE);//画三角形的两个边
		line_point(pt, left, c);
		line_point(pt, c, right);
		Sleep(500);
		setlinecolor(BLACK);//删除线段
		line_point(pt, left, c);
		line_point(pt, c, right);
	}
	if (index != -1)
	{

		for (i = 0; m[left][right][i] != '\0'; i++) {
			c = m[left][right][i];
			sum = judge(pt, left, index, c);
			if (sum > 0) m[left][index][k1] = m[left][right][i], k1++;
			sum = judge(pt, index, right, c);
			if (sum > 0) m[index][right][k2] = m[left][right][i], k2++;
		}
		pt[left].next = index;//i -> 最大值点 -> j
		pt[index].next = right;
		divide_point(pt, left, index);//分治的部分
		divide_point(pt, index, right);//分治的部分
	}
	Sleep(500);//删除线段
	setlinecolor(BLACK);
	line_point(pt, left, right);
}
//标出所有的点
void all_point(Point pt[]) {
	int i, j;
	setfillcolor(WHITE);
	a = (pt[max_p].x - pt[min_p].x);  //采用比例的方式确保每次点都在中间
	b = (pt[max_t].y - pt[min_t].y);
	for (i = 0; i < n; i++) {
		solidcircle((pt[i].x - pt[min_p].x) * 320 / a, (pt[i].y - pt[min_t].y) * 200 / b, 6);
	}
}
//连接线并且每次重新绘制点
void line_point(Point pt[], int c1, int c2) {
	line((pt[c1].x - pt[min_p].x) * 320 / a, (pt[c1].y - pt[min_t].y) * 200 / b, (pt[c2].x - pt[min_p].x) * 320 / a, (pt[c2].y - pt[min_t].y) * 200 / b);
	//setfillcolor(WHITE);//效果不明显故删除
	solidcircle((pt[c1].x - pt[min_p].x) * 320 / a, (pt[c1].y - pt[min_t].y) * 200 / b, 6);
	solidcircle((pt[c2].x - pt[min_p].x) * 320 / a, (pt[c2].y - pt[min_t].y) * 200 / b, 6);
}
int main()
{
	initgraph(640, 480, SHOWCONSOLE);
	setorigin(100, 240);//设置起始坐标点
	setaspectratio(1, -1);//将y轴翻转确保x轴向右正方向，y轴向上正方向
	int s[20];
	Point pt[20];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pt[i].x >> pt[i].y;
		s[i] = i;
	}
	find(pt);
	all_point(pt);
	int k1 = 0, k2 = 0;//首先区分上包下包
	for (int i = 0; i < n; i++) {
		int sum = judge(pt, min_p, max_p, s[i]);
		if (sum > 0) m[min_p][max_p][k1] = s[i], k1++;
		if (sum < 0) m[max_p][min_p][k2] = s[i], k2++;
	}
	divide_point(pt, min_p, max_p);
	divide_point(pt, max_p, min_p);
	//顺时针输出
	int sm = 0;
	sm = pt[0].next;
	setlinecolor(RED);
	//cout << pt[sm].x << " " << pt[sm].y << endl;
	line_point(pt, 0, pt[0].next);
	do {
		//cout << pt[sm].x << " " << pt[sm].y << endl;
		line_point(pt, sm, pt[sm].next);
		sm = pt[sm].next;

	} while (sm != 0);

	_getch();
	closegraph();
	system("pause");
	return 0;
}

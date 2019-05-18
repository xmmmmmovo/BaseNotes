// 隐藏console
// #pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <iostream>
#include <vector>
#include <cstdlib>
// 算法库
#include <algorithm>
// 随机引擎头文件
#include <random>

using namespace std;

int matrix_chain(int *p, int n, int **m, int **s)
{
	//a[][]最小乘次数
	//s[][]最小乘数时的断开点
	int i, j, r, k;

	for (i = 0; i < n; i++)   //单一矩阵的最小乘次都置为0
	{
		m[i][i] = 0;
	}

	for (r = 2; r <= n; r++)  //r为连乘矩阵的个数
	{
		for (i = 0; i <= n - r; i++)   //i表示连乘矩阵中的第一个
		{
			j = i + r - 1;         //j表示连乘矩阵中的最后一个
			m[i][j] = 99999;
			for (k = i; k <= j - 1; k++)  //在第一个与最后一个之间寻找最合适的断开点，注意，这是从i开始，即要先计算两个单独矩阵相乘的乘次
			{
				int tmp = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
				if (tmp < m[i][j])
				{
					m[i][j] = tmp;
					s[i][j] = k;
				}
			}
		}
	}
	return m[0][n - 1];
}

void print_chain(int i, int j, char **a, int **s)
{
	//递归的方式来把最小乘数的表达式输出
	if (i == j)
	{
		printf("%s", a[i]);
	}
	else
	{
		printf("(");
		print_chain(i, s[i][j], a, s);
		print_chain(s[i][j] + 1, j, a, s);
		printf(")");
	}
}

int main(int argc, char* argv[]) {
	//min_part[i][j]存储的是i+1到j+1的最小乘次，因为是从0开始
	//min_point[i][j]存储的是i+1到j+1之间最小乘次时的分割点
	/**
	 * 这里用了一个一维数组进行模拟矩阵
	 * 这里意思是有4个矩阵 分别是：
	 * m[2][4], m[4][5], m[5][5], m[5][3]
	 */
	int *p, **min_part, **min_point;
	char **a;
	int n = 6, i;
	int ret;

	p = (int *)malloc((n + 1) * sizeof(int));
	a = (char **)malloc(n * sizeof(char*));
	min_part = (int **)malloc(n * sizeof(int *));
	min_point = (int **)malloc(n * sizeof(int *));

	// 分配空间
	for (i = 0; i < n; i++) {
		min_part[i] = (int *)malloc(n * sizeof(int));
		min_point[i] = (int *)malloc(n * sizeof(int));
		a[i] = (char *)malloc(n * sizeof(char));
	}

	p[0] = 30;
	p[1] = 35;
	p[2] = 15;
	p[3] = 5;
	p[4] = 10;
	p[5] = 20;
	p[6] = 25;

	a[0] = "A1";
	a[1] = "A2";
	a[2] = "A3";
	a[3] = "A4";
	a[4] = "A5";
	a[5] = "A6";

	ret = matrix_chain(p, n, min_part, min_point);
	printf("Minest times:%d.\n", ret);
	print_chain(0, n - 1, a, min_point);

	return 0;
}
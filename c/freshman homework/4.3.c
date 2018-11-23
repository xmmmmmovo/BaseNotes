# include<stdio.h>
# include<math.h>

int main(void)
{
	double a, b, c, p;
	
	printf("请输入你所求的三角形三边长(中间以空格分隔)\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	p = (a + b + c) / 2;
	printf("所求三角形的面积为：%.2lf\n", sqrt(p*(p-a)*(p-b)*(p-c)));
	
	return 0;
}
/*
2017年10月12日20:19:15
在devcpp中的运行结果为

请输入你所求的三角形三边长(中间以空格分隔)
3.1 3.2 3.3
所求三角形的面积为：4.43
*/
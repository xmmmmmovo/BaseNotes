# include<stdio.h>

# define pi 3.1415926

int main(void)
{
	double r;
	
	printf("请输入您所求球的半径\n");
	scanf("%lf", &r);
	
	printf("所求球的表面积为：%.2lf\n", 4*pi*r*2 );
	printf("所求球的体积为：%.2lf\n", (4/3.0)*pi*r*r*r );
	
	return 0;
}
/*
2017年10月12日19:56:16
在devcpp中的运行结果为

请输入您所球的半径
2.33
所求球的表面积为：58.56
所求球的体积为：39.74
*/
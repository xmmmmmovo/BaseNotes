# include<stdio.h>

# define pi 3.1415926

int main(void)
{
	double r;
	
	printf("请输入您所求圆的半径\n");
	scanf("%lf", &r);
	
	printf("所求圆的周长为：%.2lf\n", 2*pi*r );
	printf("所求圆的面积为：%.2lf\n", pi*r*r);
	
	return 0;
}
/*
2017年10月12日19:56:16
在devcpp中的运行结果为

请输入您所求圆的半径
2.33
所求圆的周长为：14.64
所求圆的面积为：17.06 
*/
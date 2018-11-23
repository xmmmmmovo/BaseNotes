# include<stdio.h>
# include<math.h>
# define g 9.8

int main(void)
{
	double h;
	
	printf("请输入下落的高度\n");
	scanf("%lf", &h);
	
	printf("%.2lf", sqrt(2*h/g));
	
	return 0;
}
/*
2017年10月13日17:30:27
在devcpp中的输出结果为

请输入下落的高度
9
1.36
*/
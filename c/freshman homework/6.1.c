# include <stdio.h>
# include <math.h>

int main(void)
{
	double a = 0;
	double b = 0;
	double c = 0;
	double delta;
	double x1, x2;
	
	printf("请输入a，b，c的值（中间以空格分隔）\n");
	scanf("%lf %lf %lf", &a, &b, &c);

	delta = b*b - 4*a*c;

	if (delta > 0)
	{
		x1 = (-b + sqrt(delta)) / (2*a);
		x2 = (-b - sqrt(delta)) / (2*a);
		printf("2个,x1 = %.2lf, x2 = %.2lf\n", x1, x2);
	}
	else if (delta == 0)
	{
		x1 = (-b) / (2*a);
		x2 = x1;
		printf("1个, x1 = x2 =%.2lf\n",x1);
	}
	else
	{
		printf("无解\n");
	}

	return 0;
}
/*
2017年10月13日20:06:42
在devcpp中的编译结果是

请输入a，b，c的值（中间以空格分隔）
2 3 4
无解
*/
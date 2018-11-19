# include<stdio.h>

int main(void)
{
	double s;
	
	scanf("%lf", &s);
	
	if(s < 0)
		puts("error!");
	else if(s >= 0 && s < 250)
		printf("%.2lf", 10*s);
	else if(s >= 250 && s < 500)
		printf("%.2lf", (10*s) * 0.98);
	else if(s >= 500 && s < 1000)
		printf("%.2lf", (10*s) * 0.95);
	else if(s >= 1000 && s < 2000)
		printf("%.2lf", (10*s) * 0.92);
	else if(s >= 2000 && s < 3000)
		printf("%.2lf", (10*s) * 0.90);
	else
		printf("%.2lf", (10*s) * 0.85);
	
	return 0;
}
/*
2017年10月26日20:29:15
在Devc++中的运行结果为
220
2200.00 
*/

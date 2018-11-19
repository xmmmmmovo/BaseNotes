# include<stdio.h>
# include<math.h>

int main(void)
{
	double x, y;
	
	scanf("%lf", &x);
	
	if(x < 1)
		y = x*x + 2*x + sin(x);
	else if(x >= 1 && x <= 10)
		y = 2*x - 1;
	else
		y = sqrt(2*x*x*x - 11);
		
	printf("%.2lf", y);
	
	return 0;
}
/*
在devc++中的运行结果为
0.1235
0.39
*/

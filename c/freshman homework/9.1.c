# include<stdio.h>
# include<math.h>

int main(void)
{
	double a, b, c, delta;
	
	scanf("%lf %lf %lf", &a, &b, &c);
	
	delta = b*b - 4*a*c;
	
	if(a == 0)
		puts("error!");
	else if(delta == 0)
		puts("1");
	else if(delta > 0)
		puts("2");
	else
		puts("0");
	
	return 0;
}
/*
在devc++中的运行结果为
1 2 1
1
*/
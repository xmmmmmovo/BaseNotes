# include<stdio.h>

int main(void)
{
	int a, b, c, d;
	
	scanf("%d %d %d", &a, &b, &c);
	
	if(a < b)
	{
		d = a;
		a = b;
		b = d;
	}
	if(a < c)
	{
		d = a;
		a = c;
		c = d;
	}
	if(b < c)
	{
		d = b;
		b = c;
		c = d;
	}
	
	printf("最小值是:%d", c);
	
	return 0;
}
/*
在devc++中的运行结果为
12 5 3
3
*/

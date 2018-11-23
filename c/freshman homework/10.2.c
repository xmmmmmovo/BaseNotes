# include<stdio.h>

int fac(int n)
{
	int keys;
	
	if(n < 0)
	{
		puts("error!");
		return 0;
	}
	else if(n == 0 || n == 1)
		keys = 1;
	else
		keys = fac(n-1) * n;
	return keys;
}

int main(void)
{
	int n;
	int i;
	int sum = 0;
	
	scanf("%d", &n);
	
	for(i=1; i<=n; ++i)
		sum += fac(i);
	
	printf("%d", sum);
	
	return 0;
}
/*
在devc++中运行结果为
3
9
*/
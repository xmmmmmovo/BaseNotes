# include<stdio.h>

int main(void)
{
	int i;
	int n;
	
	scanf("%d", &n);
	
	for(i=10; i<=n; ++i)
	{
		if(i%5 == 0 || i%7 == 0)
			printf("%d ", i);
	}
	
	return 0;
}
/*
在devc++中运行结果为
30
10 14 15 20 21 25 28 30
*/
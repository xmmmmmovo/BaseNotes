# include<stdio.h>
# include<math.h>

int dengcha(int n)
{
	int sum = 0;
	int i;
	
	for(i=1; i<=n; ++i)
		sum += i;
	
	return sum;
}

int main(void)
{
	int m;
	int i;
	int sum;
	
	scanf("%d", &m);
	
	for(i=1; dengcha(i)<m; ++i)
	{
		sum = dengcha(i);
	}
	
	printf("%d", i-1);
	
	return 0;
}

/*
在devc++中的运行结果为
155
17
*/
# include<stdio.h>
# include<stdbool.h>

int shx(int n)
{
	int sum = 0;
	
	do
	{
		sum += (n%10) * (n%10) * (n%10);
		n /= 10;
	}while(n > 0);
	
	
	return sum;
}

int main(void)
{
	int n, i;
	int sum;
	int k = 0;
	
	scanf("%d", &n);
	
	for(i=100; i<=n; ++i)
	{	
		sum = shx(i);
		if(sum == i)
		{
			printf("%d ", i);
			k += 1;
		}
	}
	
	printf("\n%d", k);
	
	return 0;
}
/*
在devc++中的运行结果为
5000
153 370 371 407
4
*/

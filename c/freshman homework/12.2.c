# include<stdio.h>
# include<stdbool.h>

bool num(int n)
{
	int i, sum = 0;
	
	for(i=1; i<n; i++)
	{
		if(n%i == 0)
			sum += i;
		else
			continue;
	}
	
	if(sum == n)
		return true;
	else
		return false;
	
}

int main(void)
{
	int n, i;
	
	scanf("%d", &n);
	
	for(i=10; i<=n; ++i)
	{
		if(num(i))
			printf("%d ", i);
	}
	
	return 0;
}
/*
在devc++中的运行结果为
999
28 496
*/

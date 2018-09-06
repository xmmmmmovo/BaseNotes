# include<stdio.h>

int caculate(int n, int *num, int nx)
{
	if(n < 4 && n > 0)
		return 0;
	else if(nx == n)
		return *num;
	else
		*num += n/4;
		caculate(n, num, ++nx);
	return *num;
}

int main(void)
{
	int n, num = 1;
	
	while(~scanf("%d", &n))
	{
		if(n == 0)
			return 0;
		caculate(n, &num, 1);
		printf("%d\n", num);
	}
	
	return 0;
}

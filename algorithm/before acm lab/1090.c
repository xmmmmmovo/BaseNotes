# include<stdio.h>

int main(void)
{
	int n;
	int a, b;
	int i;
	
	scanf("%d", &n);
	for(i=0; i<n; ++i)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", a+b);
	}
	
	return 0;
}

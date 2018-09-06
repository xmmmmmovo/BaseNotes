# include<stdio.h>

int fun(int * p)
{
	int i;
	int j = 0;
	
	for(i=0; i<5; i++)
	{
		j = j + *(p + i);
	}
	
	return j;
}

int main(void)
{
	int a[5];
	int i;
	
	for(i=0; i<5; ++i)
	  scanf("%d", &a[i]);
	
	printf("%d", fun(a));
	
	return 0;
}

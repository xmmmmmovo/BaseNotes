# include<stdio.h>
# include<malloc.h>

void sort(int *num)
{
	
}

int array(int *num, int j, int i)
{
	int k = 2;
	
	while(k--)
	{
		while(j<i)
		{
			num[j] = num[++j];
		}
	}
	
	for(j=0; j<i; ++j)
		printf("%d ", num[j]);
	printf("\n");
	
	return 0;
}

int main(void)
{
	int n, s;
	int i = 0, j, k;
	int num[240] = {0}, temp[240];
	
	scanf("%d%d", &n, &s);
	while(n > 0)
	{
		num[i] = n % 10;
		n /= 10;
		++i;
	}
	
	for(j=0; j<i; ++j)
	{
		for(k=0; k<i; ++k)
			temp[k] = num[k];
		array(temp, j, i);
	}
	
	return 0;
}

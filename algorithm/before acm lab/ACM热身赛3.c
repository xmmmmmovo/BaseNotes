# include<stdio.h>
# include<malloc.h>

void sort(int *num, int n)
{
	int i, j, swap;
	
	for(i=0; i<n-1; ++i)
	{
		for(j=0; j<n-1-i; ++j)
		{
			if(num[j] > num[j+1])
			{
				swap = num[j];
				num[j] = num[j+1];
				num[j+1] = swap;
			}
		}
	}
}

int main(void)
{
	int n, i = 0;
	
	scanf("%d", &n);
	int *num = (int *)malloc(sizeof(int) * n);
	
	while(~scanf("%d", num+i))
	{
		if(n == ++i)
			break;
	}
	
	sort(num, n);
	for(i=0; i<n; i++)
		printf("%d\n", *(num+i));
	
	return 0;
}

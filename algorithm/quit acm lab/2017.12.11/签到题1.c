# include<stdio.h>
# include<malloc.h>

void sort(int *num, int n)
{
	int i, j, temp;
	
	for(i=0; i<n-1; ++i)
	{
		for(j=0; j<n-1-i; ++j)
		{
			if(num[j] > num[j+1])
			{
				temp = num[j+1];
				num[j+1] = num[j];
				num[j] = temp;
			}
		}
	}
}

int main(void)
{
	int n, num;
	int i, j;
	
	scanf("%d", &n);
	for(i=0; i<n; ++i)
	{
		scanf("%d", &num);
		
		int *numall = (int *)malloc(sizeof(int) * num);
		
		for(j=0; j<num; ++j)
			scanf("%d", &numall[j]);
		sort(numall, num);
		
		for(j=0; j<num-1; ++j)
			printf("%d ", numall[j]);
		printf("%d\n", numall[j]);
		
		free(numall);
	}
	
	return 0;
}
/*
Sample Input
2
3 2 1 3
9 1 4 7 2 5 8 3 6 9
Sample Output
1 2 3
1 2 3 4 5 6 7 8 9
*/

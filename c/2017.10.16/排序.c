# include<stdio.h>
# include<malloc.h>

int main(void)
{
	int n;
	int i;
	int j = 0;
	int k = 0;
	
	scanf("%d", &n);
	int * p = (int *)malloc(sizeof(int) * n);
	int * q = (int *)malloc(sizeof(int) * n);
	
	for(i=0; i<n; ++i)
		scanf("%d", (p+i));
	printf("\n");
		
	for(i=0; i<n; ++i)
	{
		if(*(p+i) == 0)
		{
			*(q+n-1-k) = *(p + i);
			k++;
		}
		else
		{
			*(q + j) = *(p + i);
			j++;
		}
	}
	
	for(i=0; i<n; ++i)
		printf("%d ", *(q + i));
	
	return 0;
}

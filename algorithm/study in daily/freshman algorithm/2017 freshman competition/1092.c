# include<stdio.h>
# include<malloc.h> 

int main(void)
{
	int n;
	int a, b;
	int i;
	int sum = 0;
	
	while(1)
	{
		sum = 0;
		
		scanf("%d", &n);
		if(n == 0)
			break;
		else
		{
			int *num = (int *)malloc(sizeof(int) * n);
			
			for(i=0; i<n; ++i)
			{
				scanf("%d", num + i);
				sum += *(num + i);
			}
			
			printf("%d\n", sum);
		}
	}
	
	return 0;
}

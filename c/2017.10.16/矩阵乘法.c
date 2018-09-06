# include<stdio.h>
# include<malloc.h>

int main(void)
{
	int x1y2, x2y1, y1, y2;
	int i, j, k, sum;
	
	scanf("%d %d", &x1y2, &x2y1);//x1y2 1的列2的行 x2y1 1的行2的列 
	int **num1 = (int **)malloc(sizeof(int) * x2y1);
	int **num2 = (int **)malloc(sizeof(int) * x1y2);
	int **num3 = (int **)malloc(sizeof(int) * x1y2);
	
	for(i=0; i<x2y1; ++i)
	{
		num3[i] = (int *)malloc(sizeof(int) * x1y2);
		num1[i] = (int *)malloc(sizeof(int) * x2y1);
		for(j=0; j<x1y2; ++j)
			scanf("%d", &num1[i][j]);
	}
	for(i=0; i<x1y2; ++i)
	{
		num2[i] = (int *)malloc(sizeof(int) * x1y2);
		for(j=0; j<x2y1; ++j)
			scanf("%d", &num2[i][j]);
	}
	
	for(i=0; i<x2y1; ++i)
	{
		for(j=0; j<x1y2; ++j)
		{
			sum = 0;
			for(k=0; k<x2y1; ++k)
				sum += num1[k][j] * num2[j][k];
			num3[i][j] = sum;
		}
	}
	
	for(i=0; i<x1y2; ++i)
	{
		printf("\n");
		for(j=0; j<x2y1; ++j)
			printf("%d ", num3[i][j]);
	}
	
	return 0;
}

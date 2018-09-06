# include<stdio.h>
# include<malloc.h>

int main(void)
{
	int i, j, k;
	int n; 
	
	scanf("%d", &n);//ÊäÈëĞĞÊın
	int **num = (int **)malloc(sizeof(int *) * (n+1));
	for(i=0; i<(n+1); ++i)
		num[i] = (int *)malloc(sizeof(int) * (n+1));
	
	//num[1][1] = 0;
	
	for(i=0; i<(n+1); ++i)
	{
		for(j=i; j<n; ++j)
			printf(" ");
		
		num[i][0] = 1;
		//num[i][i] = 1;
		printf("%d ", num[i][0]);
		
		for(j=1; j<=(i/2); ++j)
		{
			num[i][j] = num[i-1][j] + num[i-1][j-1];
			printf("%d ", num[i][j]);
		}
		
		k = (i/2) + 1;
		if(i != 0)
		{
			if(i%2 == 0)
				j--;
			while(j--)
			{
				num[i][k] = num[i][j];
				printf("%d ", num[i][k]);
				k++;
			}
		}
		
		puts("\n");
	}
	
	return 0;
}

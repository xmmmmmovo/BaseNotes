# include<stdio.h>
# include<malloc.h>

int main(void) 
{
	int i, j;
	int n;
	int k = 0;
	int sum1 = 0, sum2 = 0;
	
	scanf("%d", &n);//���뼸������
	
	int num[n][n];
	
	for(i=0; i<n; ++i)
	{
		for(j=0; j<n; j++)
		{
			num[i][j] = k;
			++k;
		}
	}
	
	for(i=0; i<n; ++i)
		sum1 += num[i][i];
	
	for(i=(n-1); i>=0; --i)
		sum2 = num[n-i-1][i];
		
	printf("���Խ��ߣ�%d\n���Խ��ߣ�%d", sum1, sum2);
	
	
	
	return 0;
}

# include<stdio.h>

int main(void)
{
	int i;
	int n;
	int a;
	
	printf("请输入要求的菱形边长\n");
	scanf("%d", &n);
	
	for(i=0; i<(2*n+1); ++i)
	{
		if(i < n)
		{
			for(a=0; a<(n-i); ++a)
				printf(" ");
			for(a=0; a<(2*i+1); ++a)
				printf("*");
		}
		else if(i == n)
		{
			for(a=1; a<(2*(n+1)); ++a)
				printf("*");
		}
		else
		{
			for(a=0; a<(i-n); ++a)
				printf(" ");
			for(a=0; a<(2*(2*n-i)+1); ++a)
				printf("*");
		}
		
		printf("\n");
	}
	
	return 0;
} 

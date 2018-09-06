# include<stdio.h>
# include<malloc.h>

int main(void)
{
	int n;
	int i;
	int * p;
	
	printf("请输入前多少以内的数\n");
	scanf("%d", &n);
	
	p = (int *)malloc(sizeof(int) * n);
	
	for(i=0; i<n; ++i)
	{
		if(i<2)
		{
			*(p+i) = 1;
			printf("1 ");
		}
		else
		{
			*(p+i) = *(p+i-1) + *(p+i-2);
			if(*(p+i) > n)
			 	break;
			printf("%d ", *(p+i));
	    }
	}
	
	return 0;
} 

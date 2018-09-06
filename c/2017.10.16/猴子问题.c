# include<stdio.h>

int main(void)
{
	int y = 1;
	int i;
	
	for(i=0; i<10; ++i)
	{
		y = 2 * (y+1);
	}
	
	printf("%d", y);
	
	return 0;
}

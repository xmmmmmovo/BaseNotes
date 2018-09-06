# include<stdio.h>

int  tower(int n, int i) 
{
	int lf = 0;
	
	if(n < 0)
		return i-1;
	tower(n-(2*i + (i-1)), ++i);
}

int main(void)
{
	int n, lf;
	
	while(~scanf("%d", &n))
		printf("%d\n", tower(n, 1));
	
	return 0;
}
/*
	扑克塔问题
	输出层数
	2017.12.06 
*/

# include<stdio.h>

int main(void)
{
	int m;
	
	scanf("%d", &m);
	
	if(m < 1 || m > 12)
		puts("error!");
	else if(m == 4 || m == 6 ||
			 m == 9 || m == 11)
		puts("30");
	else if(m == 2)
		puts("28");
	else
		puts("31");
	
	return 0;
}
/*
在devc++中的运行结果为
1
31
*/
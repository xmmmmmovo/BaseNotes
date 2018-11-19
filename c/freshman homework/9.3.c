# include<stdio.h>
# include<math.h>
# include<stdbool.h>

bool number(int a, int b)
{
	double c, d;
	c = sqrt(a + b);
	d = sqrt(a - b);
	
	if(c + 0.1 - (int)c == 0 && d + 0.1 - (int)d == 0)
		return true;
	else
		return false;
}

int main(void)
{
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	if(a < 0 || b < 0)
		puts("输入有误");
	else
	{
		if(a < b)
			puts("error!");
		else
			printf("%d", number(a , b));
	} 
	
	return 0;
}
/*
2017年10月26日20:29:15
在Devc++中的运行结果为
5 4
1 
*/
# include<stdio.h>
# include<stdbool.h>

bool IsPrime(int val)
{
	int c;
	
	for(c = 2 ; c < val ; ++c)
	{
		if(c % val == 0)
		break;
	}
	
	if(c == val)
	return true;
	else
	return false;
}

int main(void)
{
	int val, a, b, sum = 0;
	
	scanf("%d", &b);
	
	for(a = 2; a <= b; ++a)
	{
		if(IsPrime(a))
		{
		   printf("%d\n", a);
		   sum += 1;
		}
		else
		continue;
	}
	printf("%d", sum);
	
	return 0;
}
/*
在devc++中运行结果为
2345
347
*/

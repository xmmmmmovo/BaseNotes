# include<stdio.h>

int str(char * p)
{
	int i = 0;
	int sum = 0;
	
	while(*(p + i) != '\0')
	{
		i ++;
		sum ++;
	}
	
	return sum;
}

int main(void)
{
	char a[] = "fuck you";
	
	printf("%d", str(a));
	
	return 0;
}

/*
函数 字符串的长度 
*/

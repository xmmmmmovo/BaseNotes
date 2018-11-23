# include<stdio.h>
# include<malloc.h>

int main(void)
{
	char ch[80];
	int i = 0, sum = 0;
	
	gets(ch);
	while(ch[i] != '\0')
	{
		if((ch[i]>=65 && ch[i]<=90) || (ch[i]>=97 && ch[i]<=122))
			sum++;
		++i;
	}
	
	printf("%d", sum);
	
	return 0;
}
/*
要求程序运行时接收从键盘输入的字符串（长度均不超过80），
请统计并输出字符串中英文字母（大小写一起统计）的个数

在devc++中的运行结果为
qwero123489][\
5
*/
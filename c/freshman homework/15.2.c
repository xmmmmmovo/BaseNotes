# include<stdio.h>
# include<malloc.h>

int main(void)
{
	char ch[2][80];
	int i, j;
	
	for(i=0; i<2; ++i)
		gets(ch[i]);
		
	printf("%s", ch[0]);
	
	i = 0;
	while(ch[1][i]!='\0')
	{
		printf("%c", ch[1][i]);
		i += 2;
	}
	
	return 0;
}
/*
要求程序运行时接收从键盘输入的两个字符串（长度均不超过80），
并将第二个字符串中奇数位置上的字符顺序连接到第一个字符串的末尾

在devc++中的运行结果为
wo qowe
fucker
wo qowefce
*/
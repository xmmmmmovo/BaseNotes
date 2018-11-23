# include<stdio.h>

int main(void)
{
	char ch, a;
	
	printf("请输入一个大写字母\n");
	scanf("%c", &ch);
	
	ch += 32;
	a = ch + 1;
	
	printf("%c\n", ch);
	printf("%c\n", a);
	
	return 0;
}
/*
2017年10月13日17:30:27
在devcpp中的输出结果为
请输入一个大写字母
A
a
b
*/
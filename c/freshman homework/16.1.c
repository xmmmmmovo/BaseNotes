# include<stdio.h>
# include<stdbool.h>
# include<string.h>
# include<malloc.h>

int string(char (*ch)[2][80])
{
	int i=0, j=0;
	int a, b;
	char str[2][41];
	
	while(((*ch)[0][j]!='\0')&& ((*ch)[1][j]!='\0'))
	{
		str[0][j] = (*ch)[0][i];
		str[1][j] = (*ch)[1][i];
		i += 2;
		j++;
	}
	
	a = strlen(str[0]);
	b = strlen(str[1]);
	
	if(a > b)
		return 1;
	else if(a == b)
		return 0;
	else
		return -1;	
}

int main(void)
{
	char ch[2][80];
	int i;
	
	for(i=0; i<2; ++i)
		gets(ch[i]);
	
	printf("%d", string(&ch));
	
	return 0;
}
/*
接收从键盘输入的两个字符串（长度均不超过80），
请分别对两个字符串中奇数位置上的字符形成的两个
子串比较大小，若第一个子串大于第二个子串，
输出1，若第一个子串等于第二个子串，输出0，否则输出-1。

在devc++中的运行结果为
qwewqe
gdfgdfgdfg
-1
*/
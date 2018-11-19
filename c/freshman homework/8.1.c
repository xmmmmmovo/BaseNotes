# include<stdio.h>

int main(void)
{
	char ch;
	
	scanf("%c", &ch);
	
	if(ch >= 48 && ch <= 57)
		printf("It is a digit");
	else if(ch >=65 && ch <= 90 ||
			ch >= 97 && ch <= 122)
		printf("It is an alphabetic character");
	else
		printf("It is other character");
	
	return 0;
}
/*
在devc++中的运行结果为
a
It is an alphabetic character
*/

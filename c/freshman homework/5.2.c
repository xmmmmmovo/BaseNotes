# include<stdio.h>

int main(void)
{
	char ch, a;
	
	printf("������һ����д��ĸ\n");
	scanf("%c", &ch);
	
	ch += 32;
	a = ch + 1;
	
	printf("%c\n", ch);
	printf("%c\n", a);
	
	return 0;
}
/*
2017��10��13��17:30:27
��devcpp�е�������Ϊ
������һ����д��ĸ
A
a
b
*/
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
Ҫ���������ʱ���մӼ�������������ַ��������Ⱦ�������80����
�����ڶ����ַ���������λ���ϵ��ַ�˳�����ӵ���һ���ַ�����ĩβ

��devc++�е����н��Ϊ
wo qowe
fucker
wo qowefce
*/
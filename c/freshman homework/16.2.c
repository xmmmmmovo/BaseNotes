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
Ҫ���������ʱ���մӼ���������ַ��������Ⱦ�������80����
��ͳ�Ʋ�����ַ�����Ӣ����ĸ����Сдһ��ͳ�ƣ��ĸ���

��devc++�е����н��Ϊ
qwero123489][\
5
*/
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
���մӼ�������������ַ��������Ⱦ�������80����
��ֱ�������ַ���������λ���ϵ��ַ��γɵ�����
�Ӵ��Ƚϴ�С������һ���Ӵ����ڵڶ����Ӵ���
���1������һ���Ӵ����ڵڶ����Ӵ������0���������-1��

��devc++�е����н��Ϊ
qwewqe
gdfgdfgdfg
-1
*/
# include<stdio.h>

int main(void)
{
	char str1[20] = {'\0'}, str2[40] = {'\0'};
	char ch;
	int i = 0, j = 0;
	
	gets(str1);
	//getchar();
	scanf("%c", &ch);
	
	while(1)
	{
		str2[j] = str1[i];
		i++;//��ǰ�Լ�,�Ա��ж���һ�ַ� 
		if(str1[i] == '\0')
			break;
		str2[++j] = ch;
		j ++;
	}
	
	printf("%s", str2);
	
	return 0;
}
/*
	��ҵ19
���ַ���Ϊ�ڴ�ռ�ý϶�ķ���
����cpuռ�ý϶���㷨��ѭ�������϶ࣩ
���������������㷨�� 
	2017.12.01
*/

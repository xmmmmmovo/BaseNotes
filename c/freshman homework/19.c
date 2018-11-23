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
		i++;//提前自加,以便判断下一字符 
		if(str1[i] == '\0')
			break;
		str2[++j] = ch;
		j ++;
	}
	
	printf("%s", str2);
	
	return 0;
}
/*
	作业19
此种方法为内存占用较多的方法
另有cpu占用较多的算法（循环次数较多）
（类插入排序后移算法） 
	2017.12.01
*/

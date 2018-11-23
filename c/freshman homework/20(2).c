# include<stdio.h>
# include<string.h>
# include<stdbool.h>

bool match(char *str, char *str1, int *s)
{
	int i;
	int n = strlen(str);
	int m = strlen(str1);
	
	for(*s; *s<=n-m; ++*s)
	{
		for(i=0; i<m; ++i)
		{
			if(str[*s+i] != str1[i])
				break;
			if(i == m-1)
				return true;
		}
	}
	return false;
}

void replace(char *str, char *str1, char *str2)
{
	int i, j, s = 0;
	
	if(strlen(str1) != strlen(str2))
	{
		printf("error!");
		return;
	}
	
	for(i=0; str[i] != '\0'; ++i)
	{
		if(match(str, str1, &s))
		{
			for(j=0; j<strlen(str2); ++j)
				str[j+s] = str2[j];
			i = strlen(str1) + s;
			s = i - 1;
		}
	}
}

int main(void)
{
	char str[80], str1[40], str2[40];
	
	gets(str);
	gets(str1);
	gets(str2);
	
	replace(str, str1, str2);
	printf("%s", str);
	
	return 0;
}
/*
	作业20
	改进版V1
	函数名即为功能名 
	2017.12.02 
*/ 

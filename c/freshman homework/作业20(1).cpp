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

int replace(char *str, char *str1)
{
	int i, j, s = 0, time = 0;
	
	for(i=0; str[i] != '\0'; ++i)
	{
		if(match(str, str1, &s))
		{
			time++;
			i = strlen(str1) + s;
			s = i - 1;
		}
	}
	
	return time;
}

int main(void)
{
	char str[80], str1[40], str2[40];
	
	gets(str);
	gets(str1);
	
	printf("%d", replace(str, str1));
	
	return 0;
}
/*
ื๗าต20
2017.12.08 
*/

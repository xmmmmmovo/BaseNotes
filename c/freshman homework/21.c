#include<stdio.h>
#include<string.h>

void sort(char *,char *,char *);
int main ()
{
	char str1[100] = {'\0'};
	char str2[100] = {'\0'};
	char str3[100] = {'\0'};
	
	gets(str1);
	gets(str2);
	gets(str3);
	
	sort(str1,str2,str3);
	
	printf("%s\n",str1);
	printf("%s\n",str2);
	printf("%s\n",str3);
	
	return 0;
}

void sort(char *a,char *b,char *c)
{
	int i;
	char d[100] = {'\0'};
	if(strcmp(a,b)<0)
		{
			strcpy(d,a);
			strcpy(a,b);
			strcpy(b,d);
		}
	else if(strcmp(a,c)<0)
		{
			strcpy(d,a);
			strcpy(a,c);
			strcpy(c,d);
		}
	else if(strcmp(b,c)<0)
		{
			strcpy(d,b);
			strcpy(b,c);
			strcpy(c,d);
		}
}

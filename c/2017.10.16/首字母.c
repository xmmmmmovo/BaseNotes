# include<stdio.h>

int main(void)
{
	char a[100];
	int i = 1;
	
	gets(a);
	
	printf("%c", a[0] - 32);
	do
	{
		if(a[i] == ' ')
		{
			printf("%c", a[i]);
			a[i+1] -= 32;
		}
		else
			printf("%c", a[i]);
		
		++i;
	}while(a[i] != '\0'); 
	
	return 0;
}

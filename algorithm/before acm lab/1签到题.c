# include<stdio.h>
# include<string.h>

int main(void)
{
	int n, i, k=0;
	char ch[100][100];
	
	scanf("%d", &n);
	getchar();
	
	for(i=0; i<n; ++i)
	{
		scanf("%s", &ch[i]);
		k = 0;
		
		do
		{
			ch[i][k] += 32;			
			k++; 
		}while(ch[i][k] != '\0');
		
		printf("%s", ch[i]);
	}
	
	return 0;
}
/*
在devc++中的运行结果为
1990
0
*/

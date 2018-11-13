# include<stdio.h>

int main(void)
{
	/*char a, b;
	scanf("%c %c", &a, &b);
	printf("%d", a+b);
	*/
	int num[100] = {1};
	int i = 0;
	int sum = 0;
	char ch;
	
	while(1)
	{
		do
		{
			scanf("%d", &num[i]);
			ch = getchar();
			i++;
		}while(ch != '\n');
		
		if(num[0] == 0)
			break;
		
		for(i=0; num[i] != 0; ++i)
			sum += num[i];
			
		printf("%d", sum);
	}
	
	return 0;
}
/*
 1 2 3 4
 10
 1 2 3 4 5
 15
 0 

*/

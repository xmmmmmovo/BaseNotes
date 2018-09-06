# include<stdio.h>

int sql(int a)
{
	int b;
	b = 0; 
	
	if(a > 999 || a < 100)
	  {
	  	printf("请输入三位数！\n");
	  }
	else
	{
	   do
	   {
		  b += a%10;
		  a /= 10;
	   }while(a > 0);
	   printf("%d\n", b);
    }
	
	return 0;
}

int tf(void)
{
	char ch;
	int a;
	
	do
	{
	   printf("请输入一个三位数\n");
	   scanf("%d", &a);
	   sql(a);
	   printf("是否继续？");
	   scanf(" %c", &ch);
	}while('Y' == ch || 'y' == ch);
	
}

int main(void)
{
	tf();

	return 0;
}



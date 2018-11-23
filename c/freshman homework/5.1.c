# include<stdio.h>

int main(void)
{
	int a, b;
	a = b = 0;
	
	printf("请输入一个三位数\n");
	scanf("%d", &a); 
	
	if(a > 999 || a < 100)
	  {
	  	printf("请输入三位数！");
	  }
	else
	{
	   do
	   {
		  b += a%10;
		  a /= 10;
	   }while(a > 0);
	   printf("%d", b);
    }
	
	return 0;
}
/*
2017年10月13日17:30:27
在devcpp中的输出结果为
 
请输入一个三位数 
233
8

请输入一个三位数
5555
请输入三位数！
*/

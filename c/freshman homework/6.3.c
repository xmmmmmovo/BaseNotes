# include<stdio.h>

void f(int a, int * p)
{
    int b; 
    printf("换回%d的零钱数量为 %d\n",a , *p/a);
    *p %= a;
}

int main(void)
{
	int sum; 
		
	printf("请输入您想换零钱的金额\n");
	scanf("%d",&sum);
	
	f(100 , &sum);
	f(50 , &sum);
	f(20 , &sum);
	f(10 , &sum);
	f(5 , &sum);
	f(1 , &sum); 
	
	return 0;
}
/*
2017年10月13日17:30:27
在devcpp中的输出结果为

请输入您想换零钱的金额
565
换回100的零钱数量为 5
换回50的零钱数量为 1
换回20的零钱数量为 0
换回10的零钱数量为 1
换回5的零钱数量为 1
换回1的零钱数量为 0
*/
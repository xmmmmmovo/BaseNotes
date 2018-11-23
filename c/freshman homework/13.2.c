# include<stdio.h>
# include<malloc.h>

int main(void)
{
	int num[10];
	int i, sum = 0;
	
	for(i=0; i<10; ++i)
		scanf("%d", &num[i]);
		
	while(i--)
	{
		if(num[i] < 0)
			sum++;
	}
	
	printf("%d", sum);
	
	return 0;
}
/*

有一包含10个整数的数列（数据由键盘输入），计算并输出数列中非负数的个数。

在devc++中的运行结果为
1 2 3 4 -34 -45 6 7 8 9 -12
2
*/

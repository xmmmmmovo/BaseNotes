# include<stdio.h>
# include<malloc.h>

int main(void)
{
	int num[10];
	int i, max;
	
	for(i=0; i<10; ++i)
		scanf("%d", &num[i]);
	
	max = num[0];
	while(i--)
	{
		if(max < num[i])
			max = num[i];
	}
	
	printf("%d ", max); 
	
	return 0;
}
/*

求一个包含10个元素的整型数组中的最大元素值（数据由键盘输入）

在devc++中的运行结果为
1221 23234 54 7 67 878 88 666 554 33
23234
*/

# include<stdio.h>
# include<malloc.h>

int main(void)
{
	int i;
	int num[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
	int st, ed;
	
	scanf("%d %d", &st, &ed);
	for(i=0; i<(st-1); ++i)
		printf("%d ", num[i]);
	for(i=(ed-1); i>=(st-1); --i)
		printf("%d ", num[i]);
	for(i=ed; i<10; ++i)
		printf("%d ", num[i]); 
	
	return 0;
}
/*
有一包含10个整数的数列（数据在程序中初始化，分别是：
11 22 33 44 55 66 77 88 99 100），程序运行时，从小到大输入两个整数,
分别表示数列中连续的一段数据最左侧和最右侧两个数的位置
要求对连续的这段数据逆序存储，最后输出经过调整位置后的数列

在devc++中的运行结果为
2 6
11 66 55 44 33 22 77 88 99 100
*/

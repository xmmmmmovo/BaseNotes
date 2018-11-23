# include<stdio.h>
# include<malloc.h>

void Sort(int *num, int n)//n为数组长度 
{
	int i, k, j;
	
	for(i=0; i<(n-1); i++)
		for(k=0; k<(n-1-i); k++)
		{
			 if(*(num+k) > *(num+k+1))
			 {
			 	j = *(num+k);
			 	*(num+k) = *(num+k+1);
			 	*(num+k+1) = j;
			 }
		}
}
//冒泡排序 

int main(void)
{
	int num[10];
	int i;
	
	for(i=0; i<10; ++i)
		scanf("%d", &num[i]);
	
	Sort(num, 10);
	
	for(i=0; i<10; ++i) 
		printf("%d ", num[i]); 
	
	return 0;
}
/*

有一包含10个数的整数数列（程序运行时，数据由键盘输入），
完成对该数列从小到大排序，输出排序后的结果。

在devc++中的运行结果为
12 3 4 5 6 7 8 9 10 1
1 3 4 5 6 7 8 9 10 12
*/

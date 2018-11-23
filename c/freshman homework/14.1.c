# include<stdio.h>
# include<malloc.h>

float maxline(float num[])
{
	int i;
	float max = num[0];
	
	for(i=0; i<4; ++i)
		if(max < num[i])
			max = num[i];
	
	return max;
}

int main(void)
{
	float num[3][4];
	float max, temp; 
	int i, j;
	
	for(i=0; i<3; ++i)
		for(j=0; j<4; ++j)
			scanf("%f", &num[i][j]);
	
	for(i=0; i<3; ++i)
	{
		temp = maxline(num[i]);
		if(max < temp)
			max = temp;
	}
	
	printf("%.2f", max);
	
	return 0;
}
/*

有一3行4列矩阵，矩阵中各元素均为浮点数
（数据由键盘输入，所有数据值各不相同），
输出其中最大元素值（结果保留两位小数）

在devc++中的运行结果为
12 33 54 56
22 4554 678 456
12 44 5 6
4554.00
*/
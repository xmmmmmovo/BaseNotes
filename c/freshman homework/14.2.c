# include<stdio.h>
# include<malloc.h>

void numtransport(int (*num)[3][3], int(*num2)[3][3])
{
	int i, j;
	
	for(i=0; i<3; ++i)
		for(j=0; j<3; j++)
			(*num2)[j][i] = (*num)[i][j];	
}

int main(void)
{
	int num[3][3], num2[3][3];
	int i, j;
	
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			scanf("%d", &num[i][j]);
	
	numtransport(&num, &num2);
	puts("");//空行 
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
			printf("%d ", num2[i][j]);
		printf("\n");
	}

	return 0;
}
/*
有一3行3列的整数矩阵（数据由键盘输入），
输出该矩阵的转置矩阵

在devc++中的运行结果为
1 2 3
4 5 6
7 8 9

1 4 7
2 5 8
3 6 9
*/
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
	puts("");//���� 
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
			printf("%d ", num2[i][j]);
		printf("\n");
	}

	return 0;
}
/*
��һ3��3�е��������������ɼ������룩��
����þ����ת�þ���

��devc++�е����н��Ϊ
1 2 3
4 5 6
7 8 9

1 4 7
2 5 8
3 6 9
*/
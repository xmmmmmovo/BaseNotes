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

��һ3��4�о��󣬾����и�Ԫ�ؾ�Ϊ������
�������ɼ������룬��������ֵ������ͬ����
����������Ԫ��ֵ�����������λС����

��devc++�е����н��Ϊ
12 33 54 56
22 4554 678 456
12 44 5 6
4554.00
*/
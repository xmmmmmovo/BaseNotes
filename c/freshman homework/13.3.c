# include<stdio.h>
# include<malloc.h>

void Sort(int *num, int n)//nΪ���鳤�� 
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
//ð������ 

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

��һ����10�������������У���������ʱ�������ɼ������룩��
��ɶԸ����д�С����������������Ľ����

��devc++�е����н��Ϊ
12 3 4 5 6 7 8 9 10 1
1 3 4 5 6 7 8 9 10 12
*/

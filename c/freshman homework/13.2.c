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

��һ����10�����������У������ɼ������룩�����㲢��������зǸ����ĸ�����

��devc++�е����н��Ϊ
1 2 3 4 -34 -45 6 7 8 9 -12
2
*/

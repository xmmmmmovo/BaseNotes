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

��һ������10��Ԫ�ص����������е����Ԫ��ֵ�������ɼ������룩

��devc++�е����н��Ϊ
1221 23234 54 7 67 878 88 666 554 33
23234
*/

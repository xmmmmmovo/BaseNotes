# include<stdio.h>

int main(void)
{
	int a, b;
	a = b = 0;
	
	printf("������һ����λ��\n");
	scanf("%d", &a); 
	
	if(a > 999 || a < 100)
	  {
	  	printf("��������λ����");
	  }
	else
	{
	   do
	   {
		  b += a%10;
		  a /= 10;
	   }while(a > 0);
	   printf("%d", b);
    }
	
	return 0;
}
/*
2017��10��13��17:30:27
��devcpp�е�������Ϊ
 
������һ����λ�� 
233
8

������һ����λ��
5555
��������λ����
*/

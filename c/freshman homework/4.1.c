# include<stdio.h>

# define pi 3.1415926

int main(void)
{
	double r;
	
	printf("������������Բ�İ뾶\n");
	scanf("%lf", &r);
	
	printf("����Բ���ܳ�Ϊ��%.2lf\n", 2*pi*r );
	printf("����Բ�����Ϊ��%.2lf\n", pi*r*r);
	
	return 0;
}
/*
2017��10��12��19:56:16
��devcpp�е����н��Ϊ

������������Բ�İ뾶
2.33
����Բ���ܳ�Ϊ��14.64
����Բ�����Ϊ��17.06 
*/
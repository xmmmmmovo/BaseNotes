# include<stdio.h>

# define pi 3.1415926

int main(void)
{
	double r;
	
	printf("��������������İ뾶\n");
	scanf("%lf", &r);
	
	printf("������ı����Ϊ��%.2lf\n", 4*pi*r*2 );
	printf("����������Ϊ��%.2lf\n", (4/3.0)*pi*r*r*r );
	
	return 0;
}
/*
2017��10��12��19:56:16
��devcpp�е����н��Ϊ

������������İ뾶
2.33
������ı����Ϊ��58.56
����������Ϊ��39.74
*/
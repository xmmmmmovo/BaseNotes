# include <stdio.h>
# include <math.h>

int main(void)
{
	double a = 0;
	double b = 0;
	double c = 0;
	double delta;
	double x1, x2;
	
	printf("������a��b��c��ֵ���м��Կո�ָ���\n");
	scanf("%lf %lf %lf", &a, &b, &c);

	delta = b*b - 4*a*c;

	if (delta > 0)
	{
		x1 = (-b + sqrt(delta)) / (2*a);
		x2 = (-b - sqrt(delta)) / (2*a);
		printf("2��,x1 = %.2lf, x2 = %.2lf\n", x1, x2);
	}
	else if (delta == 0)
	{
		x1 = (-b) / (2*a);
		x2 = x1;
		printf("1��, x1 = x2 =%.2lf\n",x1);
	}
	else
	{
		printf("�޽�\n");
	}

	return 0;
}
/*
2017��10��13��20:06:42
��devcpp�еı�������

������a��b��c��ֵ���м��Կո�ָ���
2 3 4
�޽�
*/
# include<stdio.h>
# include<math.h>

int main(void)
{
	double a, b, c, p;
	
	printf("����������������������߳�(�м��Կո�ָ�)\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	p = (a + b + c) / 2;
	printf("���������ε����Ϊ��%.2lf\n", sqrt(p*(p-a)*(p-b)*(p-c)));
	
	return 0;
}
/*
2017��10��12��20:19:15
��devcpp�е����н��Ϊ

����������������������߳�(�м��Կո�ָ�)
3.1 3.2 3.3
���������ε����Ϊ��4.43
*/
# include<stdio.h>
# include<math.h>
# define g 9.8

int main(void)
{
	double h;
	
	printf("����������ĸ߶�\n");
	scanf("%lf", &h);
	
	printf("%.2lf", sqrt(2*h/g));
	
	return 0;
}
/*
2017��10��13��17:30:27
��devcpp�е�������Ϊ

����������ĸ߶�
9
1.36
*/
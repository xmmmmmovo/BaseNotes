# include<stdio.h>
# include<math.h>
# include<stdbool.h>

bool number(int a, int b)
{
	double c, d;
	c = sqrt(a + b);
	d = sqrt(a - b);
	
	if(c + 0.1 - (int)c == 0 && d + 0.1 - (int)d == 0)
		return true;
	else
		return false;
}

int main(void)
{
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	if(a < 0 || b < 0)
		puts("��������");
	else
	{
		if(a < b)
			puts("error!");
		else
			printf("%d", number(a , b));
	} 
	
	return 0;
}
/*
2017��10��26��20:29:15
��Devc++�е����н��Ϊ
5 4
1 
*/
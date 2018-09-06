# include<stdio.h>
# include<math.h>

double result(void)
{
	int n, m;
	int i, k;
	double x; 
	double result = 0;
	float fx[7] = {0};
		
	scanf("%d %d %lf", &n, &m, &x);//n 最高此项次数 m几阶导 x自变量 
	for(i=0; i<=n; ++i)
		scanf("%f", &fx[i]);
	
	for(i=1; i<=m; ++i)
		for(k=0; k<=n; ++k) 
			fx[k] *= (k+1-i);//求n阶导数 
		 
	k = 0;
	for(i=0; i<=n; ++i)
	{
		if(fx[i] != 0)
		{
			result += fx[i] * pow(x, k);
			k++;
		}
	}//求fx的值 
	
	return result;
}

int main(void)
{
	int k;
	int i;
	double re = 0;
	
	scanf("%d", &k);
	for(i=0; i<k; ++i)
	{
		re = result();
		printf("%.2lf", re);
		if(i != (k-1))
			printf("\n"); 
	} 
	
	return 0;
}

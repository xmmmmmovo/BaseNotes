# include<stdio.h>
# include<math.h>

int max(int a, int b)
{
	int t;
	
	if(a > b)
		t = a;
	else
		t = b;
	
	return t;
}

int main(void)
{
	int a, b;
	int i;
	
	scanf("%d %d", &a, &b);
	
	for(i=max(a,b); i>0; --i)
	{
		if(a%i == 0 && b%i == 0)
			break;
	}
	
	printf("%d %d", i, a*b/i);
	
	return 0;
}

/*
��devc++�е����н��Ϊ
1222 3456
2 2111616
*/

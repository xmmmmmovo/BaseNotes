# include<stdio.h>
# include<malloc.h>

typedef struct Milk
{
	char name[100];
	int price;
	int v;
}Milk;

int Milkday(Milk milk)
{
	if(milk.v > 1000)
		return 5;
	else if(milk.v < 200)
		return 0;
	else
		return milk.v/200;
}

int main(void)
{
	int n, nMilk, i, max = 0;
	
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &nMilk);
		Milk *milk = (Milk *)malloc(sizeof(Milk) * nMilk);
		float *day = (float *)malloc(sizeof(float) * nMilk);
		
		for(i=0; i<nMilk; ++i)
			scanf("%s %d %d", &milk[i].name, &milk[i].price, &milk[i].v);
		
		for(i=0; i<nMilk; ++i)
			day[i] = Milkday(milk[i])/milk[i].price;
		
		for(i=0; i<nMilk; ++i)
		{
			if(day[max] < day[i])
				max = i;
		}
		
		printf("%s\n", milk[max].name);
		free(day);
		free(milk);
	}
	
	return 0;
}

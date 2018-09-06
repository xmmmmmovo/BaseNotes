# include<stdio.h>
# include<stdbool.h>

bool rYear(int y)
{
		if((y%4 == 0 && y%100 != 0) || y%400 == 0)
			return true;
		else
			return false;
} 

int YearCount(int y, int m, int d)
{
	int ad = 0;
	int i;
	
	for(i=1990; i<y; ++i)
	{
		if(rYear(i))
			ad += 366;
		else
			ad += 365;
	}
	
	if(m>1)
	{
		for(i=1; i<(m+1); ++i)
		{
			if(i==4 || i==6 || i==9 || i==11)
				ad += 30;
			else if(i == 2)
			{
				if(rYear(y))
					ad += 29;
				else
					ad += 28;
			}
			else
				ad += 31;
		}
	}
	else
		ad += d;
	
	return ad;
}

int main(void)
{
	int i;
	int n;
	int y, m, d;
	int start = 1990;
	
	scanf("%d %d %d", &y, &m, &d);//输入年月日
	
	i = YearCount(y, m, d);
	if(i%5 == 1 || i%5 == 2 || i%5 == 3)
		printf("打渔");
	else
		printf("晒网");
	
	
	return 0;
}

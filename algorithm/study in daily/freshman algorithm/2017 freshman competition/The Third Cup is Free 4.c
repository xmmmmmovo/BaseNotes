# include<stdio.h>
# include<malloc.h>

int minprice(int *p,int j)
{
	int minprice = 0, i;
	
	for(i=1; i<=j; i++)
		minprice += p[i*3-1];
	
	return minprice;
}

void sort(int *p, int st, int ed)
{
	if(st >= ed)
		return;
	int low = st, high = ed;
	int i = p[low];
	
	while(low < high)
	{
		while(p[high] < i && high > low)
			high--;
		if(low < high)
			p[low++] = p[high];
		while(p[low] > i && high > low)
			low++;
		if(low < high)
			p[high--] = p[low];
	}
	
	p[low] = i;
	sort(p, st, low-1);
	sort(p, low+1, ed);
}
/*
	**快速排序**
	**重点学习** 
*/

int main(void)
{
	int t;
	int i = 1, n;
	int j, k = 0, sum = 0, min = 0, l;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		int *p = (int *)malloc(sizeof(int) * n);
		sum = 0;
		for(j=0; j<n; ++j)
		{
			scanf("%d", p+j);
			sum += p[j];
		}
		
		sort(p, 0, n-1);
		min = minprice(p, n/3);
		
		printf("Case #%d: %d\n", i++, sum-min);
		free(p);
	}
	
	return 0;
}

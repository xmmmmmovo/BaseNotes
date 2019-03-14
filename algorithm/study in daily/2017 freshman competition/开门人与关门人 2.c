# include<stdio.h>
# include<malloc.h>
# include<math.h>

int search(int **ta, int worker, int p)
{
	int m = 0, i;
	
	if(p == 1)
	{
		for(i=0; i<worker; ++i)
			if(ta[m][0] > ta[i][0])
				m = i;
	}
	else
	{
		for(i=0; i<worker; ++i)
			if(ta[m][1] < ta[i][1])
				m = i;
	}
	
	return m;
}

int main(void)
{
	int n;
	int worker, on, off;
	int i, j;
	
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &worker);
		
		char **name = (char **)malloc(sizeof(char *) * worker);
		int *t = (int *)malloc(sizeof(int) * 6);
		int **ta = (int **)malloc(sizeof(int *) * worker);
		for(i=0; i<worker; ++i)
		{
			name[i] = (char *)malloc(sizeof(char) * 15);
			ta[i] = (int *)malloc(sizeof(int) * 2);
			
			scanf("%s %d:%d:%d %d:%d:%d", name[i], t, t+1, t+2, t+3, t+4, t+5);
			
			ta[i][0] = *t * 10000 + *(t+1) * 100 + *(t+2);
			ta[i][1] = *(t+3) * 10000 + *(t+4) * 100 + *(t+5);
		}
		free(t);
		
		on = search(ta, worker, 1);
		off = search(ta, worker, 0);
		
		printf("%s %s\n", name[on], name[off]);
		
		free(ta);
		free(name);
	}
	
	return 0;
}

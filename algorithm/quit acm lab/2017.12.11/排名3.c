# include<stdio.h>
# include<malloc.h>

struct student
{
	int grade;
	char *name;
};

void sort(struct student *st, int k)
{
	int i, j, s;
	struct student temp;
	
	for(i=0; i<k-1; ++i)
		for(j=0; j<k-1-i; ++j)
		{
			if(st[j].grade < st[j+1].grade)
			{
				temp = st[j];
				st[j] = st[j+1];
				st[j+1] = temp;
			}
			else if(st[j].grade < st[j+1].grade)
			{
				for(s=0; s<20; ++s)
				{
					if(st[j].name[s] > st[j+1].name[s])
					{
						temp = st[j];
						st[j] = st[j+1];
						st[j+1] = temp;
					}
				}
			}
		}
			
}

int main(void)
{
	int n, M, G;
	int i, j, k = 0;
	
	while(~scanf("%d", &n) && n != 0)
	{
		/*
		输入模块 
		*/ 
		scanf("%d %d", &M, &G);
		int *indigrd = (int *)malloc(sizeof(int) * M);
		for(i=0; i<M; ++i)
			scanf("%d", indigrd+i);
		char **name = (char **)malloc(sizeof(char *) * n);
		int *gdall = (int *)malloc(sizeof(int) * n);
		for(i=0; i<n; ++i)
		{
			name[i] = (char *)malloc(sizeof(char) * 20);
			int *t = (int *)malloc(sizeof(int) * n);
			scanf("%s", name[i]);
			
			scanf("%d", t+i);
			int *qes = (int *)malloc(sizeof(int) * t[i]);
			gdall[i] = 0;
			for(j=0; j<t[i]; ++t)
			{				
				scanf("%d", qes+j);
				gdall[i] += indigrd[qes[j]];
			}
		}
		
		/*
		计算模块 
		*/
		struct student *st = (struct student *)malloc(sizeof(struct student) * n);
		for(i=0; i<n; ++i)
		{
			gdall[i] = 0;	
			if(gdall[i] >= G)
			{
				st[i].grade = gdall[i];
				st[i].name = name[i];
				++k;
			}
		}
		free(indigrd);
		free(gdall);
		
		sort(st, k);//排序 
		
		/*
		输出模块 
		*/
		printf("%d\n", k);
		for(i=0; i<k; ++i)
			printf("%s %d\n", st[i].name, st[i].grade);
		free(st);
		free(name);
	}
	
	
	return 0;
}

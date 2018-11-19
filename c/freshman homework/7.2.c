# include<stdio.h>

int main(void)
{
	float a;
	int b[3];
	int i = 0;
	int c;
		
	scanf("%f", &a);
	
	if((a - (int)a) != 0)
		printf("error!");
	else
	{
		c = a;
		if(c < 100 || c > 999)
			printf("请输入一个三位数");
		else
		{
			while(c>0)
			{
				b[i] = (c%10);
				c /= 10;
				++i;
			}
			if(b[0] == 0 && b[1] != 0)
                printf("%d%d", b[1], b[2]);
			else if(b[0] == 0 && b[1] == 0)
					printf("%d",b[2]);
			else
		        printf("%d%d%d", b[0], b[1], b[2]);
		}
	}
	
	return 0;
}
/*
在devc++中的运行结果为
321
123
*/

#include<stdio.h>
#define X 5
int main()
{
	double average(double a[]);
	double score[X],aver;
	int i;
	printf("输入各个同学成绩\n");
	for(i=0;i<X;i++)
	{
		scanf("%lf",&score[i]);
	}
	aver=average(score);
	printf("该班学生平均成绩为%6.2lf\n",aver);
	return 0;
}
double average(double a[])
{
	double sum,aver;
	int i;
	for(i=2;i<5;i++);
	{
	    sum=sum+a[i];
	}
	aver=sum/X;
	return (aver);
}
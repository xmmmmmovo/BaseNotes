# include<stdio.h>
int main(void)
{
    int x, a[32], i=0;
    
    printf("请输入一个十进制整数.\n");
    scanf("%d",&x);
    
    while(x!=0)
    {
        a[i++]=x%2;
        x=x/2;
    }
    
    for(i--;i>=0;i--)
        printf("%d",a[i]);
    
    printf("\n");
    
    return 0;
}
/*
2017年10月13日17:30:27
在devcpp中的输出结果为
请输入一个十进制整数.
9
1001

*/
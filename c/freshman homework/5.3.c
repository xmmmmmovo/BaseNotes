# include<stdio.h>
int main(void)
{
    int x, a[32], i=0;
    
    printf("������һ��ʮ��������.\n");
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
2017��10��13��17:30:27
��devcpp�е�������Ϊ
������һ��ʮ��������.
9
1001

*/
#include<stdio.h>
#include<stdlib.h>

int n = 0;
int count = 0;

void search(int *point, int lo, int hi)
{ 
    int i = 0;
    for(i=0; i<n; i++)
    {
        /* code */
        if ((point[i] >= lo) && (point[i] <= hi))
        {
            count ++;
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int i = 0;
    int m, lo, hi;

    scanf("%d %d", &n, &m);
    int *point = (int *)malloc(n * sizeof(int));

    for(i = 0;i < n;i++)
    {
        scanf("%d", (point + i));
    }

    for(i = 0;i < m ;i++)
    {
        scanf("%d %d", &lo, &hi);
        search(point, lo, hi);
        printf("%d", count);
    }

    //system("pause");
    return 0;
}
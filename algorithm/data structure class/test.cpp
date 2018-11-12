#include <stdio.h>
#include <stdlib.h>
int main()
{
    //定义一个指向文件类型的指针
    FILE *fp;
    fp = fopen("D:\\download\\text.txt","w");
    if(fp == NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }
    printf("打开文件成功！\n");

    char ch; //定义一个字符串
    int i = 0;
    while((ch = getchar()) != '\n')
    {
        i = fputc(ch,fp);  // 以字符为单位，写入到text.txt文件
        if(i == -1)
        {
            puts("字符写入失败！");
            exit(0);
        }
    }
    fclose(fp);
    return 0;
}
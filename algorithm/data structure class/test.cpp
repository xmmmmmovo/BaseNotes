#include <stdio.h>
#include <stdlib.h>
int main()
{
    //����һ��ָ���ļ����͵�ָ��
    FILE *fp;
    fp = fopen("D:\\download\\text.txt","w");
    if(fp == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
        exit(0);
    }
    printf("���ļ��ɹ���\n");

    char ch; //����һ���ַ���
    int i = 0;
    while((ch = getchar()) != '\n')
    {
        i = fputc(ch,fp);  // ���ַ�Ϊ��λ��д�뵽text.txt�ļ�
        if(i == -1)
        {
            puts("�ַ�д��ʧ�ܣ�");
            exit(0);
        }
    }
    fclose(fp);
    return 0;
}
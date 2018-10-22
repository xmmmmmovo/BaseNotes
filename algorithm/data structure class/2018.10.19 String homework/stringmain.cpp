#include<cstdio>
#include<cmath>
#include<cstdlib>

int strlen(char *str){
    int i = 0;
    for(i = 0; str[i] != '\0'; i++);
    return i;
}

void strassgin(char *str1, char ch){
    for(int i = 0;i < strlen(str1);i++)
    {
        str1[i] = ch;
    }
}

void strcopy(char *str1, char *str2){
    for(int i = 0;i < strlen(str1);i++)
    {
        str1[i] = 0;
    }
    for(int i = 0;i < strlen(str2);i++)
    {
        str1[i] = str2[i];
    }
}

bool strequal(char *str1, char *str2){
    if(strlen(str1) == strlen(str2))
        return true;
    else
        return false;
}

void strcmp(char *str1, char *str2){
    int i = 0, j = 0;
    for(i = strlen(str1), j = 0; str2[j] != '\0';i++, j++)
    {
        str1[i] = str2[j];
    }
}

//输出全部子串
void strsons(char *str){
    int lenth = strlen(str);
    int succ = lenth;
    while(lenth--){
        for(int i = 0;i+lenth <= succ;i++)
        {
            for(int j = i;j < lenth + i;j++)
            {
                printf("%c", str[j]);
            }

            printf(" ");
        }
        printf("\n");
    }
}

void substring(char *str, int pos, int lenth){
    if(str[pos] == '\0' || pos-- > strlen(str)){
        printf("out of list!");
        return;
    }
    for(int i = pos;i + lenth <= strlen(str);i++)
    {
        for(int j = i;j < lenth + i;j++)
        {
            printf("%c", str[j]);
        }
        printf(" ");
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    char str1[20] = {'\0'}, str2[20] = {'\0'};

    scanf("%s", str1);
    strcopy(str2, str1);
    printf("%s\n%s\n", str1, str2);
    printf("%d\n", strequal(str1, str2));
    //strcmp(str1, str2);
    printf("%s\n", str1);
    strsons(str1);
    substring(str1, 2, 2);

    system("pause");
    return 0;
}

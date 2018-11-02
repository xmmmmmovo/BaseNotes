#include <cstdio>
#include <cstdlib>
#include <cmath>

int strlength(char *str){
    int i = 0;
    for(i = 0;str[i] != '\0' ;i++);
    return i;
}

int strcompare(char *str1, char *str2){
    int i = 0, cout1, cout2, lenth1, lenth2;
    if((lenth1 = strlength(str1))>(lenth2 = strlength(str2))){
        return 1;
    }else if(lenth1 < lenth2){
        return -1;
    }

    for(i = 0;i < lenth1;i++){
        cout1 += (int)str1[i];
        cout2 += (int)str2[i];
    }

    if(cout1 > cout2){
        return 1;
    }else if(cout1 == cout2){
        return 0;
    }else{
        return -1;
    }
}

void replace(char *mstr, char *str, char *repstr){
    for(int i = 0;i < strlength(mstr);i++){
        if(mstr[i] == str[i]){
            int j = 0;
            
            for(j = i; j < strlength(str) + i; j++){
                if(mstr[j] != str[j]){
                    i = j;
                    break;
                }
            }

            if(i != j){
                for(i ;i < j; i++){
                    mstr[i] = repstr[i];
                }
                i = j;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    char *str1, *str2, *str3;
    str1 = (char*)malloc(sizeof(char) * 20);
    str2 = (char*)malloc(sizeof(char) * 20);
    str3 = (char*)malloc(sizeof(char) * 20);

    scanf("%s", str1);
    scanf("%s", str2);

    printf("%d\n", strcompare(str1, str2));

    scanf("%s", str3);
    replace(str1, str2, str3);
    printf("%s\n", str1);

    system("pause");
    return 0;
}

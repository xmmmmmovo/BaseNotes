#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct node{
    char data;
    struct node *next;
}linkstrnode;
typedef linkstrnode *nodestr;

void strinsert(nodestr *s, int i, nodestr T){
    int k = 1;
    nodestr p, q;
    p = *s;
    while (p && k < i-1) {
        p = p->next;
        k++;
    }
    if (!p) printf("error\n");
    else {
         q = T;
         while (q && q->next)   q = q->next;
         q->next = p->next;
         p->next = T;
    }
}

void strdele(nodestr *S,int i, int len)
{
    int k = 1;
    nodestr p, q, r;
    p = *S; q = NULL;
    while (p && k<i) {
        q = p;  p = p->next; k++;
    }
    if (!p) printf("error1\n");
    else
    {
        k = 1;
        while(k<len && p) {
            p = p->next;    k++;
        }
        if (!p) printf("error2\n");
        else {
            if(!q)  {r = *S;    *S = p->next;}
            else
                { r = q->next;    q->next = p->next; }
            p->next = NULL;
            while(r != NULL)
            { p = r; r = r->next; free(p); }
        }
    }
}

void *strconcat (nodestr *s1,nodestr s2){
    nodestr p;
    if(!(*s1))
        *s1 = s2;
    else
        if (s2){
            p = *s1;
            while (p->next)     p = p->next;
            p->next = s2;
        }
}

nodestr *substring(nodestr S, int i, int len){
    int k = 1;
    nodestr p, q, r, t;
    p = S;
    while(p && k <i)    {p = p->next; k++;}
    if(!p)  {
        printf("error1\n");
        return NULL;
    }
    else{
        r = (nodestr*)malloc(sizeof(linkstrnode));
        r->data = p->data;  r->next = NULL;
        k = 1;  q = r;
        while(p->next && k<len)
        {
            p = p->next;    k++;
            t = (nodestr)malloc(sizeof(linkstrnode));
            t->data = p->data;
            q->next = t;    q = t;
        }
        if (k<len) {
            printf("error2\n");
            return NULL;
        }
        else{
            q->next = NULL;
            return r;
        }
    }
}

void print(nodestr s){
    nodestr p = s;
    if(p){
        printf("%s",p->data);
        p = p->next;
    }
}


    void strcreate(nodestr *s){
    char ch;
    linkstrnode *p, *r;
    *s = NULL;  r = NULL;
    printf("输入字符串:\n");
    while ((ch = getchar()) != '\n')
    {
        p = (linkstrnode*)malloc(sizeof(linkstrnode));
        p->data = ch;
        if (*s == NULL)
            *s = p;
        else    r->next = p;
        r = p;
    }
    if (r != NULL)  r->next = NULL;
}

int main() {
    int x, y, len, flag = 1;
    nodestr s1, s2;
    strcreate(s1);
    while(flag){
        printf("------------------------\n"
               "1.插入\n"
               "2.删除\n"
               "3.拼接\n"
               "4.取子串\n"
               "5.打印\n"
               "6.退出\n"
               "------------------------\n");
        scanf("%d", &x);
        if (x == 1) {
            printf("输入位置和字符串:\n");
            scanf("%d",&y);
            strcreate(s2);
            strinsert(&s1, y, s2);
        }
        else if (x == 2) {
            printf("输入位置和长度:\n");
            scanf("%d",&y);
            scanf("%d",&len);
            strdele(&s1, y, len);
        }
        else if (x == 3) {
            printf("输入字符串:\n");
            strcreate(s2);
            strconcat(s1, s2);
            print(s1);
        }
        else if (x == 4) {
            printf("输入位置和长度:\n");
            scanf("%d",&y);
            scanf("%d",&len);
            print(*substring(s1, y, len));
        }
        else if (x == 5) print(s1);
        else if (x == 6) flag = 0;
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//链表结构体的实现
typedef struct node{
	char data;
	struct node *next;
}linkstrnode;
//链表的创�?
linkstrnode* strcreate(linkstrnode *S){
	char ch;
	linkstrnode *p,*r;
	S = NULL;
	r = NULL;
	while((ch = getchar()) != '\n'){
		p = (linkstrnode *)malloc(sizeof(linkstrnode));
		p->data = ch;
		if(S == NULL){
			S = p;
		}
		else{
			r->next = p;
		}
		r = p;
	}
	if(r != NULL){
		r->next = NULL;
	}
	return S;
}
//链表的插�?
linkstrnode* strinsert(linkstrnode *S,int i,linkstrnode* T){
	int k;
	linkstrnode *p,*q;
	p = S,k = 1;
	while(p && k<i-1){
		p = p->next;
		k++;
	}
	if(!p){
		printf("error \n");
	}
	else{
		q = T;
		while(q && q->next){
			q = q->next;
		}
		q->next = p->next;
		p->next = T;
	}
	return S;
}
//链表的删�?
linkstrnode* strdelete(linkstrnode* S,int i,int len){
	int k;
	linkstrnode *p,*q,*r;
	p = S;
	q = NULL;
	k = 1;
	while(p && k<i){
		q = p;
		p = p->next;
		k++;
	}
	if(!p){
		printf("error \n");
	}
	else{
		k = 1;
		while(k<len && p){
			p = p->next;
			k++;
		}
		if(!p){
			r = S;
			S = p->next;
		}
		else{
			r = q->next;
			q->next = p->next;
		}
		p->next = NULL;
		while(r != NULL){
			p = r;
			r = r->next;
			free(p);
		}
	}
	return S;
}

//链表的连�?
linkstrnode* strconcat(linkstrnode* S1,linkstrnode *S2){
	linkstrnode *p;
	if(!(S1)){
		S1 = S2;
		return 0;
	}
	else{
		if(S2){
			p = S1;
			while(p->next){
				p = p->next;
			}
			p->next = S2;
		}
	}
	return S1;
}

//求子�?
linkstrnode* substring(linkstrnode *S,int i,int len){
	int k;
	linkstrnode *p,*q,*r,*t;
	p = S;
	k = 1;
	while(p && k<i){
		p = p->next;
		k++;
	}
	if(!p){
		printf("error \n");
		return (NULL);
	}
	else{
		r = (linkstrnode*)malloc(sizeof(linkstrnode));
		r->data = p->data;
		r->next = NULL;
		k = 1;
		q = r;
		while(p->next && k<len){
			p = p->next;
			k++;
			t = (linkstrnode*)malloc(sizeof(linkstrnode));
			t->data = p->data;
			q->next = t;
			q = t;
		}
		if(k<len){
			printf("error \n");
			return NULL;
		}
		else{
			q->next = NULL;
			return (r);
		}
	}
}
//链表的遍历输�?
void display(linkstrnode *S){
	linkstrnode *p =S;
	while(p != NULL){
		printf("%c",p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	linkstrnode *p,*p2,*p3;
	int i,j,len=0;
	p=NULL;
	p2=NULL;
    printf("\n�����ַ���:\n");
    p=strcreate(p);
    printf("\n�����ɹ�!\n"); 
    display(p);
    printf("\nҪ������ַ���Ϊ:\n");
    p2=strcreate(p2);
    printf("\n��������λ��Ϊ:\n");
    scanf("%d",&j);
    getchar();
    strinsert(p,j,p2);
	printf("������ַ���Ϊ");
	display(p);
    printf("\n����Ҫ���ҵ��ַ���λ��:\n");
    scanf("%d",&j);
    getchar();
    printf("\nҪ������ַ�����:\n");
    scanf("%d",&len);
    getchar();
    p3=substring(p,j,len);      
	printf("\n�Ӵ�Ϊ:\n");
    display(p3);
	system("pause");
	return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//閾捐〃缁撴瀯浣撶殑瀹炵幇
typedef struct node{
	char data;
	struct node *next;
}linkstrnode;
//閾捐〃鐨勫垱寤?
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
//閾捐〃鐨勬彃鍏?
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
//閾捐〃鐨勫垹闄?
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

//閾捐〃鐨勮繛鎺?
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

//姹傚瓙涓?
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
//閾捐〃鐨勯亶鍘嗚緭鍑?
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
    printf("\n创建字符串:\n");
    p=strcreate(p);
    printf("\n创建成功!\n"); 
    display(p);
    printf("\n要插入的字符串为:\n");
    p2=strcreate(p2);
    printf("\n输入插入的位置为:\n");
    scanf("%d",&j);
    getchar();
    strinsert(p,j,p2);
	printf("插入后字符串为");
	display(p);
    printf("\n输入要查找的字符受位置:\n");
    scanf("%d",&j);
    getchar();
    printf("\n要插入的字符长度:\n");
    scanf("%d",&len);
    getchar();
    p3=substring(p,j,len);      
	printf("\n子串为:\n");
    display(p3);
	system("pause");
	return 0;

}

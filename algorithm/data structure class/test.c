
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct a
{
	  int num;
	  char name[10];
	  long tel;
}stu;


typedef struct link_node
{
    stu *student;
	struct link_node *next;
}node;

node *init()   
{
	return NULL;
}//建立一个空的单链表

node *find (node *head, char Name[])
{
	node *p = head;
	while((p!=NULL)&&(strcmp(p->student->name,Name)))
	{
		p=p->next;
	}
	if(p == NULL){
		printf("can't find!");
	}
	return p;
}//查找指定姓名的结点

node *insert (node *head,char name[])
{
	node *p,*q;
	p = (node*)malloc(sizeof(node));
	p->student = (stu*)malloc(sizeof(stu));
	scanf ("%d %s %ld",&p->student->num, p->student->name,&p->student->tel);
	q = find(head, name);//返回现阶段符合的指针 如果没有符合的就返回NULL
	if(q != NULL){
		p->next = q->next;
		q->next = p;
	}

	return head;
}//在某位同学后插入一个同学信息

node *dele (node *head,char name[])
{
	node *p = NULL, *pre = NULL;
	if (head == NULL)
	{
		printf ("通讯录为空");
		return head ;
	}
	//判断是否存在node
	p=head;
	while (p&&(strcmp(p->student->name,name)))
	{
		pre = p;
		p = p->next;
	}
	//判断是否是最后一个
	if(p == NULL){
		printf("can't find node!");
	}else{
		node *needDele;//需要删除的节点
		needDele = pre->next;
		pre->next = pre->next->next;
		free(needDele);
	}

	return head;
}//删除某位同学信息

void display (node *head)
{
	node *p;
	p=head;
	if (!p) printf ("通讯录为空");
	else
	{
		printf ("结点值为:\n");
		while (p)
		{
			printf ("%5d %s %ld\n",p->student->num,p->student->name,p->student->tel);
			p = p->next;
		}
	}
}//输出通讯录中各同学的信息

void display2(node *head,char name[])
{
	node *p;
	p=find(head,name);
	if(p != NULL)
		printf ("%5d %s %ld\n",p->student->num,p->student->name,p->student->tel);
}//输出通讯录中指定同学信息

int main()
{
	node *p,*q,*head;
	q=NULL;
	int i;
	printf ("请输入通讯录人数:");
	scanf ("%d",&i);
	int j=0;
	while (j<i)
	{
    	p=(node*)malloc(sizeof(node));
    	p->student = (stu*)malloc(sizeof(stu));	
    	scanf ("%d %s %ld",&p->student->num,p->student->name,&p->student->tel);
    	if(q == NULL){
			head = p;
			q = p;
			p->next = NULL;
		}else{
			q->next= p;
			q = p;
			p->next = NULL;
		}
    	j++;   	
	}//录入通讯录信息
	
	char name1[10];
	printf ("请输入插入位置前同学姓名:");
	scanf ("%s",name1);
	insert(head,name1);//插入
	
	
	char name2[10];
	printf ("请输入删除同学姓名:");
	scanf ("%s",name2);
	dele (head,name2);//删除
	
	display (head);//打印全部成员信息
	
	char name3[10];
	printf ("请输入指定同学姓名:");
	scanf ("%s",name3);
	display2 (head,name3);//打印指定同学信息
	
	system("pause");
	return 0;
}
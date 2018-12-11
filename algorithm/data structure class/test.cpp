# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<windows.h>
 
typedef struct Student
{
    char roomnum[10];	//ϵ�� 
    int bednum;		//�༶ 
    int num;		//���� 
    char name[20];	//���� 
    struct Student *next;
}Stu;
 
//�˵�
int menu_select()
{      
 	int a;
    do{
        system("cls");
        printf("\n\n        ----------------------ͼ��Ǽǹ���----------------------\n");
        printf("\t\t       1. ����                      \n");
        printf("\t\t       2. ��ӡ                      \n");
        printf("\t\t       3. ����                      \n");
        printf("\t\t       4. ����                      \n");
		printf("\t\t       0. �˳�                      \n");
        printf("     -----------------------------------------------------------------\n");
        printf("                             ��ѡ����� \n");
        scanf("%d",&a);
    }while(a<0||a>9);
    return a;
}
 
//���
Student *input(int n)                  
{
	int i;
	Stu *head,*l,*r;
	if(n<=0)
	{
		return NULL;
	}
	l=(Stu *)malloc(sizeof(Stu));

	printf("\t\tϵ��:");                
	scanf("%s",&l->roomnum);
	printf("\t\t�༶:");
	scanf("%d",&l->bednum);
	printf("\t\t����:");
	scanf("%d",&l->num);
	printf("\t\t����:");
	scanf("%s",&l->name);
	printf("\n");
	head=l;
	for(i=1;i<n;i++)
	{
		r=(Stu *)malloc(sizeof(Stu));
	
	    printf("\t\tϵ��:");                
	    scanf("%s",&r->roomnum);
	    printf("\t\t�༶:");
	    scanf("%d",&r->bednum);
	    printf("\t\t����:");
	    scanf("%d",&r->num);
	    printf("\t\t����:");
	    scanf("%s",&r->name);
	    printf("\n");
	    l->next=r;
	    l=r;
	    if(i==n-1)
		{
			l->next=NULL;	
		}
	}
	return head;
}
 
//���
void output(Stu *head)
{
	Stu *p;
	p=head;
	if(head==NULL)
	{
		printf("\n\t\t\tѧ����ϢΪ�գ�\n");
	}
	else
	{
		do
		{
			printf("ϵ��%s  �༶��%d  ���ţ�%d  ������%s \n",p->roomnum,p->bednum,p->num,p->name);
			p=p->next;
		}while(p!=NULL);
	} 
}
//����
int sort_select(Stu *head)
{
	Stu *p,*q;
	char roomnum[10];
	int bednum;
	int num; 
	char name[20];
	    	system("cls");    
			for(p=head;p!=NULL;p=p->next)
			{
			    for(q=p->next;q!=NULL;q=q->next)
			    {
			        if(p->num>q->num)//�Ƚ�ѧ�� 
			        {
			            
//			            roomnum=q->roomnum;
			            strcpy(roomnum,q->roomnum);
			            bednum=q->bednum;
			            num=q->num; 
			            strcpy(name,q->name);//�ַ������� 
			            
		              //  q->lh=p->lh;
//		                q->roomnum=p->roomnum;
						strcpy(q->roomnum,p->roomnum);
			            q->bednum=p->bednum;
			            q->num=p->num;
			            strcpy(q->name,p->name);
			            
		              //  p->lh=lh;
//		                p->roomnum=roomnum;
						strcpy(p->roomnum,roomnum);
		                p->bednum=bednum;
		                p->num=num;
		                strcpy(p->name,name);
					}
			    }
			}
		    output(head);
   
    	system("pause");
    	return 0;
	}

 

//����
int find_select(Stu *head)
{
	Stu *p;
			system("cls");
			p=head;
			int f;
			printf("\n\t\t\tҪ���ҵ�ѧ��Ϊ��");
			scanf("%d",&f);
			while(p!=NULL)
			{
				if(p->num==f)
			printf("ϵ��%s  �༶��%d  ���ţ�%d  ������%s \n",p->roomnum,p->bednum,p->num,p->name);			
				p=p->next;
			}
			system("pause");
			return 0;

	}

 

 
int main()          
{
	
	int n,m,x,y;
	Stu *head=NULL;
	Stu *pnew;
	for(;;)
	{
        switch(menu_select())
        {
            case 1:
            	system("cls");
            	printf("\n\n\t\t----------------------------\n\n");
				printf("\t\t\t����ѧ���ĸ�����");
				scanf("%d",&n);
				if(n<=0)
				{
					printf("\n\t\t\t��������ȷ������!");
					Sleep(500);
					break;
				}
				else
				{
					printf("\n\t\t\t����ѧ������\n\n");
	            	head=input(n);
	            	break;
				}
            case 2:
            	system("cls");
	            printf("\n\t\t\t\t\t\t\t\t��ʾѧ������\n");
	            output(head);
	            system("pause");
	            break; 
            case 3:
				do
				{
					x=sort_select(head);
				}while(x!=0);
                break;
                      
            case 4:
            	system("cls");
				do
				{
					y=find_select(head);
				}while(y!=0);
                break;
           
            case 0:
                printf("\n\t\t\t���˳�\n");
                exit(0);
        }
	}
}

# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<windows.h>
 
typedef struct Student
{
    char roomnum[10];	//系别 
    int bednum;		//班级 
    int num;		//卡号 
    char name[20];	//姓名 
    struct Student *next;
}Stu;
 
//菜单
int menu_select()
{      
 	int a;
    do{
        system("cls");
        printf("\n\n        ----------------------图书登记管理----------------------\n");
        printf("\t\t       1. 输入                      \n");
        printf("\t\t       2. 打印                      \n");
        printf("\t\t       3. 排序                      \n");
        printf("\t\t       4. 查找                      \n");
		printf("\t\t       0. 退出                      \n");
        printf("     -----------------------------------------------------------------\n");
        printf("                             请选择操作 \n");
        scanf("%d",&a);
    }while(a<0||a>9);
    return a;
}
 
//添加
Student *input(int n)                  
{
	int i;
	Stu *head,*l,*r;
	if(n<=0)
	{
		return NULL;
	}
	l=(Stu *)malloc(sizeof(Stu));

	printf("\t\t系别:");                
	scanf("%s",&l->roomnum);
	printf("\t\t班级:");
	scanf("%d",&l->bednum);
	printf("\t\t卡号:");
	scanf("%d",&l->num);
	printf("\t\t姓名:");
	scanf("%s",&l->name);
	printf("\n");
	head=l;
	for(i=1;i<n;i++)
	{
		r=(Stu *)malloc(sizeof(Stu));
	
	    printf("\t\t系别:");                
	    scanf("%s",&r->roomnum);
	    printf("\t\t班级:");
	    scanf("%d",&r->bednum);
	    printf("\t\t卡号:");
	    scanf("%d",&r->num);
	    printf("\t\t姓名:");
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
 
//输出
void output(Stu *head)
{
	Stu *p;
	p=head;
	if(head==NULL)
	{
		printf("\n\t\t\t学生信息为空！\n");
	}
	else
	{
		do
		{
			printf("系别：%s  班级：%d  卡号：%d  姓名：%s \n",p->roomnum,p->bednum,p->num,p->name);
			p=p->next;
		}while(p!=NULL);
	} 
}
//排序
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
			        if(p->num>q->num)//比较学号 
			        {
			            
//			            roomnum=q->roomnum;
			            strcpy(roomnum,q->roomnum);
			            bednum=q->bednum;
			            num=q->num; 
			            strcpy(name,q->name);//字符串复制 
			            
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

 

//查找
int find_select(Stu *head)
{
	Stu *p;
			system("cls");
			p=head;
			int f;
			printf("\n\t\t\t要查找的学号为：");
			scanf("%d",&f);
			while(p!=NULL)
			{
				if(p->num==f)
			printf("系别：%s  班级：%d  卡号：%d  姓名：%s \n",p->roomnum,p->bednum,p->num,p->name);			
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
				printf("\t\t\t输入学生的个数：");
				scanf("%d",&n);
				if(n<=0)
				{
					printf("\n\t\t\t请输入正确的人数!");
					Sleep(500);
					break;
				}
				else
				{
					printf("\n\t\t\t输入学生数据\n\n");
	            	head=input(n);
	            	break;
				}
            case 2:
            	system("cls");
	            printf("\n\t\t\t\t\t\t\t\t显示学生数据\n");
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
                printf("\n\t\t\t已退出\n");
                exit(0);
        }
	}
}

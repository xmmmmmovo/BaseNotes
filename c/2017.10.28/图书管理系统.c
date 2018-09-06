# include<stdio.h>
# include<string.h>
# include<malloc.h>

typedef struct book
{
	char BookName[20];
	char authorName[20];
	int pageNumber;
	float price;
	char kind[10];
	
	struct book * next;
}Book;

void showlist(Book *Book)
{
	do
    {
        printf("%10s   %10s   %10s    %.1f    %4d\n",Book->BookName,Book->authorName,Book->kind,Book->price,Book->pageNumber);
    }while(Book = Book->next);
    
}

Book * deleteBook(Book *head)
{
}

Book * readDataByTxt()
{
	char allChar[100];
	char bookName[20];
	char authorName[20];
	float price;
	int pageNumber;
	char kind[10];
	
	Book *head = NULL, *prev = NULL, *bookP = NULL;
	
	FILE *fp;
	int temp = 0, i, flag;
	if((fp = fopen("C:\\Users\\13256\\Desktop\\安卓实验室\\2017.10.28\\data.txt", "r")) == NULL)
		printf("**************读取失败*************\n");
	else
	{
		
		do
		{
			bookP = (Book *)malloc(sizeof(Book));
			
			fscanf(fp, "%s%s%s%f%d", bookName,authorName,kind,&price,&pageNumber);
			
			if(prev != NULL)
				prev->next = bookP;
			if(head == NULL)
				head = bookP;
			
			strcpy(bookP->BookName, bookName);
			strcpy(bookP->kind, kind);
			strcpy(bookP->authorName, authorName);
			bookP->price = price;
			bookP->pageNumber = pageNumber;
			
			prev = bookP;
		}while(fgetc(fp) != EOF);
		
		printf("**********************已成功从本地文档加载数据*******************\n\n");
	}
		
	fclose(fp);
	return head;
}

void showTitle()
{
	printf("*****************************************************************\n\n");
	printf("                           图书管理系统\n\n			1、列出当前库存\n			2、删除一本书\n			3、增添一本书\n			4、取出一本书\n			5、搜索\n			6、查看菜单\n			7、清屏\n\n");
	printf("*****************************************************************\n\n\n");
}

int main(void)
{
	int n;
	Book *head = NULL;
	
	showTitle();
	head = readDataByTxt();
	
	scanf("%d", &n);
	switch(n)
	{
		case 1:
			showlist(head);
			break;
		default:
			puts("qingping");
	}
	
	return 0;
}

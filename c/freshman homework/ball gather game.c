#include "stdio.h"
#include "windows.h"
#include "time.h"

int windowsWidth,windowsHigh;
int ballx,bally;
int ballvx,ballvy;
int i,j;
int count=0,count1=0;
int blockx,blocky;

int levels = 1; //�ȼ�

void init()
{
    system("cls");
	windowsWidth=23,windowsHigh=13;
	ballx=1,bally=1;
	ballvy=1;ballvx=1;
	blockx=(rand()*rand())%(windowsWidth-1);
	blocky=(rand()*rand())%windowsHigh;
}

void showWindows()
{
	// int length = 10/levels;
	// for(i=1;i < length;i++)
	// 	printf("*");
	// printf("\n");


	for(i=1;i<windowsHigh;i++)
	{
		//�������ո�
		for(j=1;j<windowsWidth;j++)
			printf(" ");
		//���һ��|
		printf("|\n");
	}
	for(i=1;i<windowsWidth;i++)
		printf("-");
	printf("|\n");

}
void gotoxy(int x,int y)
{
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle,pos);
}

void showBall()
{
	gotoxy(ballx,bally);
	printf("o");
	Sleep(100);
    int sleeps = 100/levels;
    // int length = 10/levels;
	while(1)
	{
		gotoxy(blockx,blocky);
		printf("*");
		gotoxy(ballx,bally);
		printf(" ");

		if(bally==windowsHigh-2 || bally==0){	
            ballvy=-ballvy;
            count++;
        }
		bally=bally+ballvy;
		
		if(ballx==windowsWidth-2 || ballx==0){	
            ballvx=-ballvx;
            count++;
        }
		ballx=ballx+ballvx;
		
		gotoxy(ballx,bally);
		printf("o");
		
		if(ballx==blockx && bally==blocky){
			blockx=rand()%(windowsWidth-1);
			blocky=rand()%windowsHigh;
			count1++;
		}

		gotoxy(windowsWidth+5,windowsHigh/2);
		printf("С�����ڵĴ�����%d",count);
		gotoxy(windowsWidth+5,windowsHigh/2+1);
		printf("С���*�Ĵ�����%d",count1);
		Sleep(sleeps);
	}
}

void displayMenu()//��ʾ���˵�
{
	printf("/************************************/\n");
	printf("/********* 1  Start game ************/\n");
	printf("/********* 2  Level     *************/\n");
	printf("/********* 0  Exit      *************/\n");
	printf("/************************************/\n");
}
void displaySubMenu()//��ʾ�Ӳ˵�
{
	system("cls");
	printf("/************************************/\n");
	printf("/********* 1  Easy       ************/\n");
	printf("/********* 2  Normal     ************/\n");
	printf("/********* 3  Hard       ************/\n");
	printf("/********* 0  Return     ************/\n");
	printf("/************************************/\n");
}
void selectSub()//���Ӳ˵��н���ѡ��
{
	printf("��ѡ��");
	scanf("%d",&levels);
	switch(levels)
	{
	    case 1:printf("����ѡ�����Ϸ�Ѷ�Ϊ��Easy\n");break;
	    case 2:printf("����ѡ�����Ϸ�Ѷ�Ϊ��Normal\n");break;
	    case 3:printf("����ѡ�����Ϸ�Ѷ�Ϊ��Hard\n");break;
	    default:return;
	}
	getchar();
	getchar();
}
void selectMenu()//�����˵��н���ѡ��
{
	int i;
	printf("��ѡ��");
	scanf("%d",&i);
    
    switch (i)
    {
        case 1:
            init();
	        showWindows();
	        showBall();
            break;

        case 2:
            displaySubMenu();
		    selectSub();
            break;

        case 0:
            exit(0);
            break;
        
        default:
            break;
    }
}
int main()
{
	while(1)
	{
		system("cls");
		displayMenu();//��ʾ���˵�	
		selectMenu();//�����˵��н���ѡ��
		//system("pause");
	}
	return 0;
}

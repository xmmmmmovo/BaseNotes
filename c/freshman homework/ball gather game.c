#include "stdio.h"
#include "windows.h"
#include "time.h"

int windowsWidth,windowsHigh;
int ballx,bally;
int ballvx,ballvy;
int i,j;
int count=0,count1=0;
int blockx,blocky;

int levels = 1; //等级

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
		//输出多个空格
		for(j=1;j<windowsWidth;j++)
			printf(" ");
		//输出一个|
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
		printf("小球碰壁的次数：%d",count);
		gotoxy(windowsWidth+5,windowsHigh/2+1);
		printf("小球吃*的次数：%d",count1);
		Sleep(sleeps);
	}
}

void displayMenu()//显示主菜单
{
	printf("/************************************/\n");
	printf("/********* 1  Start game ************/\n");
	printf("/********* 2  Level     *************/\n");
	printf("/********* 0  Exit      *************/\n");
	printf("/************************************/\n");
}
void displaySubMenu()//显示子菜单
{
	system("cls");
	printf("/************************************/\n");
	printf("/********* 1  Easy       ************/\n");
	printf("/********* 2  Normal     ************/\n");
	printf("/********* 3  Hard       ************/\n");
	printf("/********* 0  Return     ************/\n");
	printf("/************************************/\n");
}
void selectSub()//在子菜单中进行选择
{
	printf("请选择：");
	scanf("%d",&levels);
	switch(levels)
	{
	    case 1:printf("您所选择的游戏难度为：Easy\n");break;
	    case 2:printf("您所选择的游戏难度为：Normal\n");break;
	    case 3:printf("您所选择的游戏难度为：Hard\n");break;
	    default:return;
	}
	getchar();
	getchar();
}
void selectMenu()//在主菜单中进行选择
{
	int i;
	printf("请选择：");
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
		displayMenu();//显示主菜单	
		selectMenu();//在主菜单中进行选择
		//system("pause");
	}
	return 0;
}

#undef UNICODE
#undef _UNICODE

#include "Book.h"
#include "List.h"
#include "resource.h"
#include "Window.h"
#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

/**
主函数
*/
int main(void) {
	MOUSEMSG mouse;
	char pos[12]; // 测试用的坐标数组
	initView();
	initList();
	while (true){
		mouse = GetMouseMsg();
		switch (mouse.uMsg){
		case WM_LBUTTONDOWN:
			if (checkRect(mouse, startrec)) {
			}
			else if (checkRect(mouse, exitrec)) {
				closegraph();
				return 0;
			}else{
				FILE *file;
				fopen_s(&file, "./data.txt", "a");
				fprintf(file, pos);
			}
			break;
		case WM_MOUSEMOVE:
			setfillcolor(BLACK);
			solidrectangle(0, 0, 75, 20);
			sprintf_s(pos, "[%d, %d]", mouse.x, mouse.y);
			outtextxy(0, 0, pos);
			break;
		default:
			break;
		}
	}
	return 0;
}
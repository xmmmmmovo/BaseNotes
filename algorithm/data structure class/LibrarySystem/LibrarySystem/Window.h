#pragma once
#undef UNICODE
#undef _UNICODE
/**
图形化函数
*/
#include <graphics.h>

/**
矩形边界
*/
typedef RECT rect;

rect startrec; // 开始菜单的按钮
rect exitrec;

/**
初始化边界
*/
void createRect(rect &rec, int left, int top, int right, int buttom) {
	rec.left = left;
	rec.top = top;
	rec.right = right;
	rec.bottom = buttom;
}

/**
创建
*/
rect createButton(int left, int top) {
	rect rectan;
	createRect(rectan, left, top, left + 200, top + 100);
	return rectan;
}

/**
矩形填充
*/
void fillRect(rect rec) {
	fillrectangle(rec.left, rec.top, rec.right, rec.bottom);
}

/**
初始化
*/
void initView() {
	initgraph(1280, 960); // 初始化窗口
	loadimage(NULL, "IMAGE", "LABBK", 1280, 960, true); // 读取背景

	// 按钮
	startrec = createButton(200, 500);
	exitrec = createButton(200, 700);
	setfillcolor(WHITE);
	fillRect(startrec);
	fillRect(exitrec);
	// 按钮内部字体
	settextstyle(70, 25, NULL);
	setbkcolor(WHITE);
	settextcolor(BLACK);
	drawtext("进入系统", &startrec, DT_CENTER | DT_VCENTER);
	drawtext("退出程序", &exitrec, DT_CENTER | DT_VCENTER);

	// 标题
	rect titlerec;
	createRect(titlerec, 100, 100, 1000, 250);
	fillRect(titlerec);
	settextstyle(130, 50, NULL);
	drawtext("欢迎来到图书管理系统！", &titlerec, DT_CENTER | DT_VCENTER);
	// 人员表
	rect grouprec;
	createRect(titlerec, 100, 250, 1000, 300);
	fillRect(titlerec);
	settextstyle(50, 15, NULL);
	drawtext("————小队人员：马骕駸 林志鹏 李开宇 申田园", &titlerec, DT_RIGHT);
}

/**
边界检测
*/
bool checkRect(MOUSEMSG &mouse, rect &rectTemp) {
	return (mouse.x > rectTemp.left && mouse.x < rectTemp.right
		&& mouse.y > rectTemp.top && mouse.y < rectTemp.bottom) ? true : false;
}
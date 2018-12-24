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
	initgraph(750, 446); // 初始化窗口
	loadimage(NULL, "PNG", "LABBK"); // 读取背景
}

/**
边界检测
*/
bool checkRect(MOUSEMSG &mouse, rect &rectTemp) {
	return (mouse.x > rectTemp.left && mouse.x < rectTemp.right
		&& mouse.y > rectTemp.top && mouse.y < rectTemp.bottom) ? true : false;
}
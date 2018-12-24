#pragma once
#undef UNICODE
#undef _UNICODE
/**
ͼ�λ�����
*/
#include <graphics.h>

/**
���α߽�
*/
typedef RECT rect;

rect startrec; // ��ʼ�˵��İ�ť
rect exitrec;

/**
��ʼ���߽�
*/
void createRect(rect &rec, int left, int top, int right, int buttom) {
	rec.left = left;
	rec.top = top;
	rec.right = right;
	rec.bottom = buttom;
}

/**
����
*/
rect createButton(int left, int top) {
	rect rectan;
	createRect(rectan, left, top, left + 200, top + 100);
	return rectan;
}

/**
�������
*/
void fillRect(rect rec) {
	fillrectangle(rec.left, rec.top, rec.right, rec.bottom);
}

/**
��ʼ��
*/
void initView() {
	initgraph(750, 446); // ��ʼ������
	loadimage(NULL, "PNG", "LABBK"); // ��ȡ����
}

/**
�߽���
*/
bool checkRect(MOUSEMSG &mouse, rect &rectTemp) {
	return (mouse.x > rectTemp.left && mouse.x < rectTemp.right
		&& mouse.y > rectTemp.top && mouse.y < rectTemp.bottom) ? true : false;
}
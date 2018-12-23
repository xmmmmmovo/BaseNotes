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
	initgraph(1280, 960); // ��ʼ������
	loadimage(NULL, "IMAGE", "LABBK", 1280, 960, true); // ��ȡ����

	// ��ť
	startrec = createButton(200, 500);
	exitrec = createButton(200, 700);
	setfillcolor(WHITE);
	fillRect(startrec);
	fillRect(exitrec);
	// ��ť�ڲ�����
	settextstyle(70, 25, NULL);
	setbkcolor(WHITE);
	settextcolor(BLACK);
	drawtext("����ϵͳ", &startrec, DT_CENTER | DT_VCENTER);
	drawtext("�˳�����", &exitrec, DT_CENTER | DT_VCENTER);

	// ����
	rect titlerec;
	createRect(titlerec, 100, 100, 1000, 250);
	fillRect(titlerec);
	settextstyle(130, 50, NULL);
	drawtext("��ӭ����ͼ�����ϵͳ��", &titlerec, DT_CENTER | DT_VCENTER);
	// ��Ա��
	rect grouprec;
	createRect(titlerec, 100, 250, 1000, 300);
	fillRect(titlerec);
	settextstyle(50, 15, NULL);
	drawtext("��������С����Ա�����X� ��־�� ��� ����԰", &titlerec, DT_RIGHT);
}

/**
�߽���
*/
bool checkRect(MOUSEMSG &mouse, rect &rectTemp) {
	return (mouse.x > rectTemp.left && mouse.x < rectTemp.right
		&& mouse.y > rectTemp.top && mouse.y < rectTemp.bottom) ? true : false;
}
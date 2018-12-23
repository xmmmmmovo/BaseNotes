#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<graphics.h>
#include<vector>

using namespace std;

int main() {
	initgraph(640, 480);
	HRGN reg = CreateRectRgn(100, 100, 200, 200);
	SelectClipRgn(NULL, reg);
	loadimage(NULL, _T("D:\\AndroidLabtest\\notes\\algorithm\\data structure class\\LibrarySystem\\LibrarySystem\\res\\labBk.jpg"));

	getchar();
	return 0;
}
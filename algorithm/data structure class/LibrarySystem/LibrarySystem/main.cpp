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
Ö÷º¯Êý
*/
int main(void) {
	initView();
	initList();
	getchar();
	closegraph();
}
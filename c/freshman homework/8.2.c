#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool year(int y)
{
	if((y%4 == 0 && y%100 != 0) || y%400 == 0)
		return true;
	else
		return false;
}

int main(void)
{
	int y;
	
	scanf("%d", &y);
	
	printf("%d", year(y));	
	
	return 0;
}
/*
在devc++中的运行结果为
1990
0
*/

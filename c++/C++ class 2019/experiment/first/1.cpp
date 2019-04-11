#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
    int i = 1, sum = 0;

    /*
    do{
        sum += i;
    }while (i++<10);
    */

    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    printf("%d\n", sum);

    system("pause");
    return 0;
}

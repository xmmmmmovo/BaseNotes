#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void sorts(int &x, int &y, int &z) {
    if (x < y) {
        swap(x, y);
    }

    if (x < z) {
        swap(x, z);
    }

    if (y < z) {
        swap(y, z);
    }
}

int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    sorts(x, y, z);
    printf("%d %d %d\n", x, y, z);

    system("pause");
    return 0;
}

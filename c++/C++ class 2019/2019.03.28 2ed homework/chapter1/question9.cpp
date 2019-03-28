#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void checks(int &x, int &y) {
    if (x < y) {
        swap(x, y);
    }
}

void sorts(int &x, int &y, int &z) {
    int maxnum = max(x, max(y, z));

    if (y == maxnum) {
        swap(x, y);
    } else if (z == maxnum) {
        swap(x, z);
    }
    checks(y, z);
}

int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    sorts(x, y, z);
    printf("%d %d %d\n", x, y, z);

    return 0;
}

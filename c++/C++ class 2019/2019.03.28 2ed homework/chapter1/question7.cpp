#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int linemax(int x, int y, int z) {
    return max(x, max(y, z));
}

int main() {
    int x, y, z = -1 << 32;
    int ans = 0;

    scanf("%d %d", &x, &y);
    if (getchar() != '\n') {
        scanf("%d", &z);
    }

    ans = linemax(x, y, z);
    printf("%d\n", ans);

    return 0;
}

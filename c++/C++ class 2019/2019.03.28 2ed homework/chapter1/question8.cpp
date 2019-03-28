#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void maxchose(int &x, int &y) {
    if (y > x) {
        swap(x, y);
    }
    return;
}

int main() {
    int x, y;

    scanf("%d %d", &x, &y);
    maxchose(x, y);
    printf("%d %d", x, y);

    return 0;
}

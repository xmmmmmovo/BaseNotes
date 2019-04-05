#include <iostream>
#include <cstdio>
#include <cstdlib>
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
    printf("%d %d\n", x, y);

    system("pause");
    return 0;
}

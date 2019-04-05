#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define pi 3.1415926

double cacu(double r) {
    return r * r * pi;
}

double cacu(double x, double y) {
    return x * y;
}

int main(void) {
    int chose = 0;
    double r = 0, x = 0, y = 0, ans = 0;
    printf("What do you want caculate?\n1.ciecle 2.rectangle 3.squre\n");
    scanf("%d", &chose);

    switch(chose) {
    case 1:
        printf("Give me your R:\n");
        scanf("%lf", &r);
        ans = cacu(r);
        break;
    case 2:
        printf("Give me your x & y:\n");
        scanf("%lf %lf", &x, &y);
        ans = cacu(x, y);
        break;
    case 3:
        printf("Give me your a:\n");
        scanf("%lf", &x);
        ans = cacu(x, x);
        break;
    }

    printf("%.2lf\n", ans);

    return 0;
}

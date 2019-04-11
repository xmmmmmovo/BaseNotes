#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

double ftoc(double f) {
    return (f - 32) * 5.0 / 9.0;
}

int max1(int a, int b = 0) {
    return a > b ? a : b;
}

int max1(int a, int b, int c) {
    return max1(a, max1(b, c));
}

double max1(double a, double b = 0) {
    return a > b ? a : b;
}

double max1(double a, double b, double c) {
    return max1(a, max1(b, c));
}

int main(void) {
    double c = 0, f = 0;
    scanf("%lf", &f);
    printf("%.2lf\n", ftoc(f));

    printf("%d\n", max1(-6));
    printf("%.2lf\n", max1(-6.0));
    printf("%d\n", max1(-6, 123));
    printf("%.2lf\n", max1(-6.0, 0.001));

    double x = 0, y = 0;
    scanf("%lf %lf", &x, &y);
    printf("%.2lf\n", pow(x, y));

    system("pause");
    return 0;
}

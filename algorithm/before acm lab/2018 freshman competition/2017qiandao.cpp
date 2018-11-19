#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int T = 0;
    int a = 0, b = 0, c = 0, x = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d", &a, &b, &c, &x);
        printf("%.0lf %.0lf %.0lf", ((double)(x*c)/(c-b)), ((double)(x*a)/(c-b)), ((double)(x*b)/(c-b)));
    }

    // system("pause");
    return 0;
}
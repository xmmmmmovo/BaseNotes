#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int T = 0, e = 0;
    int a = 0, b = 0, c = 0, x = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d", &a, &b, &c, &x);
        e = (x * b)/(c - b);
        printf("%d %d %d\n", e * c / b, e * a / b, e);
    }

    // system("pause");
    return 0;
}
/**
 *测试用文件 
*/
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int r;

    double PI = atan(1.0) * 4;//高精度PI
    
    scanf("%d", &r);
    printf("%.7lf", PI * r * r);

    system("pause");
    return 0;
}
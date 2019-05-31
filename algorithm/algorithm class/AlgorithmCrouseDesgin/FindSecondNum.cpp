/**
 * author: xmmmmmovo
 * generation time: 2019/05/25
 * filename: FindSecondNum.cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <algorithm>

using namespace std;

int random_partion(int *p, int n)
{
    int idx = rand() % n;
    swap(p[idx], p[n - 1]);
    int i = -1;
    int j = 0;
    for (j = 0; j < n; j++)
    {
        if (p[j] < p[n - 1])
        {
            swap(p[++i], p[j]);
        }
    }
    swap(p[++i], p[n - 1]);
    return i;
}

int getMaxK(int *p, int n, int k)
{
    int mid;
    if (k <= 0)
        return -1;
    if (n < k)
        return -1;
    mid = random_partion(p, n);
    if (mid == n - k)
        return p[mid];
    else if (mid < n - k)
        return getMaxK(p + mid + 1, n - mid - 1, k);
    else
        return getMaxK(p, mid, k - (n - mid));
}

int main(void)
{
    int n = 0, a[1000], temp = 0, num = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a[i] = temp;
    }

    num = getMaxK(a, n, 2);
    printf("%d\n", num);

    return 0;
}
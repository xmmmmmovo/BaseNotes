/**
 * author: xmmmmmovo
 * generation time: 2019/05/20
 * filename: 1093 A+B for Input-Output Practice (V).cpp
 * language & build version : C++ 11
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    int n = 0;
    string temp;

    cin >> n;
    getchar();
    while (n--)
    {
        int ans = 0;
        while (cin >> temp && temp[temp.size() - 1] == '\n')
        {
            cout << temp << " ";
            ans += stoi(temp);
        }
        ans += stoi(temp.substr(0, temp.size() - 1));
        cout << ans << endl;
    }

    system("pause");
    return 0;
}
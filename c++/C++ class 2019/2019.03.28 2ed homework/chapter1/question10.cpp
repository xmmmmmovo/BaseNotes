#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string str1, str2;
    int len1 = 0;

    cin >> str1;
    cin >> str2;

    str1.append(str2);

    cout << str1 << endl;

    system("pause");
    return 0;
}

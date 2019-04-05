#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string str;

    cin >> str;
    for (int i = str.length() - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;

    system("pause");
    return 0;
}
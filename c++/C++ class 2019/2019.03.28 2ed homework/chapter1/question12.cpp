#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string strs[5];

    for (int i = 0; i < 5; i++) {
        cin >> strs[i];
    }
    
    sort(strs, strs + 5);

    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << strs[i] << endl;
    }

    system("pause");
    return 0;
}
#include "vector.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    Vector<int> vector;
    vector.append(12);
    vector.showAll();

    system("pause");
    return 0;
}
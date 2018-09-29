#include "unidirectionalLinkedlist.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    List<int> list;
    list.insertInBack(12);
    list.insertInFort(122);
    list.insertInBack(23333);
    list.printAll();

    system("pause");
    return 0;
}

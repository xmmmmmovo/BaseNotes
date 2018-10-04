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
    list.deletePoint(122);
    list.printAll();
    list.insert(122, 1);//多种插入模式
    list.insert(12, 1);
    list.printAll();
    //1为非顺序的
    cout << list.disordered() << '\n';
    list.backInsert(1, 233);
    list.printAll();
    list.traserve();
    list.printAll();

    system("pause");
    return 0;
}

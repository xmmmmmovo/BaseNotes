#include "vector.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    Vector<int> vector;//构造int类型的模板类
    cout << vector.size() << '\n';
    vector.append(12);
    cout << vector.get(1);
    vector.put(1, 2);
    vector.showAll();
    vector.insert(1, 3);
    vector.showAll();
    vector.remove(1);
    vector.showAll();

    vector.append(12);
    vector.append(1);
    vector.append(33);
    vector.append(25);
    vector.append(12);
    cout << vector.disordered();
    vector.showAll();

    vector.sort(1, vector.size());
    vector.showAll();

    vector.uniquify(1, vector.size());
    vector.showAll();

    cout << vector.searchUnsortedList(1, 4, 12) << '\n';
    cout << vector.searchSortedList(1, 4, 12);
    vector.showAll();

    system("pause");
    return 0;
}
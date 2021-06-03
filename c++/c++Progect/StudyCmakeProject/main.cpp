/**
 * author: xmmmmmovo
 * generation time: 2019/05/05
 * filename: main.cpp
 * language & build version : C++ 11
 */
#include <iostream>

#define MIN(a, b) ({auto &at = (a); auto &bt = (b); (at) < (bt) ? (at) : (bt);})
//#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int main(int argc, char const *argv[]) {
  int i = 3, j = 6;
  cout << MIN(i += 1, j);
  return 0;
}
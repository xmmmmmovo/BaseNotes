/**
 * author: xmmmmmovo
 * generation time: 2019/08/02
 * filename: test.cpp
 * language & build version : C++ 11
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  for (float x = -1.5f; x < 1.5f; x+=0.05f) {
    putchar(x<=0.0f?"1324"[(int)(x)]:' ');
  }

  return 0;
}
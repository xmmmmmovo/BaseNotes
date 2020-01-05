//
// Created by xmmmmmovo on 2019/12/8.
//


#include <cstdio>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <unordered_map>

#define name_to_str(name)  (#name)

using std::vector;
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
using std::pair;
using std::make_pair;
using std::unordered_map;
using std::array;
using std::string;
using std::min;

vector<int> page;
array<pair<int, int>, 3> mem;
// 用于记录时间
int timmer = 0;

/**
 * 特化了一个模板来着
 * */
template<std::size_t size = 0>
ostream &operator<<(ostream &out, const array<pair<int, int>, size> &arr) {
    for (auto &iter : arr) {
        out << "\tfirst: " << iter.first << "\tsecond: " << iter.second << endl;
    }
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, const vector <T> &s) {
    for (auto &item : s) {
        out << "\t" << item;
    }
    out << endl;
    return out;
}

template <typename T, std::size_t size>
void arrayPrinter(string name, array<T, size> arr) {
    cout << "\n" << name << " array is:\n" << arr;
}

template <typename T>
void vectorPrinter(string name, vector<T> vec) {
    cout << "\n" << name << " vector is:\n" << vec;
}

/**
 * 这里进行了初始化
 * */
void init() {
    mem.fill(make_pair(-1, 0));
}

/**
 * 查找是否需要
 * */
bool findAndReplace(int require_page) {
    for (auto &iter : mem) {
        if (iter.first == require_page) {
            return true;
        }
        if (iter.first == -1) {
            iter = make_pair(0, 0);
            return true;
        }
    }
}

void timmerUpper() {
    timmer++;
    for (auto &iter : mem) {
        iter.second++;
    }
}

int main(void) {
    init();
    int tmp = 0;

    while (~scanf("%d", &tmp) && tmp != -1) {
        page.emplace_back(tmp);
    }

    vectorPrinter(name_to_str(page), page);

    arrayPrinter(name_to_str(mem), mem);

    for (auto &require_page : page) {
        timmerUpper();
        findAndReplace(require_page);
    }

    arrayPrinter(name_to_str(mem), mem);

    return 0;
}

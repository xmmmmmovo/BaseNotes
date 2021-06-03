/**
 * author: xmmmmmovo
 * generation time: 2021/05/05
 * filename: cp1.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>

int count_lines(const std::string &filename) {
    std::ifstream in(filename);

    return std::count(std::istream_iterator<char>(in),
                      std::istream_iterator<char>(), '\n');
}

std::vector<int>
count_lines_in_files(const std::vector<std::string> &files) {
    std::vector<int> results(files.size());
    std::transform(files.cbegin(), files.cend(), results.begin(),
                   count_lines);
    return results;
}

int main() {
    auto results = count_lines_in_files({"main.cpp", "Makefile"});

    for (const auto &result : results) {
        std::cout << result << " line(s)\n";
    }

    return 0;
}
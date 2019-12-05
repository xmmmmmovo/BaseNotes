//
// Created by xmmmmmovo on 2019/12/5.
//
#include <iostream>
#include <fstream>
#include <vector>

int p_num = 0, r_num = 0;
std::vector<int> available;
std::vector <std::vector<int>> max;
std::vector <std::vector<int>> allocation;

/**
 * 用于输出vector
 * */
template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector <T> &s) {
    for (auto &item : s) {
        out << "\t" << item;
    }
    out << std::endl;
    return out;
}

void readData() {
    int data;
    std::ifstream ifstream("../exp4/data.txt");

    std::cout << "Reading data now..." << std::endl;

    ifstream >> p_num >> r_num;

    std::cout << p_num << " " << r_num << std::endl;

    std::vector<int> tmp(r_num, 0);

    for (int i = 0; i < p_num; ++i) {
        for (int j = 0; j < r_num; ++j) {
            ifstream >> tmp[j];
        }
        allocation.emplace_back(tmp);
    }

    std::cout << "allocation:\n" << allocation;

    for (int i = 0; i < p_num; ++i) {
        for (int j = 0; j < r_num; ++j) {
            ifstream >> tmp[j];
        }
        max.emplace_back(tmp);
    }

    std::cout << "max:\n" << max;

    for (int k = 0; k < r_num; ++k) {
        ifstream >> tmp[0];
        available.emplace_back(tmp[0]);
    }

    std::cout << "available:\n" << available;

    return;
}

void processFillPrinter(int k) {
    std::cout << "process " << k + 1 << " alloc!" << std::endl;
}

// 回收资源
void recycleRes(int k) {
    for (int i = 0; i < r_num; ++i) {
        available[i] += allocation[k][i];
    }
}

void mainAlgorithm() {
    // 这里先是所有的process都无法完成
    std::vector<bool> is_get(p_num, false);
    // 计算每个process的需求(need)
    std::vector <std::vector<int>> need(p_num, std::vector<int>(r_num, 0));
    // 安全序列
    std::vector<int> ans;

    // 计算need矩阵
    for (int i = 0; i < p_num; ++i) {
        for (int j = 0; j < r_num; ++j) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    std::cout << "need:\n" << need;

    while (true) {
        int not_f = 0;
        // 每次进行process轮询
        for (int k = 0; k < p_num; ++k) {
            bool is_find = true;

            if (is_get[k]) {
                not_f++;
                continue;
            }

            for (int h = 0; h < r_num; ++h) {
                if (need[k][h] > available[h]) {
                    not_f++;
                    is_find = false;
                }
            }

//            std::cout << is_find << std::endl;

            if (is_find) {
                processFillPrinter(k);
                is_get[k] = true;
                ans.emplace_back(k + 1);
                recycleRes(k);
                std::cout << "now available is:\n" << available;
            }
        }

        std::cout << not_f << std::endl;

        if (not_f == p_num) {
            if (ans.size() == p_num) {
                std::cout << "will not appear deadlock! safe array is:\n" << ans;
                return;
            } else {
                std::cout << "can't alloc! will appear deadlock!" << std::endl;
                return;
            }
        }
    }


    return;
}

int main(void) {
    readData();
    mainAlgorithm();

    return 0;
}
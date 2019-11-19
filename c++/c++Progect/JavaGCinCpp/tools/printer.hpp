//
// Created by 13256 on 2019/11/19.
//

#ifndef JAVAGCINCPP_PRINTER_HPP
#define JAVAGCINCPP_PRINTER_HPP

#include <iostream>

template <typename content>
void constructorPrinter(content pContent) {
    std::cout << pContent << " 对象生成..." << std::endl;
}

template <typename content>
void destructorPrinter(content pContent) {
    std::cout << pContent << " 对象析构..." << std::endl;
}

template <typename content>
void newPrinter(content pContent) {
    std::cout << pContent << " new 分配内存..." << std::endl;
}

template <typename content>
void deletePrinter(content pContent) {
    std::cout << pContent << " delete 回收内存..." << std::endl;
}

inline void allocPrinter() {
    std::cout << "开始生成辣鸡" << std::endl;
}

inline void freePrinter() {
    std::cout << "开始回收辣鸡" << std::endl;
}

#endif //JAVAGCINCPP_PRINTER_HPP

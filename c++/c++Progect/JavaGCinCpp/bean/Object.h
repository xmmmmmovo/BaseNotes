//
// Created by 13256 on 2019/11/19.
//

#ifndef JAVAGCINCPP_OBJECT_H
#define JAVAGCINCPP_OBJECT_H

#include <iostream>

using namespace std;

class Object {

public:
    Object();

    /**
     * 单个进行重载
     * */
    void *operator new(size_t size);
    void operator delete(void *, size_t size);

    /**
     * 对于数组等容器进行重载
     * */
     void *operator new[](size_t size);
     void operator delete[](void *, size_t size);

    /**
     * 这里析构函数写成虚函数防止内存泄漏
     * */
    virtual ~Object();
};


#endif //JAVAGCINCPP_OBJECT_H

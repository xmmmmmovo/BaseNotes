//
// Created by 13256 on 2019/11/19.
//
#include "Object.h"
#include "../tools/printer.hpp"

Object::Object() {
    constructorPrinter("Object");
}

Object::~Object() {
    destructorPrinter("Object");
}

/**
 * 单个Object new delete重载
 * */
void *Object::operator new(size_t size) {
    newPrinter("Object");

    return malloc(size);
}

void Object::operator delete(void *, size_t size) {

}

/**
 * 下面是各种容器new delete重载
 * */
void *Object::operator new[](size_t size) {
    newPrinter("Object vector");

    return malloc(size);
}

void Object::operator delete[](void *, size_t size) {
    destructorPrinter("Object vector");
}



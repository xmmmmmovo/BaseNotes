cmake_minimum_required(VERSION 3.14)
project(JavaGCinCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(JavaGCinCpp main.cpp mem_alloc/AllocMem.cpp mem_alloc/AllocMem.h obj/Object.cpp obj/Object.h)
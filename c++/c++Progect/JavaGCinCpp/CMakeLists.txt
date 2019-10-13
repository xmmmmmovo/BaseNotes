cmake_minimum_required(VERSION 3.14)
project(JavaGCinCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(JavaGCinCpp main.cpp Gabage.cpp Gabage.h MemBlock.cpp MemBlock.h)
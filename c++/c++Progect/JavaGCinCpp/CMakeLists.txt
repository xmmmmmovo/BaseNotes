cmake_minimum_required(VERSION 3.14)
project(JavaGCinCpp)

set(CMAKE_CXX_STANDARD 14)
set(DCMAKE_TOOLCHAIN_FILE "C:/Local/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_executable(JavaGCinCpp main.cpp mem_alloc/AllocMem.cpp mem_alloc/AllocMem.h obj/Object.cpp obj/Object.h mem_alloc/PointCollector.cpp mem_alloc/PointCollector.h tools/printer.hpp)
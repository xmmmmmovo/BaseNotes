cmake_minimum_required(VERSION 3.14)
project(JavaGCinCpp)

set(CMAKE_CXX_STANDARD 14)
set(DCMAKE_TOOLCHAIN_FILE "C:/Local/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_executable(JavaGCinCpp main.cpp mem/AllocMem.cpp mem/AllocMem.h bean/Object.cpp bean/Object.h mem/PointCollector.cpp mem/PointCollector.h tools/printer.hpp)
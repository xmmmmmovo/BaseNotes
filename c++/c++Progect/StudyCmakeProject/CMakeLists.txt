cmake_minimum_required(VERSION 3.0)
project(study_cmake_test)
# set(BUILD_USE_64BITS on)

find_package(OpenCV REQUIRED)

add_executable(main main.cpp)

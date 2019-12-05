cmake_minimum_required(VERSION 3.10)
project(OperatorSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(exp21 exp2/ProcessStartMain.cpp)
add_executable(exp22 exp2/ProcessPipeMain.cpp)

add_executable(exp31 exp3/ProducerConsumerMain.cpp)
#thread
find_package(Threads)
target_link_libraries(exp31 ${CMAKE_THREAD_LIBS_INIT})

add_executable(exp41 exp4/BankAlgorithmMain.cpp)

add_executable(test_project TestMain.cpp)
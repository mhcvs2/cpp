cmake_minimum_required(VERSION 3.8)
project(set)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp set.h set.cpp)
add_executable(set ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.7)
project(staticLib)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c mylib/fred.c mylib/lib.h)
add_executable(staticLib ${SOURCE_FILES})
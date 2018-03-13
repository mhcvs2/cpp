cmake_minimum_required(VERSION 3.7)
project(AlienLanguageRecognizer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Solution.cpp)
add_executable(AlienLanguageRecognizer ${SOURCE_FILES})
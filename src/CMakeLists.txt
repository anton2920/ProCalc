cmake_minimum_required(VERSION 3.8)
project(src)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp libs/polynom.lib.cpp libs/polynom.main.cpp headers/header.h headers/polynom.h)
add_executable(src ${SOURCE_FILES})
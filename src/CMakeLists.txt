cmake_minimum_required(VERSION 3.13)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(files)
include_directories(headers)
include_directories(libs)

add_executable(src
        headers/header.h
        headers/polynom.h
        libs/polynom.lib.cpp
        libs/polynom.main.cpp
        main.cpp)

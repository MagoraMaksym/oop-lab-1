cmake_minimum_required(VERSION 4.1)
project(OOP_lab1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP_lab1
        cost.h
        main.cpp
        source.cpp)
file(COPY test.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
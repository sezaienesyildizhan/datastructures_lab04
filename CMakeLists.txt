cmake_minimum_required(VERSION 3.26)
project(commit1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(commit1
        Deque.cpp
        Deque.h
        main.cpp)

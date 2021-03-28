cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(search)

add_executable(search src/main.cpp src/read.cpp src/search.cpp src/print.cpp)

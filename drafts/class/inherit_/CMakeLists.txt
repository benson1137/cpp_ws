cmake_minimum_required(VERSION 2.8)

set(CXX_STANDARD_REQUIRED C++11)

project(template)

add_library(point point.cpp)
add_library(rectangle rectangle.cpp)
add_executable(a.out main.cpp)

target_link_libraries(a.out point)

set(CMAKE_BUILD_TYPE "Debug")


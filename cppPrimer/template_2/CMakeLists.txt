cmake_minimum_required(VERSION 2.8)

set(CXX_STANDARD_REQUIRED C++11)

project(template)

include_directories(".")

add_executable(a.out main.cpp)

set(CMAKE_BUILD_TYPE "Debug")


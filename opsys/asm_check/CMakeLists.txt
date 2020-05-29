cmake_minimum_required(VERSION 2.8)

set(CXX_STANDARD_REQUIRED C99)

project(template)
add_library(libtest libtest.c)
add_executable(a.out main.c)

target_link_libraries(a.out libtest)

set(CMAKE_BUILD_TYPE "Debug")


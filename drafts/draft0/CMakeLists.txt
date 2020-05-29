cmake_minimum_required(VERSION 2.8)

set(CXX_STANDARD_REQUIRED C++11)

project(template)

add_library(libAnimal Animal.cpp)

add_executable(a.out main.cpp)

target_link_libraries(a.out libAnimal)

set(CMAKE_BUILD_TYPE "Debug")


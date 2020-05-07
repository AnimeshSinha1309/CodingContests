cmake_minimum_required(VERSION 3.13)  # CMake version check
project(CompetitiveProgramming)
set(CMAKE_CXX_STANDARD 17)            # Enable c++14 standard

add_compile_options(-Wall -pedantic)

add_executable(Coding CodeForces/R637/E.cpp)

cmake_minimum_required(VERSION 3.10)

project(NQueens LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_executable(NQueens src/main.cpp src/NQueens.cpp)

target_include_directories(NQueens PRIVATE include)

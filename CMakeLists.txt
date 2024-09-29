cmake_minimum_required(VERSION 3.28)
project(cmpt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)

add_executable(cry src/main.cpp src/fetch/one.cpp)
target_include_directories(cry PUBLIC include/)
target_include_directories(cry PRIVATE include/internal)

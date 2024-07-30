cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(PROJECT_NAME LNES)

project(${PROJECT_NAME})

set(CMAKE_CXX_COMPILER, "g++")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

add_executable(${PROJECT_NAME}
    src/main.cpp
    include/mem.hpp
    src/cpu.cpp
    include/cpu.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)
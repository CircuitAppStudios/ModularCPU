cmake_minimum_required(VERSION 3.13)
project(ModularCPU)

set(CMAKE_CXX_STANDARD 11)

add_executable(ModularCPU main.cpp Timer.cpp Timer.h Logger.cpp Logger.h)
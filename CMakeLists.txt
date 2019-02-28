cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project ("socialNetwork")

set (CMAKE_C_COMPILER "gcc")
set (CMAKE_CXX_COMPILER "g++")
set (CMAKE_CXX_FLAGS "-std=c++17")




add_executable(socialNetwork socialNetwork.cpp,main.cpp)

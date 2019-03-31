cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project ("socialNetwork")

if(APPLE)
	set (CMAKE_CXX_COMPILER "clang++")
	set (CMAKE_CXX_FLAGS "-std=c++17 -stdlib=libc++ -std=c++1y")
else()
	set (CMAKE_C_COMPILER "gcc-5")
	set (CMAKE_CXX_COMPILER "g++-5")
	set (CMAKE_CXX_FLAGS "-std=c++17")
endif()

add_executable(socialNetwork socialNetwork.cpp main.cpp)

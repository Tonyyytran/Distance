cmake_minimum_required(VERSION 3.16)
project(Distance)

set(CMAKE_CXX_STANDARD 14)

add_executable(Distance distanceDriver.cpp distance.h distance.cpp)
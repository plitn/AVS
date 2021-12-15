cmake_minimum_required(VERSION 3.21)
project(threads_avs)

set(CMAKE_CXX_STANDARD 17)

add_executable(threads_avs main.cpp cabinet.h cabinet.cpp)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
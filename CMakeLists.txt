cmake_minimum_required(VERSION 3.20)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")


add_executable(untitled2 main.cpp rectangle.h triangle.h circle.h triangle.cpp rnd.h circle.cpp rectangle.cpp shape.h shape.cpp container.h container.cpp)

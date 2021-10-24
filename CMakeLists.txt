cmake_minimum_required(VERSION 3.21)
project(avs2)

set(CMAKE_CXX_STANDARD 17)

add_executable(avs2 main.cpp shape.h shape.cpp rnd.h triangle.h triangle.cpp rectangle.h rectangle.cpp circle.h circle.cpp container.h container.cpp)

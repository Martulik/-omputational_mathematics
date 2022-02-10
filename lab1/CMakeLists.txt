cmake_minimum_required(VERSION 3.17)

project(lab1)

set(CMAKE_CXX_STANDARD 14)

include_directories(../software)

add_executable(lab1 main.cpp data.hpp ../software/SPLINE.CPP)

cmake_minimum_required(VERSION 3.17)
project(lab3)

set(CMAKE_CXX_STANDARD 14)
include_directories(../software)

add_executable(lab3 main.cpp ../software/RKF45.CPP data.hpp)

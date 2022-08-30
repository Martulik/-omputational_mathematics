cmake_minimum_required(VERSION 3.17)
project(estimation_parameters)

set(CMAKE_CXX_STANDARD 14)
include_directories(../software)
include_directories(../software)
add_executable(estimation_parameters main.cpp data.hpp ../software/QUANC8.CPP ../software/FMIN.CPP ../software/RKF45.CPP)

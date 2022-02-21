cmake_minimum_required(VERSION 3.17)

project(lab2)

set(CMAKE_CXX_STANDARD 14)

include_directories(../software)

add_executable(lab2 main.cpp ../software/DECOMP.CPP data.hpp)

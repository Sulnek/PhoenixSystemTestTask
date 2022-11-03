cmake_minimum_required(VERSION 3.23)
project(PStestTask C)

set(CMAKE_C_STANDARD 23)

add_executable(PStestTask main.c IP_V4.c IP_V4.h)

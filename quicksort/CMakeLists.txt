cmake_minimum_required(VERSION 3.16)
project(quicksort C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -fopenmp")

add_executable(quicksort main.c)
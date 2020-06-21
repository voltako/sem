cmake_minimum_required(VERSION 3.15)
project(3zad2 C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -fopenmp")

add_executable(3zad2 main.c)
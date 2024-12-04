cmake_minimum_required(VERSION 3.28)
project(student_tmp C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(student_tmp
        students.c
        students.h)

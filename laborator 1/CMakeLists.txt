cmake_minimum_required(VERSION 3.29)
project(laborator_1_mai_ok C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(laborator_1_mai_ok
    functions.c
    functions.h
    main.c
    structs.h)

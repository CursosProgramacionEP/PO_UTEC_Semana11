cmake_minimum_required(VERSION 3.20)
project(A2_Universidad)

set(CMAKE_CXX_STANDARD 20)

add_executable(A2_Universidad main.cpp
        Universidad.cpp
        Universidad.h
        Alumno.cpp
        Alumno.h
        Curso.cpp
        Curso.h
)

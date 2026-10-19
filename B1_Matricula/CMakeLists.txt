cmake_minimum_required(VERSION 3.20)
project(B1_Matricula)

set(CMAKE_CXX_STANDARD 20)

add_executable(B1_Matricula main.cpp
        CSeccion.cpp
        CSeccion.h
        CCurso.cpp
        CCurso.h
        CProfesor.cpp
        CProfesor.h
        CLaboratorio.cpp
        CLaboratorio.h
        CAlumno.cpp
        CAlumno.h
        Tipos.h
)

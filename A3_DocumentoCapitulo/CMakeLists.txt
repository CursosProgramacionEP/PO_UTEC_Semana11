cmake_minimum_required(VERSION 3.20)
project(A3_DocumentoCapitulo)

set(CMAKE_CXX_STANDARD 20)

add_executable(A3_DocumentoCapitulo main.cpp
        Documento.cpp
        Documento.h
        Capitulo.cpp
        Capitulo.h
)

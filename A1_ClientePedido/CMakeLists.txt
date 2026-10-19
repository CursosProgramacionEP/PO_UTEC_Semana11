cmake_minimum_required(VERSION 3.20)
project(A1_ClientePedido)

set(CMAKE_CXX_STANDARD 20)

add_executable(A1_ClientePedido main.cpp
        Cliente.cpp
        Cliente.h
        Pedido.cpp
        Pedido.h
)

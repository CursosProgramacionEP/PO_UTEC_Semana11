cmake_minimum_required(VERSION 3.20)
project(A4_BattleBot)

set(CMAKE_CXX_STANDARD 20)

add_executable(A4_BattleBot main.cpp
        CBattleBox.cpp
        CBattleBox.h
        CRobot.cpp
        CRobot.h
        CObstaculo.cpp
        CObstaculo.h
        CCoordenada.cpp
        CCoordenada.h
        Tipos.h
)

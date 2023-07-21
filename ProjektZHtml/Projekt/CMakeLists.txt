cmake_minimum_required(VERSION 3.19)
project(Projekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp
             Pokemon.cpp
             Pokemon.h Gracz.cpp Gracz.h MocSpecjalna.cpp MocSpecjalna.h Walka.cpp Walka.h)

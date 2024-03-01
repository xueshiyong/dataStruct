cmake_minimum_required(VERSION 3.27)
project(dataStruct)

set(CMAKE_CXX_STANDARD 14)

add_executable(dataStruct
        Vector/Vector.cpp
        Vector/Vector.h
        config.h
        main.cpp
        String/String.cpp
        String/String.h)

cmake_minimum_required(VERSION 3.27)
project(CompilerLab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(CompilerLab1 main.cpp
        Scanner2.hpp
        Scanner2.cpp
        TokenType.hpp
        t2.i
        Scanner.hpp
        Scanner.cpp
        Parser.hpp
        Parser.cpp
)

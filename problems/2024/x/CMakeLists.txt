cmake_minimum_required(VERSION 3.29)
project(x)

set(CMAKE_CXX_STANDARD 20)

add_executable(x main.cpp
        credit/credit.cpp
        credit/cs50.cpp
        credit/cs50.h
)

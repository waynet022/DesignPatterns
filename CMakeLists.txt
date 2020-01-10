cmake_minimum_required(VERSION 3.15)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 17)

add_executable(DesignPatterns main.cpp)

add_executable(Single SOLIDDesignPrinciples/SingleResponsabilityPrinciple.cpp)

add_executable(OpenClosed SOLIDDesignPrinciples/OpenClosed.cpp)
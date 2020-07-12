cmake_minimum_required(VERSION 3.13)
project(faang)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE FILES
    leet_code/*.hpp
    leet_code/*.cpp
    pramp/*.hpp
    pramp/*.cpp)

add_executable( ${PROJECT_NAME} main.cpp ${FILES})

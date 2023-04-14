cmake_minimum_required(VERSION 3.10)

project(example)

set(CMAKE_CXX_STANDARD 11)

file(GLOB
        SOURCES
        *.cpp
        )

add_executable(example ${SOURCES} main.cpp)
target_link_libraries(example xWrapUp)
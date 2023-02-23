cmake_minimum_required(VERSION 3.10)

project(xWrapUp)

set(CMAKE_CXX_STANDARD 11)

include_directories(inc)

file(GLOB
        SOURCES
        src/*.cpp
        )

add_library(xWrapUp STATIC ${SOURCES})
target_include_directories(xWrapUp PUBLIC .)

add_subdirectory(examples)

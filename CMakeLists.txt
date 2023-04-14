cmake_minimum_required(VERSION 3.10)

project(xWrapUp)

set(CMAKE_CXX_STANDARD 11)

# depress suggest-override
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-inconsistent-missing-override")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-inconsistent-missing-override")

include_directories(inc)

file(GLOB
        SOURCES
        src/*.cpp
        src/iface/*.cpp
        )

add_library(xWrapUp STATIC ${SOURCES})
target_include_directories(xWrapUp PUBLIC .)

add_subdirectory(examples)

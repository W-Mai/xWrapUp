cmake_minimum_required(VERSION 3.10)

project(example)

# C/C++ version
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# Platform config
## Common
add_definitions(
        #        -DLV_USE_FS_POSIX=1
        -DLV_USE_LOG=1
        -DLV_USE_ASSERT=1
        -DLV_SCREEN_HOR_RES=700
        -DLV_SCREEN_VER_RES=700
        -DLV_USE_DEV_VERSION=1
)

## Others
if (WIN32)
    message(STATUS "Platform: windows")

    add_definitions(-DUSE_WIN32DRV=1)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Simulator)
elseif (UNIX)
    message(STATUS "Platform: UNIX")

    add_definitions(-DUSE_SDL=1 -DHAVE_UNISTD_H=1 -DHAVE_FCNTL_H=1)
    find_package(SDL2 REQUIRED SDL2)
    include_directories(
            ${SDL2_INCLUDE_DIRS}
            ${SDL2_INCLUDE_DIRS}/../
            ${PROJECT_SOURCE_DIR}
    )

    # Address Sanitizer
    if (DISABLE_ASAN)
        set(ASAN_FLAGS "-fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer")
        add_definitions(${ASAN_FLAGS})
        set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} ${ASAN_FLAGS})
    endif ()

endif ()

# Sources
## lvgl porting
file(GLOB LV_PORT_SOURCES "lv_port/*.c")

# Subdirectory
add_subdirectory(lvgl ${PROJECT_BINARY_DIR}/build_lvgl)

file(GLOB
        SOURCES
        *.cpp
        )


add_executable(example ${LV_PORT_SOURCES} ${SOURCES} ${INCLUDES} main.cpp)
target_link_libraries(example PRIVATE
        xWrapUp
        lvgl
        ${SDL2_LIBRARIES})


# Executable
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_executable(Simulator main.cpp ${SOURCES} ${INCLUDES})

# Link
target_link_libraries(
        Simulator PRIVATE
        lvgl
        lvgl::examples
        lvgl::demos
        ${SDL2_LIBRARIES}
)

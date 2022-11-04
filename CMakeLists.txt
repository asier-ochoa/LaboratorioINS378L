cmake_minimum_required(VERSION 3.23)
project(LabINS378)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(UNIX)
    add_compile_definitions(UNIX)
endif()
if(WIN32)
    add_compile_definitions(WIN32)
endif()

add_subdirectory(Lab1)
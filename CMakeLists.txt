cmake_minimum_required(VERSION 3.22)
project(LabINS378)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(wxWidgets)

if(UNIX)
    add_compile_definitions(UNIX)
endif()
if(WIN32)
    add_compile_definitions(WIN32)
endif()

add_subdirectory(Lab1)
add_subdirectory(Lab2)

add_subdirectory(Teoria1)
add_subdirectory(Teoria2)
add_subdirectory(wxTest)
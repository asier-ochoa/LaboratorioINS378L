file(GLOB SRC_FILES *.cpp)
add_executable(CircleDraw ${SRC_FILES})
target_link_libraries(CircleDraw wx::net wx::core wx::base)
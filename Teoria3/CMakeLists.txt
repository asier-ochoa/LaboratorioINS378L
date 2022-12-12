add_executable(CircleDraw main.cpp)
add_executable(Triangles triangles.cpp)
target_link_libraries(CircleDraw wx::net wx::core wx::base)
target_link_libraries(Triangles wx::net wx::core wx::base)

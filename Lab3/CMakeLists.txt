add_executable(queue queue.cpp)
add_executable(stack stack.cpp)
add_executable(amortizacion amortizacion.cpp)
target_include_directories(queue PRIVATE ../include)
target_link_libraries(queue PRIVATE raylib $<TARGET_OBJECTS:rlImGui> $<TARGET_OBJECTS:imgui>)
target_include_directories(amortizacion PRIVATE ../include)
target_link_libraries(amortizacion PRIVATE raylib $<TARGET_OBJECTS:rlImGui> $<TARGET_OBJECTS:imgui>)

file(GLOB SRC_FILES *.cpp)
add_executable(AI_TicTacToe ${SRC_FILES})
target_link_libraries(AI_TicTacToe wx::net wx::core wx::base)
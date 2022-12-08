file(GLOB SRC_FILES *.cpp)
add_executable(TicTacToe ${SRC_FILES})
target_link_libraries(TicTacToe wx::net wx::core wx::base)
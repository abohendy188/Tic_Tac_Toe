cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add the main executable
add_executable(TicTacToe
    src/main_tic.cpp
    src/TicTacToe.cpp
)

# Add Google Test
enable_testing()
add_subdirectory(googletest)

# Add unit tests
add_executable(runUnitTests
    tests/Test_TicTacToe.cpp
    src/TicTacToe.cpp  # Make sure TicTacToe.cpp is included here
)
target_link_libraries(runUnitTests gtest gtest_main)

# Add integration tests
add_executable(runIntegrationTests
    tests/Integration_Test.cpp
    src/TicTacToe.cpp  # Add TicTacToe.cpp here as well
)
target_link_libraries(runIntegrationTests gtest gtest_main)

# Add custom test commands
add_test(NAME unitTests COMMAND runUnitTests)
add_test(NAME integrationTests COMMAND runIntegrationTests)

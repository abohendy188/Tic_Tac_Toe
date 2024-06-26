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

# Set the path to Google Test (assuming it's in the project directory)
set(GTEST_DIR ${CMAKE_SOURCE_DIR}/googletest)

# Add Google Test
enable_testing()
add_subdirectory(${GTEST_DIR})

# Add unit tests
add_executable(runUnitTests tests/Test_TicTacToe.cpp)
target_link_libraries(runUnitTests gtest gtest_main)

# Add integration tests
add_executable(runIntegrationTests tests/Integration_Test.cpp)
target_link_libraries(runIntegrationTests gtest gtest_main)

# Add custom test commands
add_test(NAME unitTests COMMAND runUnitTests)
add_test(NAME integrationTests COMMAND runIntegrationTests)

cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add the executable
add_executable(TicTacToe
    src/main_tic.cpp
    src/TicTacToe.cpp
)

# Add Google Test
enable_testing()
add_subdirectory(external/googletest)  # Ensure googletest is in the 'external' folder

# Link Google Test to the unit tests
add_executable(runUnitTests tests/Test_TicTacToe.cpp)
target_link_libraries(runUnitTests gtest gtest_main)

# Link Google Test to the integration tests
add_executable(runIntegrationTests tests/Integration_Test.cpp)
target_link_libraries(runIntegrationTests gtest gtest_main)

# Add custom test commands
add_test(NAME unitTests COMMAND runUnitTests)
add_test(NAME integrationTests COMMAND runIntegrationTests)

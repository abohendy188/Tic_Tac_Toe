# CMake generated Testfile for 
# Source directory: D:/Project_testing/Github/Tic_Tac_Toe
# Build directory: D:/Project_testing/Github/Tic_Tac_Toe/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unitTests "D:/Project_testing/Github/Tic_Tac_Toe/build/runUnitTests.exe")
set_tests_properties(unitTests PROPERTIES  _BACKTRACE_TRIPLES "D:/Project_testing/Github/Tic_Tac_Toe/CMakeLists.txt;33;add_test;D:/Project_testing/Github/Tic_Tac_Toe/CMakeLists.txt;0;")
add_test(integrationTests "D:/Project_testing/Github/Tic_Tac_Toe/build/runIntegrationTests.exe")
set_tests_properties(integrationTests PROPERTIES  _BACKTRACE_TRIPLES "D:/Project_testing/Github/Tic_Tac_Toe/CMakeLists.txt;34;add_test;D:/Project_testing/Github/Tic_Tac_Toe/CMakeLists.txt;0;")
subdirs("googletest")

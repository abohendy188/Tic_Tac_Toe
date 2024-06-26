#include <gtest/gtest.h>
#include "TicTacToe.hpp"

// Integration test fixture
class TicTacToeIntegrationTest : public ::testing::Test {
protected:
    char board[3][3];

    void SetUp() override {
        initArray(board);
    }

    void simulateMove(char symbols[3][3], int row, int col, char player) {
        symbols[row][col] = player;
    }
};

// Test Game Initialization
TEST_F(TicTacToeIntegrationTest, TestGameInitialization) {
    initArray(board);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            EXPECT_EQ(board[i][j], ' ');
        }
    }
}


// Test Two-Player Mode , Player 1 Wins
TEST_F(TicTacToeIntegrationTest, TestTwoPlayerMode) {
    initArray(board);
    // Player 1 moves
    simulateMove(board, 0, 0, 'X');
    // Player 2 moves
    simulateMove(board, 0, 1, 'O');
    // Player 1 moves
    simulateMove(board, 1, 1, 'X');
    // Player 2 moves
    simulateMove(board, 0, 2, 'O');
    // Player 1 moves
    simulateMove(board, 2, 2, 'X');
    /*
        X O O
        - X -
        - - X
    */
    
    //drawBoard(board);
    int result = checkWin(board);
    EXPECT_EQ(result, 2);  // Player 1 wins
}

// Test Player 2 Winning
TEST_F(TicTacToeIntegrationTest, TestPlayer2Wins) {
    initArray(board);
    // Player 1 moves
    simulateMove(board, 0, 0, 'X');
    // Player 2 moves
    simulateMove(board, 0, 1, 'O');
    // Player 1 moves
    simulateMove(board, 1, 0, 'X');
    // Player 2 moves
    simulateMove(board, 1, 1, 'O');
    // Player 1 moves
    simulateMove(board, 2, 2, 'X');
    // Player 2 moves
    simulateMove(board, 2, 1, 'O');  // Winning move
    /* X  O  -
       X  O  -
       -  O  X
    */

    //drawBoard(board);
    int result = checkWin(board);
    EXPECT_EQ(result,-2);  // Player 2 (O) wins
}

// Test Draw Scenario
TEST_F(TicTacToeIntegrationTest, TestDrawScenario) {
    // Simulate a full game that results in a draw
    simulateMove(board, 0, 0, 'X');
    simulateMove(board, 0, 1, 'O');
    simulateMove(board, 0, 2, 'X');
    simulateMove(board, 1, 1, 'O');
    simulateMove(board, 1, 0, 'X');
    simulateMove(board, 2, 0, 'O');
    simulateMove(board, 1, 2, 'X');
    simulateMove(board, 2, 2, 'O');
    simulateMove(board, 2, 1, 'X');

    /*
        X O X
        X O X
        O X O
    */

    //drawBoard(board);
    int result = checkWin(board);
    EXPECT_EQ(result, 0);  // Game is a draw
}




// Test AI Mode (Easy)
TEST_F(TicTacToeIntegrationTest, TestAIModeEasy) {
    initArray(board);
    int rowIndex, colIndex, result = 1, gameLevel = 0;

    // Simulate player's move
    simulateMove(board, 0, 0, 'X');
    //drawBoard(board);

    // Simulate AI move
    getComputerMove(board);
    //drawBoard(board);
    result = checkWin(board);

    EXPECT_NE(result, 2);  // AI should not win immediately
    EXPECT_NE(result, -2); // Player should not win immediately
}



// Test AI Mode (Intermediate)
TEST_F(TicTacToeIntegrationTest, TestAIModeIntermediate) {
    initArray(board);
    int rowIndex, colIndex, result = 1, gameLevel = 0;

    // Simulate player's move
    simulateMove(board, 0, 0, 'X');
    //drawBoard(board);

    // Simulate AI move
    getComputerMove(board);
    //drawBoard(board);
    result = checkWin(board);

    EXPECT_NE(result, 2);  // AI should not win immediately
    EXPECT_NE(result, -2); // Player should not win immediately
}


// Test AI Mode (Hard)
TEST_F(TicTacToeIntegrationTest, TestAIModeHard) {
    initArray(board);
    int rowIndex, colIndex, result = 1, gameLevel = 1;

    // Simulate player's move
    simulateMove(board, 0, 0, 'X');
    //drawBoard(board);

    // Simulate AI move 
    miniMax(board, true);
   // drawBoard(board);
    result = checkWin(board);

    EXPECT_NE(result, 2);  // AI should not win immediately
    EXPECT_NE(result, -2); // Player should not win immediately
}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
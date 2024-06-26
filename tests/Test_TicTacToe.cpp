#include <gtest/gtest.h>
#include "TicTacToe.hpp"



// Test the initialization of the board
TEST(TicTacToeTest, InitArray) {
    char board[3][3];
    initArray(board);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            EXPECT_EQ(board[i][j], ' ');
        }
    }
}

TEST(TicTacToeTest, ResetBoard) {
    char board[3][3] = {{'X', 'O', 'X'}, 
                        {'O', 'X', 'O'}, 
                        {'O', 'X', ' '}};
    initArray(board);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            EXPECT_EQ(board[i][j], ' ');
        }
    }
}




// Test drawing the board
// TEST(TicTacToeTest, DrawBoard) {
//     char board[3][3] = {{'X', 'O', 'X'},
//                         {'O', 'X', 'O'}, 
//                         {'X', 'O', 'X'}};
//     testing::internal::CaptureStdout();
//     drawBoard(board);
//     std::string output = testing::internal::GetCapturedStdout();
//     std::string expectedOutput = 
//         "\f\t\t\t\t\t\t X | O | X\n"
//         "\t\t\t\t\t\t-----------\n"
//         "\t\t\t\t\t\t O | X | O\n"
//         "\t\t\t\t\t\t-----------\n"
//         "\t\t\t\t\t\t X | O | X\n\n\n\n\n";
//     EXPECT_EQ(output, expectedOutput);
// }

TEST(TicTacToeTest, DrawBoard) {
    char board[3][3] = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'X', 'O', 'X'}
    };
    std::string output = drawBoard(board);
    std::string expectedOutput = 
        "\t\t\t\t\t\t X | O | X\n"
        "\t\t\t\t\t\t-----------\n"
        "\t\t\t\t\t\t O | X | O\n"
        "\t\t\t\t\t\t-----------\n"
        "\t\t\t\t\t\t X | O | X\n\n\n\n\n";
    EXPECT_EQ(output, expectedOutput);
}



// Test choosing play mode
TEST(TicTacToeTest, ChoosePlayMode) {
    // Simulate user input for mode selection
    std::istringstream input("0\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(choose_play_mode(), 0);
    
    input.str("1\n");
    input.clear();
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(choose_play_mode(), 1);
}
TEST(TicTacToeTest, ChoosePlayModeWithInvalidInput) {
    std::istringstream input("2\n0\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(choose_play_mode(), 0);

    input.str("3\n1\n");
    input.clear();
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(choose_play_mode(), 1);
}




// Test getting two player symbols
TEST(TicTacToeTest, GetTwoPlayerSymbols) {
    char player_one, player_two;
    std::istringstream input("X\n");
    std::cin.rdbuf(input.rdbuf());
    get_two_player_symbols(player_one, player_two);
    EXPECT_EQ(player_one, 'X');
    EXPECT_EQ(player_two, 'O');

    input.str("O\n");
    input.clear();
    std::cin.rdbuf(input.rdbuf());
    get_two_player_symbols(player_one, player_two);
    EXPECT_EQ(player_one, 'O');
    EXPECT_EQ(player_two, 'X');
}

// Test checkWin function
TEST(TicTacToeTest, CheckWin) {
    //Check general board
    char board1[3][3] = {{'X', 'X', 'X'}, 
                        {'O', ' ', 'O'},   
                        {' ', ' ', ' '}};
    EXPECT_EQ(checkWin(board1), 2);
    
    //check rows 
    char board2[3][3] = {{'X', ' ', 'X'}, 
                        {'O', 'O', 'O'},   
                        {' ', ' ', ' '}}; //row2
    EXPECT_EQ(checkWin(board2), -2);

    char board3[3][3] = {{'O', ' ', 'O'}, 
                        {'X', 'X', 'X'},   
                        {' ', ' ', ' '}};//row2
    EXPECT_EQ(checkWin(board3), 2);

    char board4[3][3] = {{' ', ' ', ' '}, 
                        {'X', ' ', 'X'},   
                        {'O', 'O', 'O'}}; //row3
    EXPECT_EQ(checkWin(board4), -2);

    //check columns
        char board5[3][3] = {{'X', ' ', 'O'}, 
                            {'X', 'O', 'O'},   
                            {'X', ' ', ' '}};// col1 
    EXPECT_EQ(checkWin(board5), 2);
    
    char board6[3][3] = {{'X', 'O', ' '}, 
                        {'X', 'O', ' '},   
                        {' ', 'O', ' '}}; //col2
    EXPECT_EQ(checkWin(board6), -2);

    char board7[3][3] = {{' ', ' ', 'O'}, 
                        {'X', 'X', 'O'},   
                        {' ', ' ', 'O'}}; //col3
    EXPECT_EQ(checkWin(board7), -2);
    

    // check diagonals 
        char board8[3][3] = {{'X', ' ', 'O'}, 
                            {' ', 'X', 'O'},   
                            {' ', ' ', 'X'}}; // main diagonal
        EXPECT_EQ(checkWin(board8), 2);

        char board9[3][3] = {{' ', ' ', 'O'}, 
                            {'X', 'O', 'X'},   
                            {'O', ' ', ' '}}; // The other Diagonal
        EXPECT_EQ(checkWin(board9), -2);

    //  check tie
    char tieBoard[3][3] = {{'X', 'O', 'X'}, 
                           {'O', 'X', 'O'}, 
                           {'O', 'X', 'O'}};
    EXPECT_EQ(checkWin(tieBoard), 0);
}


// Test exitGame function
TEST(TicTacToeTest, ExitGame) {
    char winBoard[3][3] = {{'X', 'X', 'X'}, 
                           {'O', ' ', 'O'},     
                           {' ', ' ', ' '}};
    testing::internal::CaptureStdout();
    EXPECT_TRUE(exitGame(winBoard));
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Congratulation! You win.\n");

    char loseBoard[3][3] = {{'O', 'O', 'O'}, 
                            {'X', ' ', 'X'},    
                            {' ', ' ', ' '}};
    testing::internal::CaptureStdout();
    EXPECT_TRUE(exitGame(loseBoard));
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sorry! You loss.\n");

    char tieBoard[3][3] = {{'X', 'O', 'X'}, 
                           {'O', 'X', 'O'}, 
                           {'O', 'X', 'O'}};
    testing::internal::CaptureStdout();
    EXPECT_TRUE(exitGame(tieBoard));
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "No winner, it is a tie.\n");

    char ongoingBoard[3][3] = {{'X', 'O', 'X'}, 
                               {'O', ' ', 'O'}, 
                               {'O', 'X', ' '}};
    EXPECT_FALSE(exitGame(ongoingBoard));
}




// Test checkWin_Two_Players function
TEST(TicTacToeTest, CheckWinTwoPlayers) {
    char board[3][3] = {{'X', 'X', 'X'}, 
                        {'O', ' ', 'O'}, 
                        {' ', ' ', ' '}};
    EXPECT_EQ(checkWin_Two_Players(board, 'X', 'O'), 2);
    
    board[0][0] = 'O'; board[0][1] = 'O'; board[0][2] = 'O';
    EXPECT_EQ(checkWin_Two_Players(board, 'X', 'O'), -2);

    board[0][0] = 'X'; board[1][0] = 'X'; board[2][0] = 'X';
    EXPECT_EQ(checkWin_Two_Players(board, 'X', 'O'), 2);
    
    board[0][0] = 'O'; board[1][0] = 'O'; board[2][0] = 'O';
    EXPECT_EQ(checkWin_Two_Players(board, 'X', 'O'), -2);
    
    char tieBoard[3][3] = {{'X', 'O', 'X'}, 
                           {'O', 'X', 'O'}, 
                           {'O', 'X', 'O'}};
    EXPECT_EQ(checkWin_Two_Players(tieBoard, 'X', 'O'), 0);
}





// Test case for getRandomMove function
TEST(TicTacToeTest, GetRandomMoveTest) {
    char symbols[3][3];  // Initialize symbols array
    initArray(symbols);  // Ensure symbols are initialized with empty spaces

    // Call getRandomMove
    getRandomMove(symbols);

    // Calculate empty count after getRandomMove
    int emptyCount = calculateEmptyCount(symbols);

    // Assert that emptyCount is 8 (assuming getRandomMove fills one spot)
    EXPECT_EQ(emptyCount, 8);
}






// Test case for getComputerMove function
TEST(TicTacToeTest, GetComputerMoveTest) {
    // Test case 1: board where 'O' should be placed in board[0][2]
    char board[3][3] = {
        {'X', ' ', ' '},
        {' ', 'X', ' '},
        {' ', 'O', 'O'}
    };

    // Call getComputerMove on board
    getComputerMove(board);

    // Assert that the expected move was made on board[0][2]
    EXPECT_EQ(board[2][0], 'O') << "Expected 'O' at board[0][2]";

    // Test case 2: board2 where 'O' should be placed in board2[0][2]
    char board2[3][3] = {
        {' ', 'X', ' '},
        {'X', ' ', 'O'},
        {' ', ' ', 'O'}
    };

    // Call getComputerMove on board2
    getComputerMove(board2);

    // Assert that the expected move was made on board2[0][2]
    EXPECT_EQ(board2[0][2], 'O') << "Expected 'O' at board2[0][2]";
}









// Test miniMax function
TEST(TicTacToeTest, MiniMax) {
    char board[3][3] = {{'X', 'X', ' '},
                        {' ', 'O', ' '},   
                        {' ', ' ', ' '}};
    EXPECT_EQ(miniMax(board, true, true), 2); // AI moves
    EXPECT_EQ(board[0][2] , 'O');

    char board2[3][3] = {{'X', 'O', 'X'}, 
                         {' ', 'O', ' '},   
                         {' ', ' ', 'X'}};
    EXPECT_EQ(miniMax(board2, true, true), 2); // AI moves to win
    EXPECT_EQ(board2[1][2] , 'O');

    char board3[3][3] = {{'X', 'O', 'X'}, 
                        {'X', 'O', 'O'},   
                        {'O', 'X', ' '}};
    EXPECT_EQ(miniMax(board3, true, true), 0);  // Expect tie
}





int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

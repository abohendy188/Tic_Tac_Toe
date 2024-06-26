// tic_tac_toe.cpp

#include "TicTacToe.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

// Function to count empty spaces in symbols array
int calculateEmptyCount(const char symbols[3][3]) {
    int count = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (symbols[i][j] == ' ') {
                count++;
            }
        }
    }
    return count;
}
//----------------Functions----------------------------------------------------------


// 1------- function to initialize the array of symbols by space character(as a sign for being empty).
void initArray(char symbols[][3])
 {
    for (int counter_1 = 0; counter_1 < 3; counter_1++)
        for (int counter_2 = 0; counter_2 < 3; counter_2++)
            symbols[counter_1][counter_2] = ' ';
}

// 2-----function to draw the board
// void drawBoard(const char symbols[3][3])
//  {
//     system("cls");
//     cout << "\t\t\t\t\t\t" << " " << symbols[0][0] << " | " << symbols[0][1] << " | " << symbols[0][2] << endl;
//     cout << "\t\t\t\t\t\t" << "-----------" << endl;
//     cout << "\t\t\t\t\t\t" << " " << symbols[1][0] << " | " << symbols[1][1] << " | " << symbols[1][2] << endl;
//     cout << "\t\t\t\t\t\t" << "-----------" << endl;
//     cout << "\t\t\t\t\t\t" << " " << symbols[2][0] << " | " << symbols[2][1] << " | " << symbols[2][2] << endl;
//     cout << "\n\n\n\n";
// }

std::string drawBoard(const char board[3][3]) {
    std::string boardStr = "\n\t\t\t\t\t\t";
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            boardStr += board[row][col];
            if (col < 2) boardStr += " | ";
        }
        if (row < 2) boardStr += "\n\t\t\t\t\t\t-----------\n\t\t\t\t\t\t";
    }
    boardStr += "\n\n\n\n\n";
    return boardStr;
}

//3-------function to choose the playmode 
int choose_play_mode() {
    int mode;
    cout << "What mode you want to play?" << endl << "Enter:\n0 for two players mode\n1 to play with the computer\n";
    do
    {
       cin >> mode;
       if((0==mode) || (1 == mode))
       {
        break ;
       }
       else if((0!=mode) || (1 != mode)) 
       {
        cout<< "Please Enter Valid Inputs ,\" 0-> for two players mode & 1-> to play with the computer \" \n";
       }
    } while ((mode!=0) || (mode!=1));
    
    
    return mode;
}

//4------function to get the player symbol for two players mode
void get_two_player_symbols(char &player_one, char &player_two) {
    cout << "Player 1 should choose what symbol to play with!, \" Press X or O \" \n";
    cin >> player_one;
    cin.ignore();
    if (player_one == 'X' || player_one == 'x') {
        player_two = 'O';
        cout<< "Now Player 1 is \" X \" and Player 2 is \" O \" \n";
    } else {
        player_two = 'X';
        player_one = 'O' ;
        cout<< "Now Player 1 is \" O \" and Player 2 is \" X \" \n";
    }
}

//5------Function to check the win
int checkWin(const char symbols[][3]) {
    // check the rows
    for (int counter = 0; counter < 3; counter++)
        if (symbols[counter][0] != ' ' && symbols[counter][0] == symbols[counter][1] && symbols[counter][0] == symbols[counter][2])
            return (symbols[counter][0] == 'X' ? 2 : -2);

    // check the columns
    for (int counter = 0; counter < 3; counter++)
        if (symbols[0][counter] != ' ' && symbols[0][counter] == symbols[1][counter] && symbols[0][counter] == symbols[2][counter])
            return (symbols[0][counter] == 'X' ? 2 : -2);

    // check the diagonal
    if (symbols[0][0] != ' ' && symbols[0][0] == symbols[1][1] && symbols[0][0] == symbols[2][2]) {
        return (symbols[0][0] == 'X' ? 2 : -2);
    }
    if (symbols[0][2] != ' ' && symbols[0][2] == symbols[1][1] && symbols[0][2] == symbols[2][0]) {
        return (symbols[0][2] == 'X' ? 2 : -2);
    }
    bool tie = true;
    for (int counter_1 = 0; counter_1 < 3; counter_1++)
        for (int counter_2 = 0; counter_2 < 3; counter_2++)
            if (symbols[counter_1][counter_2] == ' ')
                tie = false;
    if (tie)
        return 0;
    else
        return 1;
}

//6----function to check if the game ended.
bool exitGame(const char symbols[][3]) {
    int result = checkWin(symbols);
    if (result == 2 ) {
        cout << "Congratulation! You win.\n";
        return true;
    }
    if (result == -2) {
        cout << "Sorry! You loss.\n";
        return true;
    }
    if (result == 0) {
        cout << "No winner, it is a tie.\n";
        return true;
    }
    return false;
}

//7---------------Function to check the win in case of two players
int checkWin_Two_Players(const char symbols[][3], char player_one, char player_two) {
    // check the rows
    for (int counter = 0; counter < 3; counter++)
        if (symbols[counter][0] != ' ' && symbols[counter][0] == symbols[counter][1] && symbols[counter][0] == symbols[counter][2])
            return (symbols[counter][0] == player_one ? 2 : -2);

    // check the columns
    for (int counter = 0; counter < 3; counter++)
        if (symbols[0][counter] != ' ' && symbols[0][counter] == symbols[1][counter] && symbols[0][counter] == symbols[2][counter])
            return (symbols[0][counter] == player_one ? 2 : -2);

    // check the diagonal
    if (symbols[0][0] != ' ' && symbols[0][0] == symbols[1][1] && symbols[0][0] == symbols[2][2]) {
        return (symbols[0][0] == player_one ? 2 : -2);
    }
    if (symbols[0][2] != ' ' && symbols[0][2] == symbols[1][1] && symbols[0][2] == symbols[2][0]) {
        return (symbols[0][2] == player_one ? 2 : -2);
    }
    bool tie = true;
    for (int counter_1 = 0; counter_1 < 3; counter_1++)
        for (int counter_2 = 0; counter_2 < 3; counter_2++)
            if (symbols[counter_1][counter_2] == ' ')
                tie = false;
    if (tie)
        return 0;
    else
        return 1;
}


//----------------------AI algorithm function-------------------------------------

//8-------------------The easy level function-----------------------------------------------
void getRandomMove(char symbols[][3]) {
    // then if no blocking or winning ya hendo, we will generate a random value

    int availableMoves[9][2];  // 2D array of 9 elements

    for (int counter_1 = 0; counter_1 < 9; counter_1++)
        for (int counter_2 = 0; counter_2 < 2; counter_2++)
            availableMoves[counter_1][counter_2] = -1;  // Initialize with -1

    int moveCount = 0;

    for (int counter_1 = 0; counter_1 < 3; counter_1++)
    {
        for (int counter_2 = 0; counter_2 < 3; counter_2++)
        {
            if (symbols[counter_1][counter_2] == ' ')
            {
                availableMoves[moveCount][0] = counter_1;
                availableMoves[moveCount][1] = counter_2;
                moveCount++;
            }
        }
    }
    // notice that the condition below is to make sure that if moveCount = 0, then the function will return to avoid division by zero
    if (moveCount == 0) {
        return;
    }
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % moveCount; // this line of code can make some issues
    symbols[availableMoves[randomIndex][0]][availableMoves[randomIndex][1]] = 'O';
}



// 9------------The meduim level function----------------------------------------
void getComputerMove(char symbols[3][3]) {
    // here I will not ask to cin >> any thing, as computer will analyze the state of the game, and determine the suitable action
    int counter_1, counter_2;
    // check for winning move
    for (counter_1 = 0; counter_1 < 3; counter_1++) {
        for (counter_2 = 0; counter_2 < 3; counter_2++) {
            if (symbols[counter_1][counter_2] == ' ') {
                //char tempSymbol[3][3];
                //memcpy(tempSymbol, symbols, sizeof(symbols));
                symbols[counter_1][counter_2] = 'O';
                if (checkWin(symbols) == -2) {
                    symbols[counter_1][counter_2] = 'O';
                    //cout << "i'm from the 1st cond\n";
                    return;
                }
                else {
                    symbols[counter_1][counter_2] = ' ';
                }
            }
        }
    }
    // check for blocking move
    for (counter_1 = 0; counter_1 < 3; counter_1++) {
        for (counter_2 = 0; counter_2 < 3; counter_2++) {
            if (symbols[counter_1][counter_2] == ' ') {
                //char tempSymbol[3][3];
                //memcpy(tempSymbol, symbols, sizeof(symbols));
                symbols[counter_1][counter_2] = 'X';
                if (checkWin(symbols) == 2) {
                    symbols[counter_1][counter_2] = 'O';
                    //cout << "i'm from the 2nd cond\n";
                    return;
                }
                else {
                    symbols[counter_1][counter_2] = ' ';
                }
            }
        }
    }
    getRandomMove(symbols);
}

//10------The hard level function---------------------------------------
int miniMax(char symbols[][3], bool isMaximizing, bool firstTime) {
    int result = checkWin(symbols);
    if (result != 1) {
        return result;
    }
    if (isMaximizing) {
        int minusInfinity = -10;
        int rowIndex = 0;
        int colIndex = 0;
        for (int counter_1 = 0; counter_1 < 3; counter_1++) 
            for (int counter_2 = 0; counter_2 < 3; counter_2++) {
                if (symbols[counter_1][counter_2] == ' ') {
                    symbols[counter_1][counter_2] = 'X';
                    int tempScore = miniMax(symbols, false, false);
                    symbols[counter_1][counter_2] = ' ';
                    if (tempScore > minusInfinity) {
                        minusInfinity = tempScore;
                        rowIndex = counter_1;
                        colIndex = counter_2;
                    }
                }
            }
        if (firstTime) {
            symbols[rowIndex][colIndex] = 'O';
        }
        return minusInfinity;
    }
    else {
        int plusInfinity = 10;
        int rowIndex = 0;
        int colIndex = 0;
        for (int counter_1 = 0; counter_1 < 3; counter_1++)
            for (int counter_2 = 0; counter_2 < 3; counter_2++) {
                if (symbols[counter_1][counter_2] == ' ') {
                    symbols[counter_1][counter_2] = 'O';
                    int tempScore = miniMax(symbols, true, false);
                    symbols[counter_1][counter_2] = ' ';
                    if (tempScore < plusInfinity) {
                        plusInfinity = tempScore;
                        rowIndex = counter_1;
                        colIndex = counter_2;
                    }
                }
            }
        if (firstTime) {
            symbols[rowIndex][colIndex] = 'O';
        }
        return plusInfinity;
    }
}

//11-----------------function to play with AI
void play_with_AI(int &rowIndex, int &colIndex, int &result, char symbols[][3], int &gameLevel) {
    bool valid_place = true ;
    cout << "Choose the level, (1-Easy\t2-Immediate\t3-Impossible): ";
    cin >> gameLevel;

    if (gameLevel == 1) {
        cout << "You are playing at the easy level\n";
    } else if (gameLevel == 2) {
        cout << "You are playing at the medium level\n";
    } else if (gameLevel == 3) {
        cout << "You are playing at the hard level\n";
    } else {
        gameLevel = 1;
        cout << "Invalid level choice, defaulting to easy level\n";
    }
    while (true) {
         do
        {
        cout << "Enter the row number and the column number respectively\n";
        cin >> rowIndex >> colIndex;

        rowIndex--;
        colIndex--;
        if (((rowIndex<0) || (rowIndex>2) || (colIndex<0)  || (colIndex>2) ) || ((symbols[rowIndex][colIndex] == 'X') || (symbols[rowIndex][colIndex] == 'x') || (symbols[rowIndex][colIndex] == 'O') ) )
        {
            valid_place= false ;
            cout << "Please choose an empty place to place your symbol.\n";
        } 
        else 
        {
            valid_place = true;
        }
        } while (false == valid_place);

        symbols[rowIndex][colIndex] = 'X';
        if (exitGame(symbols))
            break;

        if (gameLevel == 1) {
            getRandomMove(symbols);
        } else if (gameLevel == 2) {
            getComputerMove(symbols);
        } else if (gameLevel == 3) {
            // apply minimax and get AI move
            int move = miniMax(symbols, false);
        }
        drawBoard(symbols);
        if (exitGame(symbols))
           break;
    }
}
//-----------------------------------------------------------------------------------------------
//12-------------------functio to Two players mode
void Two_players_mode(int &rowIndex, int &colIndex, int &result, char symbols[][3]) {
    char player_one, player_two;
    bool valid_place = true; // true for valid place and false for invalid place 

    // determine the players symbol
    get_two_player_symbols(player_one, player_two);
    do
    {
        do
        {
        cout << "Player 1, enter the row number and the column number respectively\n";
        cin >> rowIndex >> colIndex;
        rowIndex--;
        colIndex--;
        if (((rowIndex<0) || (rowIndex>2) || (colIndex<0)  || (colIndex>2) ) || ((symbols[rowIndex][colIndex] == 'X') || (symbols[rowIndex][colIndex] == 'x') || (symbols[rowIndex][colIndex] == 'O') ) )
        {
            valid_place= false ;
            cout << "Please choose an empty place to place your symbol.\n";
        } 
        else 
        {
            valid_place = true;
        }
        } while (false == valid_place);
        

        symbols[rowIndex][colIndex] = player_one;
        result= checkWin_Two_Players(symbols,player_one,player_two);
        drawBoard(symbols);

        if (result==2)
        {
            cout<<"Player_1 wins!";
            return;

        }
        else if (result==0)
        {
            cout<<"There is a draw";
            return;
        }


        do
        {
            cout << "Player 2, enter the row number and the column number respectively\n";
            cin >> rowIndex >> colIndex;
            rowIndex--;
            colIndex--;
            if (((rowIndex<0) || (rowIndex>2) || (colIndex<0)  || (colIndex>2) ) || ((symbols[rowIndex][colIndex] == 'X') || (symbols[rowIndex][colIndex] == 'x') || (symbols[rowIndex][colIndex] == 'O') ))
            {
                valid_place= false ;
                cout << "Please choose an empty place to place your symbol.\n";
            } 
            else 
            {
                valid_place = true;
            }

        } while (false == valid_place);
        
        symbols[rowIndex][colIndex] = player_two;
        result= checkWin_Two_Players(symbols,player_one,player_two);
        drawBoard(symbols);
        if (result==-2)
        {
            cout<<"Player_2 wins!";
            return;
        }
        else if (result==0)
        {
            cout<<"There is a draw";
            return;
        }
    } while (result==1);
    
}

//13-----------------Function of the game--------------------------------
void playGame() {
    int result = 1;
    int rowIndex = 0;
    int colIndex = 0;
    int gameLevel = 0;
    char symbols[3][3];
    initArray(symbols);
    drawBoard(symbols);
     if (choose_play_mode())
    {
        play_with_AI(rowIndex,colIndex,result,symbols,gameLevel);
    }
    else
    {
        Two_players_mode(rowIndex,colIndex,result,symbols);
    }
}

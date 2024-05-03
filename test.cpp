// this is the last modification in the code from demo

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

// here we will start with the common functions between the three levels

// function to draw the board
void drawBoard(const char symbols[3][3]) {
    cout << "\t\t\t\t\t\t" << " " << symbols[0][0] << " | " << symbols[0][1] << " | " << symbols[0][2] << endl;
    cout << "\t\t\t\t\t\t" << "-----------" << endl;
    cout << "\t\t\t\t\t\t" << " " << symbols[1][0] << " | " << symbols[1][1] << " | " << symbols[1][2] << endl;
    cout << "\t\t\t\t\t\t" << "-----------" << endl;
    cout << "\t\t\t\t\t\t" << " " << symbols[2][0] << " | " << symbols[2][1] << " | " << symbols[2][2] << endl;
    cout << "\n\n\n\n";
}
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

// function to initialize the array of symbols
void initArray(char symbols[][3]) {
    for (int counter_1 = 0; counter_1 < 3; counter_1++)
        for (int counter_2 = 0; counter_2 < 3; counter_2++)
            symbols[counter_1][counter_2] = ' ';
}

//------------------------------------------------------------------------------------
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



// function to get the computer's move
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
                    cout << "i'm from the 1st cond\n";
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
                    cout << "i'm from the 2nd cond\n";
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


int miniMax(char symbols[][3], bool isMaximizing, bool firstTime = true) {
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

// function to play the game
void playGame() {
    int result = 1;
    int rowIndex = 0;
    int colIndex = 0;
    int gameLevel = 0;
    char symbols[3][3];

    // get the game level
    cout << "Choose the level, (1-Easy\t2-Immediate\t3-Impossible): ";
    cin >> gameLevel;

    initArray(symbols);
    drawBoard(symbols);
    while (true) {
        cout << "Enter the row, then enter the column: ";
        cin >> rowIndex >> colIndex;
        symbols[rowIndex][colIndex] = 'X';
        if (gameLevel == 1) {
            getRandomMove(symbols);
        }
        else if (gameLevel == 2) {
            getComputerMove(symbols);
        }
        else {
            // apply minimax and get AI move
            int move = miniMax(symbols, false);
        }
        drawBoard(symbols);
        int result = checkWin(symbols);

        if (result == 2) {
            cout << "Congratulation! You win.\n";
            break;
        }
        if (result == -2) {
            cout << "Sorry! You loss.\n";
            break;
        }
        if (result == 0) {
            cout << "No winner, it is a tie.\n";
            break;
        }

    }
}

int main() {
    cout << "Hello to tic tac toe game!\n";
    cout << "--------------------------\n";
    playGame();
    return 0;
}

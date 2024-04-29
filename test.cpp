//-------------------- file is from ElDemairy, AI task >> to Elsheikh abohendy------------------------------------
// here, symbol is the main array I used to contain X-O

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

struct player {
    char playerSymbol;
    bool whoStart;
}player_1, player_2, AI;

// this function is needed to draw the grid contained the state of the game.
void drawBoard(const char symbols[][3]) {
    cout << "\t\t\t\t\t\t" << " " << symbols[0][0] << " | " << symbols[0][1] << " | " << symbols[0][2] << endl;
    cout << "\t\t\t\t\t\t" << "-----------" << endl;
    cout << "\t\t\t\t\t\t" << " " << symbols[1][0] << " | " << symbols[1][1] << " | " << symbols[1][2] << endl;
    cout << "\t\t\t\t\t\t" << "-----------" << endl;
    cout << "\t\t\t\t\t\t" << " " << symbols[2][0] << " | " << symbols[2][1] << " | " << symbols[2][2] << endl;
    cout << "\n\n\n\n";
}

// function to determine the symbol you want to play with
void chooseSymbol() {
    char symbol;
    cout << "Determine the symbol you want to play with: ";
    cin >> symbol;
    cin.ignore();
    if (symbol == 'x' || symbol == 'X') {
        player_1.playerSymbol = 'X';
        AI.playerSymbol = 'O';
        player_2.playerSymbol= 'O';
    }
    else {// You didn't make the case that the user enter a strange letter beca
        player_1.playerSymbol = 'O';
        AI.playerSymbol = 'X';
        player_2.playerSymbol= 'X';
    }
    cout << "\n\n\n";
}

int getSizeOfSymbols(const char symbols[][3]) {
    int counter = 0;
    for (int counter_1 = 0; counter_1 < 3; counter_1++)
        for (int counter_2 = 0; counter_2 < 3; counter_2++)
            if (symbols[counter_1][counter_2] != ' ')
                counter++;
    return counter;
}

// this function is to check if one of the two opponents has won.
bool checkWin(const char symbols[][3], char playerSymbol) {
    // check the rows
    for (int counter = 0; counter < 3; counter++) 
        if (symbols[counter][0] == playerSymbol && symbols[counter][1] == playerSymbol && symbols[counter][2] == playerSymbol)
            return true;

    // check the columns
    for (int counter = 0; counter < 3; counter++)
        if (symbols[0][counter] == playerSymbol && symbols[1][counter] == playerSymbol && symbols[2][counter] == playerSymbol)
            return true;
    
    // check the diagonal
    if (symbols[0][0] == playerSymbol && symbols[1][1] == playerSymbol && symbols[2][2] == playerSymbol) {
        return true;
    }
    if (symbols[0][2] == playerSymbol && symbols[1][1] == playerSymbol && symbols[2][0] == playerSymbol) {
        return true;
    }
    return false;
}


// function to get the player's move

int* getPlayerMove() {
    int* ptr = new int[2]; // this variable is dealed as an array, that will contain the index of the array symbols, and its length will be 2
    cout << "Please, enter the index of the move: (1:3 | 1:3): ";
    cin >> ptr[0] >> ptr[1];

    // here I can make an if condition to check if the index is within the range, but u know we are deal with GUI >> to hendo
    return ptr;
}

// function to get the computer's move
int* getComputerMove(const char symbols[][3]) {
    // here I will not ask to cin >> any thing, as computer will analyze the state of the game, and determine the suitable action
    int counter_1, counter_2;
    int* ptr = new int[2]; // it is like the pointer in getPlayerMove function
    // check for winning move
    for (counter_1 = 0; counter_1 < 3; counter_1++)
        for (counter_2 = 0; counter_2 < 3; counter_2++)
            if (symbols[counter_1][counter_2] == ' ') {
                char tempSymbol[3][3];
                memcpy(tempSymbol, symbols, sizeof(symbols));
                tempSymbol[counter_1][counter_2] = AI.playerSymbol;
                if (checkWin(tempSymbol, AI.playerSymbol)) {
                    ptr[0] = counter_1;
                    ptr[1] = counter_2;
                    return ptr;
                }
            }

    // check for blocking move
    for (counter_1 = 0; counter_1 < 3; counter_1++)
        for (counter_2 = 0; counter_2 < 3; counter_2++)
            if (symbols[counter_1][counter_2] == ' ') {
                char tempSymbol[3][3];
                memcpy(tempSymbol, symbols, sizeof(symbols));
                tempSymbol[counter_1][counter_2] = player_1.playerSymbol;
                if (checkWin(tempSymbol, player_1.playerSymbol)) {
                    ptr[0] = counter_1;
                    ptr[1] = counter_2;
                    return ptr;
                }
            }

    // then if no blocking or winning ya hendo, we will generate a random value

    int* availableMoves[9];  // Array of 9 pointers

    for (int counter_1 = 0; counter_1 < 9; counter_1++)
        availableMoves[counter_1] = new int[2];

    for (counter_1 = 0; counter_1 < 3; counter_1++)
        for (counter_2 = 0; counter_2 < 3; counter_2++)
            if (symbols[counter_1][counter_2] == ' ') {
                availableMoves[counter_1 * 3 + counter_2][0] = counter_1;
                availableMoves[counter_1 * 3 + counter_2][1] = counter_2;
            }

    srand(time(0));  
    int randomIndex = rand() % (sizeof(availableMoves) / sizeof(availableMoves[0]));
    return availableMoves[randomIndex];
}

void initialize_grid(char symbols[][3]) {
    for (int counter_1 = 0; counter_1 < 3; counter_1++)
        for (int counter_2 = 0; counter_2 < 3; counter_2++)
            symbols[counter_1][counter_2] = ' ';
}

void playGame() {
    char symbols[3][3];
    bool playerTurn = true;
    char playAgain;
    initialize_grid(symbols);
    chooseSymbol();
    drawBoard(symbols);
    while (true) {
        if (playerTurn) {
            int* move = getPlayerMove();
            symbols[move[0] - 1][move[1] - 1] = player_1.playerSymbol;
            drawBoard(symbols);
            if (checkWin(symbols, player_1.playerSymbol)) {
                cout << "You won!, congratulations :)\nwant to play again? (Y/N): ";
                cin >> playAgain;
                cin.ignore();
                if (playAgain == 'n' || playAgain == 'N')
                    break;
                else {
                    initialize_grid(symbols);
                    drawBoard(symbols);
                    continue;
                }
            }
        }
        else {
            int* move = getComputerMove(symbols);
            symbols[move[0]][move[1]] = AI.playerSymbol;///////////////
            drawBoard(symbols);
            if (checkWin(symbols, AI.playerSymbol)) {
                cout << "You lost! sorry :(\nwant to play again? (Y/N): ";
                cin >> playAgain;
                cin.ignore();
                if (playAgain == 'n' || playAgain == 'N')
                    break;
                else {
                    initialize_grid(symbols);
                    drawBoard(symbols);
                    continue;
                }
            }
        }
        if (getSizeOfSymbols(symbols) == 9) {
            cout << "It is a tie.\nwant to play again? (Y/N): ";
            cin >> playAgain;
            cin.ignore();
            if (playAgain == 'n' || playAgain == 'N')
                break;
            else {
                initialize_grid(symbols);
                drawBoard(symbols);
                continue;
            }
        }
        playerTurn = !playerTurn;
    }
}


int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "=======================" << endl << endl;

    playGame();

    return 0;
}


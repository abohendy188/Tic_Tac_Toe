//-------------------- file is from ElDemairy, AI task >> to Elsheikh abohendy------------------------------------
// here, symbol is the main array I used to contain X-O

#include <iostream>
using namespace std;
// function to draw the board
void drawBoard(const char symbols[3][3]) {
    cout << "\t\t\t\t\t\t" << " " << symbols[0][0] << " | " << symbols[0][1] << " | " << symbols[0][2] << endl;
    cout << "\t\t\t\t\t\t" << "-----------" << endl;
    cout << "\t\t\t\t\t\t" << " " << symbols[1][0] << " | " << symbols[1][1] << " | " << symbols[1][2] << endl;
    cout << "\t\t\t\t\t\t" << "-----------" << endl;
    cout << "\t\t\t\t\t\t" << " " << symbols[2][0] << " | " << symbols[2][1] << " | " << symbols[2][2] << endl;
    cout << "\n\n\n\n";
}
<<<<<<< HEAD

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
    else {//@Demo You didn't make the case that the user enter a strange letter because you
    // assume that this code will be on gui and it is only x and o in gui??
    //Okay, you meant that. I just didn't read the comment below.
        player_1.playerSymbol = 'O';
        AI.playerSymbol = 'X';
        player_2.playerSymbol= 'X';
    }
    cout << "\n\n\n";
}

void mode (int &mode_factor)  // mode_factor is detected upon the user choice to play 2-players mode 
//or play computer mode
{
cout <<"What mode you want to play?"<<endl<<"1- Two players mode"<<endl<<"2- Play with the computer";
cin>>mode_factor;
if(mode_factor==1)
{
    play_game_2_players();
    else
    {
        play_game_AI();
    }
}
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
=======
int checkWin(const char symbols[][3]) {
>>>>>>> 088ec6e07f8aa7f39df76a3fd0876b73cf693736
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
<<<<<<< HEAD


// function to get the player's move

int* getPlayerMove() {
    int* ptr = new int[2]; // this variable is dealed as an array, that will contain the index of the array symbols,
    // and its length will be 2
    cout << "Please, enter the index of the move: (1:3 | 1:3): ";
    cin >> ptr[0] >> ptr[1];

    // here I can make an if condition to check if the index is within the range, 
    //but u know we are deal with GUI >> to hendo
    return ptr;
}

// function to get the computer's move
int* getComputerMove(const char symbols[][3]) {
    // here I will not ask to cin >> any thing, as computer will analyze the state of the game, 
    //and determine the suitable action
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
=======
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
>>>>>>> 088ec6e07f8aa7f39df76a3fd0876b73cf693736
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
// function to initialize the array of symbols
void initArray(char symbols[][3]) {
    for (int counter_1 = 0; counter_1 < 3; counter_1++)
        for (int counter_2 = 0; counter_2 < 3; counter_2++)
            symbols[counter_1][counter_2] = ' ';
}
<<<<<<< HEAD

void play_game_2_players()
{

}

void play_game_AI()
{

}


=======
// function to play the game
>>>>>>> 088ec6e07f8aa7f39df76a3fd0876b73cf693736
void playGame() {
    int result = 1;
    int rowIndex = 0;
    int colIndex = 0;
    char symbols[3][3];
<<<<<<< HEAD
    bool playerTurn = true;
    char playAgain;
    int mode_factor;
    initialize_grid(symbols);
    chooseSymbol();
=======
    initArray(symbols);
>>>>>>> 088ec6e07f8aa7f39df76a3fd0876b73cf693736
    drawBoard(symbols);
    mode(mode_factor);// This function should have the effect of branching to one of the modes,
    // and We should define one function for playing every mode 


//All written below should be transformed to the function of AI
    while (true) {
        // get player move
        cout << "Enter the row, then enter the column: ";
        cin >> rowIndex >> colIndex;
        symbols[rowIndex][colIndex] = 'X';
        cout << "row: " << rowIndex << " col: " << colIndex << " symbol: " << symbols[rowIndex][colIndex] << endl;
        // apply minimax and get AI move
        int move = miniMax(symbols, false);
        drawBoard(symbols);
        result = checkWin(symbols);
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


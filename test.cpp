//Alsalam Alykom!
// for more information and notes please go to the readme file!

#include <iostream>
using namespace std;


//----------------Functions----------------------------------------------------------


// 1------- function to initialize the array of symbols by space character(as a sign for being empty).
void initArray(char symbols[][3]) {
    for (int counter_1 = 0; counter_1 < 3; counter_1++)
        for (int counter_2 = 0; counter_2 < 3; counter_2++)
            symbols[counter_1][counter_2] = ' ';
}


// 2-----function to draw the board
void drawBoard(const char symbols[3][3])
 {
    cout << "\t\t\t\t\t\t" << " " << symbols[0][0] << " | " << symbols[0][1] << " | " << symbols[0][2] << endl;
    cout << "\t\t\t\t\t\t" << "-----------" << endl;
    cout << "\t\t\t\t\t\t" << " " << symbols[1][0] << " | " << symbols[1][1] << " | " << symbols[1][2] << endl;
    cout << "\t\t\t\t\t\t" << "-----------" << endl;
    cout << "\t\t\t\t\t\t" << " " << symbols[2][0] << " | " << symbols[2][1] << " | " << symbols[2][2] << endl;
    cout << "\n\n\n\n";
}

//3-------function to choose the playmode 
int choose_play_mode()
{
    int mode;
    cout<<"What mode you want to play?"<<endl<<"Enter:\n0 for two players mode\n1 to play with the computer\n";
    cin>>mode;
    return mode;
}

//4------function to get the player symbol for two players mode
void get_two_player_symbols(char &player_one,char &player_two)
{
    cout<<"Player 1 should choose what symbol to play with!\n";
    cin>>player_one;
    cin.ignore();
    if (player_one=='X' |'x')
    {
        player_two='O';
    }
    else
    {
        player_two='X';
    }
}

//5------Function to check the win
int checkWin(const char symbols[][3]) 
{
    // check the rows
    for (int counter = 0; counter < 3; counter++)
        if (symbols[counter][0] != ' ' && symbols[counter][0] == symbols[counter][1] && symbols[counter][0] == symbols[counter][2])
            return (symbols[counter][0] == 'X' ? 2 : -2);

    // check the columns
    for (int counter = 0; counter < 3; counter++)
        if (symbols[0][counter] != ' ' && symbols[0][counter] == symbols[1][counter] && symbols[0][counter] == symbols[2][counter])
            return (symbols[0][counter] == 'X' ? 2 : -2);

    // check the diagonal
    if (symbols[0][0] != ' ' && symbols[0][0] == symbols[1][1] && symbols[0][0] == symbols[2][2])
    {
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

//----------------------AI algorithm function-------------------------------------

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


//5-------------------functio to Two players mode
void Two_players_mode(int &rowIndex,int &colIndex,int &result, char symbols[][3])
{
    // determine the players symbol

    char player_one,player_two;
    get_two_player_symbols(player_one,player_two);
    cout << "Player 1, Enter the row, then enter the column! ";
        cin >> rowIndex >> colIndex;
        symbols[rowIndex][colIndex] = player_one;
        



    
}

//function to play with AI

void play_with_AI(int &rowIndex,int &colIndex,int &result, char symbols[][3])
{
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


//-----------------------------------------------------------------------------------------------


//-----------------Function of the game--------------------------------


void playGame() {
    int result = 1;
    int rowIndex = 0;
    int colIndex = 0;
    char symbols[3][3];
    initArray(symbols);
    drawBoard(symbols);
    if (choose_play_mode())
    {
        play_with_AI(rowIndex,colIndex,result,symbols);
    }
    else
    {
        Two_players_mode(rowIndex,colIndex,result,symbols);
    }
   
   
}



//------------------The main function--------------------

int main() {
    cout << "Hello to tic tac toe game!\n";
    cout << "--------------------------\n";
    playGame();
    return 0;
}


// tic_tac_toe.h

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H



int calculateEmptyCount(const char symbols[3][3]);
void initArray(char symbols[][3]);
void drawBoard(const char symbols[3][3]);
int choose_play_mode();
void get_two_player_symbols(char &player_one, char &player_two);
int checkWin(const char symbols[][3]);
bool exitGame(const char symbols[][3]);
int checkWin_Two_Players(const char symbols[][3], char player_one, char player_two);
void getRandomMove(char symbols[][3]);
void getComputerMove(char symbols[3][3]);
int miniMax(char symbols[][3], bool isMaximizing, bool firstTime = true);
void play_with_AI(int &rowIndex, int &colIndex, int &result, char symbols[][3], int &gameLevel);
void Two_players_mode(int &rowIndex, int &colIndex, int &result, char symbols[][3]);
void playGame();

#endif // TIC_TAC_TOE_H

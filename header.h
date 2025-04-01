#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
#endif

#define MAX 4
#define TRUE 1
#define FALSE 0

typedef int Matrix[MAX][MAX];

struct boardTag
{
    Matrix Uno; // matrix for player Uno
    Matrix Dos; // matrix for player Dos
    Matrix Tres; // matrix for player Tres
    Matrix F; // matrix for occupied and unoccupied spaces
};

typedef struct boardTag boardType; // sets alias for struct boardTag

struct comboTag
{
    Matrix W;
    int rowsW;
};

typedef struct comboTag comboType; // sets alias for struct comboTag

void clrscr();
void initializeMatrix();
void defineP();
void defineW();
int isValidInput();
int Search();
int checkCombo();

void startMenu();
void howToMenu();
void comboListMenu();
void changeCharacter();
void enterCharacter();
void setGameMode();
void setSuccess();
void creditsMenu();
void exitMenu();

void printBoard();
void playerName();
void randPlayer();
void getPositions();
int NextPlayerMove();
void GameOver();
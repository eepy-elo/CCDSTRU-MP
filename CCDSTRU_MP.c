/**************************************************************************

This is to certify that this project is my own work, based on my personal efforts in studying
and applying the concepts learned. I have constructed the functions and their respective algorithms
and corresponding code by myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise plagiarized the work of other
students and/or persons.

    Jessica Mae G. Dela Cruz    12410268
    Shielo Heart D. Lunario     12413070
    Marc Alexis E. De Roca      12410535

***************************************************************************/

/*
 Description: The program simulates a game of modifed 4x4 tic-tac-toe that has a z-pattern winning
              combination. Player Uno and Tres have to create this pattern in order to win while Dos
              has to ensure they do not. If the board fills up before they create a pattern, they lose.
              
              It can be played either by: a) two players: player Dos' moves are randomly
              generated or b) three players. 

 Programmed by: Jessica Mae G. Dela Cruz
                Shielo Heart D. Lunario
                Marc Alexis E. De Roca

 Last modified: March 31, 2025

 Version: V3

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 4
#define TRUE 1
#define FALSE 0

typedef int Array2D[MAX][MAX];

void clrscr();
void initializeArray();
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
void getCoordinates();
int NextPlayerMove();
void GameOver();

/*
    Purpose: This function clears the screen
    Returns: void
*/
void
clrscr()
{
    system("@cls||clear");
}

/*
    Purpose: This function sets the value of each 2d array element to a number.
    Returns: void
    @param : arr is the 2d array to be initialized
    @param : num is the number the array is initialized to
    Pre-condition: number of elements in arr match MAX
*/
void
initializeArray(Array2D arr, int num)
{
    int i, j;

    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            arr[i][j] = num; // sets array element to num
}

/*
    Purpose: This function checks the validity of an integer input.
    Returns: 1 if the input is between 1 and 4 inclusive,
                 otherwise it returns 0
    @param : input is the integer to be evaluated
    Pre-condition: argument passed to function must be of type int
*/
int
isValidInput(int input)
{
    if (input >= 1 && input <= 4)
        return 1;
    else
        return 0;
}

/*
    Purpose: This function uses linear search to search for a key in an array.
    Returns: either (a) index of found key or (b) -1 to signify key is not found
    @param : key is the number to be searched for
    @param : *arr is the array to be searched
    @param : size is the number of elements to be searched
    Pre-condition: arguments passed to function are of proper type
*/
int
Search(int key, int *arr, int size)
{
    int i, found;
    found = -1;

    for (i = 0; i < size; i++)
        if (arr[i] == key)
            found = i; // sets found to found index

    return found;
}

/*
    Purpose: This function takes a 2D array and checks if it contains the winning combinations in W.
             If an index in the 2D array contains 1, it stores the row and column indices in array temp
             as a 2-digit integer. Example: arr[1][2] => 12
    Returns: either (a) 1 if all elements of a row in W is found in the 2D array (b) else 0
    @param : arr is the array to be checked for combos
    Pre-condition: number of elements in arr match MAX
*/
int
checkCombo(Array2D arr)
{
    int W[3][4] = {{11, 12, 13, 14},
                   {14, 23, 32, 41},
                   {41, 42, 43, 44}}; // winning combinations
    int temp[16] = {0};
    int ctr = 0, i, j, k = 0;

    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            if (arr[i][j] == 1)
            {
                temp[k] = (i + 1) * 10 + (j + 1); // converts (x, y) to a 2-digit integer
                k++;
            }

    for (i = 0; i < 3 && ctr < 4; i++)
    {
        ctr = 0;
        for (j = 0; j < MAX; j++)
            if (Search(W[i][j], temp, k) >= 0)
                ctr++; // adds to ctr if there is part of winning combo
    }

    if (ctr == 4)
        return 1; // there is a winning combo
    else
        return 0; // no winning combo
}

/*
    Purpose: This function prints the start menu
    Returns: void
    @param : playerChars[] stores the characters of player Uno and Tres
    @param : playerMode stores the player mode a) 0 for three players and b) 1 for two players
    Pre-condition: arguments passed to function are of proper type
*/
void
startMenu(char playerChars[], int *playerMode)
{
    int next;

    do
    {
        clrscr();
        printf("\a");
        printf("╔═══════════════════════════════════════════╗\n");
        printf("║              .·:*¨ ༺ ༻  ¨*:·.             ║\n");
        printf("║          \033[1m\033[31mWELCOME TO THE 4X4 GAME!\033[0m         ║\n");
        printf("╚═══════════════════════════════════════════╝\n");
        printf("║                                           ║\n");
        printf("║   [1] How to play?                        ║\n");
        printf("║   [2] Change Character                    ║\n");
        printf("║   [3] Set Game Mode                       ║\n");
        printf("║   [4] Credits                             ║\n");
        printf("║   [5] Exit Game                           ║\n");
        printf("║ 𓅭                                         ║\n");
        printf("╔═══════════════════════════════════════════╗\n");
        printf("║       \033[5mEnter '6' to start the game...\033[0m      ║\n");
        printf("╚═══════════════════════════════════════════╝\n");

        while (scanf("%d", &next) != 1 || (next != 1 && next != 2 &&
                                           next != 3 && next != 4 && next != 5 && next != 6)) // repeats asking input while invalid
        {
            printf("Invalid input, try again\n");
            while (getchar() != '\n'); // clears buffer
        }
        switch (next)
        {
        case 1:
            howToMenu();
            break; // goes to how to menu
        case 2:
            changeCharacter(playerChars, playerMode);
            break; // goes to change character menu
        case 3:
            setGameMode(playerChars, playerMode);
            break; // goes to game mode menu
        case 4:
            creditsMenu();
            break; // goes to credit menu
        case 5:
            exitMenu();
            break; // exits the game
        }
    } while (next != 6); // ends menu
}

/*
    Purpose: This function prints the how to menu containing the rules
    Returns: void
*/
void
howToMenu()
{
    int next;

    clrscr();
    printf("\a");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              .·:*¨ ༺ ༻  ¨*:·.             ║\n");
    printf("║                   \033[1m\033[31mRULES\033[0m                   ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("║                                           ║\n");
    printf("║   1. Player Uno and Tres can occupy an    ║\n");
    printf("║      unoccupied position.                 ║\n");
    printf("║   2. Player Dos can unoccupy a position   ║\n");
    printf("║      occupied by Uno or Tres.             ║\n");
    printf("║   3. The game ends when a player obtains  ║\n");
    printf("║      a winning combination or all         ║\n");
    printf("║      positions are occupied.              ║\n");
    printf("║   4. A winning combination is any line    ║\n");
    printf("║      in the Z-pattern as specified in     ║\n");
    printf("║      the winning combos [1].              ║\n");
    printf("║   5. If in two-player mode, Dos' moves    ║\n");
    printf("║      are randomized.                      ║\n");
    printf("║                                           ║\n");
    printf("║                                           ║\n");
    printf("║ 𓅭                  See Winning Combos [1] ║\n");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║       \033[5mEnter '0' to return to menu..\033[0m       ║\n");
    printf("╚═══════════════════════════════════════════╝\n");

    while (scanf("%d", &next) != 1 || (next != 0 && next != 1)) // repeats asking input while invalid
    {
        printf("Invalid input, try again\n");
        while (getchar() != '\n'); // clears buffer
    }

    if (next == 1)
    {
        comboListMenu(); // goes to winning combos
    }
    else
        return; // returns to start menu
}

/*
    Purpose: This function prints the possible combinations player Uno and Tres can make to win
    Pre-condition: arguments passed to function are of proper type
*/
void
comboListMenu()
{
    int next;

    clrscr();
    printf("\a");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              .·:*¨ ༺ ༻  ¨*:·.             ║\n");
    printf("║             \033[1m\033[31mCOMBINATIONS LIST\033[0m             ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("║                                           ║\n");
    printf("║       1. (1,1), (1,2), (1,3), (1,4)       ║\n");
    printf("║       2. (1,4), (2,3), (3,2), (4,1)       ║\n");
    printf("║       3. (4,1), (4,2), (4,3), (4,4)       ║\n");
    printf("║                                           ║\n");
    printf("║                                           ║\n");
    printf("║ 𓅭                    Go Back to Rules [1] ║\n");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║       \033[5mEnter '0' to return to menu..\033[0m       ║\n");
    printf("╚═══════════════════════════════════════════╝\n");

    while (scanf("%d", &next) != 1 || (next != 0 && next != 1)) // repeats asking input while invalid
    {
        printf("Invalid input, try again\n");
        while (getchar() != '\n'); // clears buffer
    }

    if (next == 1)
    {
        howToMenu(); // returns to how to menu
    }
    else
        return; // returns to start menu
}

/*
    Purpose: This function prints the change character menu and changes the players'
             characters accordingly
    Returns: void
    @param : playerChars[] stores the characters of player Uno and Tres
    @param : playerMode stores the player mode a) 0 for three players and b) 1 for two players
    Pre-condition: arguments passed to function are of proper type
*/
void
changeCharacter(char playerChars[], int *playerMode)
{
    int next;

    clrscr();
    printf("\a");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              .·:*¨ ༺ ༻  ¨*:·.             ║\n");
    printf("║              \033[1m\033[31mCHANGE CHARACTER\033[0m             ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("║                                           ║\n");
    printf("║                CURRENT THEME              ║\n");
    printf("║                   \033[1m%c\033[0m and \033[1m%c\033[0m                 ║\n",
                                        playerChars[0], playerChars[1]);
    printf("║                                           ║\n"); // prints current player characters
    printf("║-------------------------------------------║\n");
    printf("║                                           ║\n");
    printf("║                  SET THEME                ║\n");
    printf("║      [1] X's and O's                      ║\n");
    printf("║      [2] @'s and *'s                      ║\n");
    printf("║      [3] 1's and 3's                      ║\n");
    printf("║      [4] Custom                           ║\n");
    printf("║                                           ║\n");
    printf("║ 𓅭                                         ║\n");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║       \033[5mEnter '0' to return to menu..\033[0m       ║\n");
    printf("╚═══════════════════════════════════════════╝\n");

    while (scanf("%d", &next) != 1 || (next != 0 && next != 1 && next != 2 &&
                                       next != 3 && next != 4)) // repeats asking input while invalid
    {
        printf("Invalid input, try again\n");
        while (getchar() != '\n'); // clears buffer
    }

    switch (next)
    { // changes the players' characters according to what they chose
    case 1:
        playerChars[0] = 'X';
        playerChars[1] = 'O';
        setSuccess(playerChars, playerMode, 0);
        break;
    case 2:
        playerChars[0] = '@';
        playerChars[1] = '*';
        setSuccess(playerChars, playerMode, 0);
        break;
    case 3:
        playerChars[0] = '1';
        playerChars[1] = '3';
        setSuccess(playerChars, playerMode, 0);
        break;
    case 4:
        enterCharacter(playerChars, playerMode);
        break; // goes to enter character menu
    }

    return; // returns to start menu
}

/*
    Purpose: This function prints the enter character menu and asks the user to input the
             player characters for Uno and Tres
    Returns: void
    @param : playerChars[] stores the characters of player Uno and Tres
    @param : playerMode stores the player mode a) 0 for three players and b) 1 for two players
    Pre-condition: arguments passed to function are of proper type
*/
void
enterCharacter(char playerChars[], int *playerMode)
{
    int ctr = 0, valid;
    char next[3], playerNames[2][5] = {"UNO ", "TRES"}; // sets player names for display

    do
    {
        clrscr();
        printf("\a");
        valid = 0;

        printf("╔═══════════════════════════════════════════╗\n");
        printf("║              .·:*¨ ༺ ༻  ¨*:·.             ║\n");
        printf("║               \033[1m\033[31mENTER CHARACTER\033[0m             ║\n");
        printf("╚═══════════════════════════════════════════╝\n");
        printf("║                                           ║\n");
        printf("║            ENTER CHARACTER FOR            ║\n");
        printf("║                PLAYER %s                ║\n", playerNames[ctr]); // displays player name
        printf("║                                           ║\n");
        printf("║ 𓅭                                         ║\n");
        printf("╔═══════════════════════════════════════════╗\n");
        printf("║           \033[5mEnter '0' to cancel..\033[0m           ║\n");
        printf("╚═══════════════════════════════════════════╝\n");

        do
        {
            if (scanf(" %2s", next) == 1) // scans entered characters
            {
                if (next[1] != '\0') // if input is more than one character
                {   
                    printf("Invalid input, try again\n");
                    valid = 0; // ensures valid is still 0
                } else if (next[0] == '0')
                    return; // returns to start menu
                else 
                {
                    playerChars[ctr] = next[0]; // sets the character to input

                    valid = 1; // mark input as valid
                    ctr++;     // changes player to enter character for
                }
            }
            else
            {
                printf("Invalid input, try again\n");
                valid = 0; // ensures valid is still 0
            }

            while (getchar() != '\n'); // clear buffer

        } while (!valid); // repeats asking input while invalid

    } while (ctr < 2); // repeats while not all players have assigned character

    setSuccess(playerChars, playerMode, 0); // goes to set success screen
}

/*
    Purpose: This function prints the game mode menu and sets the game mode based on user input
    Returns: void
    @param : playerChars[] stores the characters of player Uno and Tres
    @param : playerMode stores the player mode a) 0 for three players and b) 1 for two players
    Pre-condition: arguments passed to function are of proper type
*/
void
setGameMode(char playerChars[], int *playerMode)
{
    int next;

    clrscr();
    printf("\a");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              .·:*¨ ༺ ༻  ¨*:·.             ║\n");
    printf("║                 \033[1m\033[31mGAME MODE\033[0m                 ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("║                                           ║\n");
    printf("║             CURRENT GAME MODE             ║\n");
    if (*playerMode == 1) // "TWO"
        printf("║              \033[1mTWO\033[0m-PLAYER MODE              ║\n");
    else // "THREE"
        printf("║             \033[1mTHREE\033[0m-PLAYER MODE             ║\n");
    printf("║                                           ║\n");
    printf("║-------------------------------------------║\n");
    printf("║                                           ║\n");
    printf("║                  GAME MODES               ║\n");
    printf("║      [2] Two Player Mode                  ║\n");
    printf("║      [3] Three Player Mode                ║\n");
    printf("║                                           ║\n");
    printf("║ 𓅭                                         ║\n");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║       \033[5mEnter '0' to return to menu..\033[0m       ║\n");
    printf("╚═══════════════════════════════════════════╝\n");

    while (scanf("%d", &next) != 1 || (next != 0 && next != 2 && next != 3)) // repeats asking input while invalid
    {
        printf("Invalid input, try again\n");
        while (getchar() != '\n'); // clears buffer
    }

    if (next == 0)
        return; // returns to start menu
    else
    {
        *playerMode = !(next % 2);              // 2 = 1 (two-player), 3 = 0 (three-player)
        setSuccess(playerChars, playerMode, 1); // goes to set success screen
    }
}

/*
    Purpose: This function prints the success menu indicating a setting was successfully set
    Returns: void
    @param : playerChars[] stores the characters of player Uno and Tres
    @param : playerMode stores the player mode a) 0 for three players and b) 1 for two players
    @param : menu indicates which menu to return to
    Pre-condition: arguments passed to function are of proper type
*/
void
setSuccess(char playerChars[], int *playerMode, int menu)
{
    int next;

    clrscr();
    printf("\a");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              .·:*¨ ༺ ༻  ¨*:·.             ║\n");
    printf("║                   \033[1m\033[31mSTATUS\033[0m                  ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("║                                           ║\n");
    printf("║            ^ SET SUCCESSFULLY ^           ║\n");
    printf("║                                           ║\n");
    printf("║                                           ║\n");
    printf("║ 𓅭                             [1] Go Back ║\n");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║       \033[5mEnter '0' to return to menu..\033[0m       ║\n");
    printf("╚═══════════════════════════════════════════╝\n");

    while (scanf("%d", &next) != 1 || (next != 0 && next != 1)) // repeats asking input while invalid
    {
        printf("Invalid input, try again\n");
        while (getchar() != '\n'); // clears buffer
    }

    if (next == 1)
    {
        if (menu == 0)
            changeCharacter(playerChars, playerMode); // goes back to change character menu
        else
            setGameMode(playerChars, playerMode); // goes back to game mode menu
    }
    else
        return; // returns to start menu
}

/*
    Purpose: This function prints the credits or the creators of this project
    Returns: void
*/
void
creditsMenu()
{
    int next;

    clrscr();
    printf("\a");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              .·:*¨ ༺ ༻  ¨*:·.             ║\n");
    printf("║                  \033[1m\033[31mCREDITS\033[0m                  ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    printf("║                                           ║\n");
    printf("║                Created by:                ║\n");
    printf("║        ^-^ Jessica Shielo Marc ^-^        ║\n");
    printf("║                                           ║\n");
    printf("║            Special Thanks to:             ║\n");
    printf("║              Ms. Jazzie Jao               ║\n");
    printf("║                                           ║\n");
    printf("║ 𓅭                                         ║\n");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║       \033[5mEnter '0' to return to menu..\033[0m       ║\n");
    printf("╚═══════════════════════════════════════════╝\n");

    while (scanf("%d", &next) != 1 || next != 0) // repeats asking input while invalid
    {
        printf("Invalid input, try again\n");
        while (getchar() != '\n'); // clears buffer
    }

    return; // returns to start menu
}

/*
    Purpose: This function prints the exit menu and exits the game
    Returns: void
*/
void
exitMenu()
{
    clrscr();
    printf("\a");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║              .·:*¨ ༺ ༻  ¨*:·.             ║\n");
    printf("║                                           ║\n");
    printf("║                                           ║\n");
    printf("║                                           ║\n");
    printf("║             THANKS FOR PLAYING!           ║\n");
    printf("║                                           ║\n");
    printf("║                                           ║\n");
    printf("║                                           ║\n");
    printf("║ 𓅭                                         ║\n");
    printf("╚═══════════════════════════════════════════╝\n");
    exit(0); // exits the game
}

/*
    Purpose: This function prints the contents of a 2D array in a 4x4 board.
             The first row and column should print numbers 1-4 as the column
             and row coordinates, respectively.
    Returns: void
    @param : arr1 is the 2d array of player Uno
    @param : arr2 is the 2d array of player Tres
    @param : playerChars[] stores the chosen/default characters of each player
    @param : state indicates if the owner of the occupied spaces are revealed (0 for not, 1 for yes)
    Pre-condition: arguments are initialized
*/
void
printBoard(Array2D arr1, Array2D arr2, char playerChars[], int state)
{
    int i, j;
    printf("\n     1   2   3   4\n");
    printf("   ┌───┬───┬───┬───┐\n");
    for (i = 0; i < MAX; i++)
    {
        printf(" %d |", i + 1);
        for (j = 0; j < MAX; j++)
        {
            switch (state)
            {
            case 0: // displays player Dos screen
                if (arr1[i][j] == 0 && arr2[i][j] == 0)
                    printf(" - |"); // unoccupied
                else
                    printf(" O |"); // occupied
                break;
            case 1:                  // displays player Uno and Tres screen
                if (arr1[i][j] == 1) // occupied by Uno
                    printf(" \033[33m%c\033[0m |", playerChars[0]);
                else if (arr2[i][j] == 1) // occupied by Tres
                    printf(" \033[35m%c\033[0m |", playerChars[1]);
                else
                    printf(" - |"); // unoccupied
                break;
            }
        }
        printf("\n");

        if (i < 3)
            printf("   ├───┼───┼───┼───┤\n");
    }
    printf("   └───┴───┴───┴───┘\n");
}

/*
    Purpose: This function accepts a number and prints its corresponding player name.
    Returns: void
    @param : num specifies which player's turn it is
    Pre-condition: num is either 0, 1, or 2
*/
void
playerName(int num)
{
    printf("\n");

    switch (num) // prints player header according to num
    {
    case 0:
        printf("\033[33m%17s\033[0m", "Player Uno");
        break;
    case 1:
        printf("\033[36m%17s\033[0m", "Player Dos");
        break;
    case 2:
        printf("\033[35m%17s\033[0m", "Player Tres");
        break;
    }
}

/*
    Purpose: randomizes the x and y coordinate move of the player Dos
    Returns: void
    @param : *x stores the x coordinate
    @param : *y stores the y coordinate
    @param : arr stores the occupied and unoccupied spaces
    Pre-condition: arguments passed to function are of proper type
*/
void
randPlayer(Array2D arr, int *x, int *y)
{
    do
    {
        *x = rand() % 4 + 1; // generates random number from 1-4
        *y = rand() % 4 + 1;

    } while (arr[*x - 1][*y - 1]); // repeats while x and y is unnocupied
}

/*
    Purpose: This function asks the user for coordinates x and y. If the input
             is invalid, an error message will be displayed until the user
             enters a valid input.
    Returns: void
    @param : *x stores the x coordinate
    @param : *y stores the y coordinate
    @param : F is the 2d array where the coordinates will be marked
    @param : player specifies whose turn it is
    Pre-condition: arguments passed to function are of proper type
*/
void
getCoordinates(int *x, int *y, Array2D F, int player)
{

    *x = 0; // initializes to zero
    *y = 0;

    do
    {
        // checks if *x and *y are between 1 and 4
        if (isValidInput(*x) && isValidInput(*y))
            if ((player == 1 && F[*x - 1][*y - 1]) || (player != 1 && !F[*x - 1][*y - 1]))
                printf("\nThis space cannot be selected. Please enter a different coordinate.");
        // informs user that player cannot occupy/unoccupy that space

        printf("\nEnter row: ");
        scanf("%d", x);
        while (getchar() != '\n'); // clears buffer
        while (!isValidInput(*x))
        {
            printf("Invalid input. Enter row: ");
            scanf("%d", x);
            while (getchar() != '\n');
        }

        printf("Enter column: ");
        scanf("%d", y);
        while (getchar() != '\n');
        while (!isValidInput(*y))
        {
            printf("Invalid input. Enter column: ");
            scanf("%d", y);
            while (getchar() != '\n');
        }
    } while ((player == 1 && F[*x - 1][*y - 1]) || (player != 1 && !F[*x - 1][*y - 1]));
    // repeats while no valid input has been made
}

/*
    Purpose: If the game is in three-player mode, this function starts the going through each
             player's turn (Uno, Dos, and Tres) and repeats it until a player wins according
             to either:
                (a) a winning combination is found or
                (b) all elements in the 2d matrix F are 0

             The player turn order starts with Uno, Dos, then Tres. Uno and Tres can occupy an
             an unoccupied position in board F by entering its row and column index. While Dos can
             unoccupy a position occupied by Tres or Uno in the same fashion.

             If the game is in two-player mode, this function works the same except player Dos' moves
             is random and not taken from user-input.

             An unoccupied position is marked as - while an occupied one is marked as the player's
             character or 'O'.

    Returns: 1 once the game is over
    @param : Uno stores the board of occupied/unoccupied spaces of player Uno
    @param : Dos stores the board of occupied/unoccupied spaces of player Dos
    @param : Tres stores the board of occupied/unoccupied spaces of player Tres
    @param : F is the 2d array where the coordinates will be marked
    @param : playerChars[] stores the chosen/default characters of each player
    @param : playerMode indicates if the game mode is two or three player
    Pre-condition: number of elements of the arrays match MAX
*/
int
NextPlayerMove(Array2D Uno, Array2D Dos, Array2D Tres, Array2D F, char playerChars[], int playerMode)
{
    int turn = TRUE, go = FALSE, over = FALSE; // initializes according to specs
    int totalF = 16, turnNumber = 0, player;
    int x, y; // coordinates

    while (!over) // repeats while no one wins
    {
        player = turnNumber % 3;
        if (!(playerMode == 1 && player == 1)) // default is three-player game mode
        {                                      // runs if three-player and/or if it is not player Dos' turn
            clrscr();
            playerName(player);

            printBoard(Uno, Tres, playerChars, player != 1);

            if (player == 2)
                printf("\n    \033[36mDos\033[0m removed \033[31m%d %d\033[0m\n", x, y);
            // prints what player Dos unoccupied

            getCoordinates(&x, &y, F, player);
        }
        else
            randPlayer(F, &x, &y); // two-player game mode

        if (turn)
        {
            if (!go && F[x - 1][y - 1]) // player Uno's turn
            {
                Uno[x - 1][y - 1] = 1;
                F[x - 1][y - 1] = 0;
                turn = !turn;
                go = !go;
                totalF--;
            }
            else if (go && F[x - 1][y - 1]) // player Tres' turn
            {
                Tres[x - 1][y - 1] = 1;
                F[x - 1][y - 1] = 0;
                go = !go;
                totalF--;
            }
        }
        else if (!turn && !F[x - 1][y - 1]) // player Dos' turn
        {
            Uno[x - 1][y - 1] = 0;
            Tres[x - 1][y - 1] = 0;
            F[x - 1][y - 1] = 1;
            turn = !turn;
            totalF++;
        }
        over = checkCombo(Uno) || checkCombo(Tres) || totalF == 0; // indicates if there is winner
        turnNumber++;                                              // adds to turn counter
    }

    return over;
}

/*
    Purpose: This function signifies the end of the game by printing the winning
             player's name and the final board
    Returns: void
    @param : over is status of the game (1 if over, 0 if not)
    @param : playerChars[] stores the chosen/default characters of each player
    @param : Uno stores the board of occupied/unoccupied spaces of player Uno
    @param : Dos stores the board of occupied/unoccupied spaces of player Dos
    @param : Tres stores the board of occupied/unoccupied spaces of player Tres
    @param : F is the 2d array where the coordinates will be marked
    Pre-condition: number of elements of the arrays match MAX
*/
void
GameOver(int over, char playerChars[], Array2D Uno, Array2D Dos, Array2D Tres, Array2D F)
{
    int i, j, totalF = 0;

    clrscr();

    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            if (F[i][j] == 1)
                totalF++; // counts if all spaces are occupied

    if (over && totalF == 0)
        printf("\n\033[36m\033[1m-------DOS WINS-------\033[0m\n");
    else if (over && checkCombo(Uno))
        printf("\n\033[33m\033[1m-------UNO WINS-------\033[0m\n");
    else if (over && checkCombo(Tres))
        printf("\n\033[35m\033[1m-------TRES WINS-------\033[0m\n");

    // prints final board
    printBoard(Uno, Tres, playerChars, 1);
}

int
main()
{
    Array2D Uno, Dos, Tres, F; // boards of each player
    int over, playerMode = 0, play = 1;
    char playerChars[2] = {'1', '3'}; // sets default player characters

    srand(time(0)); // sets time to help random generator

    while (play)
    {
        // initialize matrices

        initializeArray(Uno, 0);
        initializeArray(Dos, 0);
        initializeArray(Tres, 0);
        initializeArray(F, 1);

        startMenu(playerChars, &playerMode); // prints start menu

        over = NextPlayerMove(Uno, Dos, Tres, F, playerChars, playerMode); // starts game loop

        GameOver(over, playerChars, Uno, Dos, Tres, F); // prints winner board and game over screen

        printf("\nStart again? (\033[32m1 for yes\033[0m, \033[31m0 for no\033[0m): ");
        // asks if user wants to play again

        while (scanf("%d", &play) != 1 || (play != 0 && play != 1)) // repeats asking input while invalid
        {
            printf("Invalid input, try again\n");
            while (getchar() != '\n'); // clears buffer
        }
    }

    exitMenu(); // exits game

    return 0;
}

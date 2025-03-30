#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 4
#define TRUE 1
#define FALSE 0

typedef int Array2D[MAX][MAX];

void exitMenu();
void howToMenu();
void creditsMenu();
void comboListMenu();
void changeCharacter();
void enterCharacter();
void setGameMode();
void setSuccess();

/*
    Purpose: This function clears the screen
    Returns: void
*/
void clrscr()
{
    system("@cls||clear");
}

void startMenu(char playerChars[], int *playerMode)
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
                         next != 3 && next != 4 && next != 5 && next != 6))
	{
		printf("Invalid input, try again\n");
		while (getchar() != '\n');
	}
    switch (next)
    {
       case 1: howToMenu(playerChars, playerMode); break;
       case 2: changeCharacter(playerChars, playerMode); break;
       case 3: setGameMode(playerChars, playerMode); break;
       case 4: creditsMenu(playerChars, playerMode); break;
       case 5: exitMenu(playerChars, playerMode); break;
    }
} while (next != 6);
}

void howToMenu (char playerChars[], int *playerMode)
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
    printf("║      positions are occupied               ║\n");
    printf("║                                           ║\n");
    printf("║                                           ║\n");
    printf("║ 𓅭                  See Winning Combos [1] ║\n");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║       \033[5mEnter '0' to return to menu..\033[0m       ║\n");
    printf("╚═══════════════════════════════════════════╝\n");

    while (scanf("%d", &next) != 1 || (next != 0 && next != 1))
        {
            printf("Invalid input, try again\n");
            while (getchar() != '\n');
        }

    if (next == 1)
    {
        comboListMenu(playerChars, playerMode);
    } else return;

}

void comboListMenu (char playerChars[], int *playerMode)
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

    while (scanf("%d", &next) != 1 || (next != 0 && next != 1))
        {
            printf("Invalid input, try again\n");
            while (getchar() != '\n');
        }

    if (next == 1)
    {
        howToMenu(playerChars, playerMode);
    } else return;

}

void changeCharacter (char playerChars[], int *playerMode)
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
    printf("║                   %c and %c                 ║\n", playerChars[0], playerChars[1]);
    printf("║                                           ║\n");
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

    while (scanf("%d", &next) != 1 || (next != 0 && next != 1 && next != 2 && next != 3 ))
        {
            printf("Invalid input, try again\n");
            while (getchar() != '\n');
        }

    switch (next)
    {
        case 1: playerChars[0] = 'X'; playerChars[1] = 'O'; setSuccess(playerChars, playerMode, 0); break;
        case 2: playerChars[0] = '@'; playerChars[1] = '*'; setSuccess(playerChars, playerMode, 0); break;
        case 3: playerChars[0] = '1'; playerChars[1] = '3'; setSuccess(playerChars, playerMode, 0); break;
        case 4: enterCharacter(playerChars, playerMode); break;
    }

    return;
}

void enterCharacter (char playerChars[], int *playerMode)
{
    int ctr = 0, valid;
    char next, playerNames[2][5] = {"UNO ", "TRES"};

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
    printf("║                PLAYER %s                ║\n", playerNames[ctr]);
    printf("║                                           ║\n");  
    printf("║ 𓅭                                         ║\n");
    printf("╔═══════════════════════════════════════════╗\n");
    printf("║           \033[5mEnter '0' to cancel..\033[0m           ║\n");
    printf("╚═══════════════════════════════════════════╝\n");

    do 
    {
        if (scanf(" %c", &next) == 1) 
        {
            if (next == '0')
                return;

            playerChars[ctr] = next;

            valid = 1;  // Mark input as valid
            ctr++;
        }
        else
        {
            printf("Invalid input, try again\n");
        }
    
        while (getchar() != '\n');  // Clear input buffer
    
    } while (!valid);

    } while (ctr < 2);

    setSuccess(playerChars, playerMode, 0);
}

void setGameMode (char playerChars[], int *playerMode)
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

    while (scanf("%d", &next) != 1 || (next != 0 && next != 2 && next != 3))
        {
            printf("Invalid input, try again\n");
            while (getchar() != '\n');
        }

    if (next == 0)
        return;
    else 
    {
        *playerMode = !(next % 2); // 2 = 1, 3 = 0
        setSuccess(playerChars, playerMode, 1);
    }

}

void setSuccess (char playerChars[], int *playerMode, int menu)
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

    while (scanf("%d", &next) != 1 || (next != 0 && next != 1))
        {
            printf("Invalid input, try again\n");
            while (getchar() != '\n');
        }

    if (next == 1)
    {
        if (menu == 0)
            changeCharacter(playerChars, playerMode);
        else setGameMode(playerChars, playerMode);
    } else return;

}

void creditsMenu (char playerChars[], int *playerMode)
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

    while (scanf("%d", &next) != 1 || next != 0 )
        {
            printf("Invalid input, try again\n");
            while (getchar() != '\n');
        }

    return;
}

void exitMenu ()
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
    exit(0);
}

/*
    Purpose: This function sets the value of each 2d array element to a number.
    Returns: void
    @param : arr is the 2d array to be initialized
    @param : num is the number the array is initialized to
    Pre-condition: number of elements in arr match MAX
*/
void initializeArray(Array2D arr, int num)
{
    int i, j;

    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            arr[i][j] = num;
}

/*
    Purpose: This function prints the contents of a 2D array in a 4x4 board.
             The first row and column should print numbers 1-4 as the column
             and row coordinates, respectively.
    Returns: void
    @param : arr is the 2d array to be printed
    Pre-condition: arr is initialized
*/
void printBoard(Array2D arr1, Array2D arr2, char playerChars[], int state)
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
                case 0: 
                    if (arr1[i][j] == 0 && arr2[i][j] == 0)
                        printf(" - |");
                    else printf(" O |");
                    break;
                case 1:
                    if (arr1[i][j] == 1)
                        printf(" %c |", playerChars[0]);
                    else if (arr2[i][j] == 1)
                        printf(" %c |", playerChars[1]);
                    else printf(" - |");
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
    Purpose: This function checks the validity of an integer input.
    Returns: 1 if the input is between 1 and 4 inclusive,
                 otherwise it returns 0
    @param : input is the integer to be evaluated
    Pre-condition: argument passed to function must be of type int
*/
int isValidInput(int input)
{
    if (input >= 1 && input <= 4)
        return 1;
    else
        return 0;
}

/*
    Purpose: This function asks the user for coordinates x and y. If the input
             is invalid, an error message will be displayed until the user
             enters a valid input.
    Returns: void
    @param : *x stores the x coordinate
    @param : *y stores the y coordinate
    @param : F is the 2d array where the coordinates will be marked
    @param : player specifies which player turn it is 
    Pre-condition: arguments passed to function are of proper type
*/
void getCoordinates(int *x, int *y, Array2D F, int player)
{
    *x = 0;
    *y = 0;

    do
    {
        if (isValidInput(*x) && isValidInput(*y))
            if ((player % 3 == 1 && F[*x - 1][*y - 1]) || ((player % 3 == 0 || player % 3 == 2) && !F[*x - 1][*y - 1]))
                printf("\nThis space cannot be selected. Please enter a different coordinate.");

        printf("\nEnter row: ");
        scanf("%d", x);
        while (getchar() != '\n');
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
    } while ((player % 3 == 1 && F[*x - 1][*y - 1]) || ((player % 3 == 0 || player % 3 == 2) && !F[*x - 1][*y - 1]));
}

/*
    Purpose: This function uses linear search to search for a key in an array. 
    Returns: either (a) index of found key or (b) -1 to signify key is not found
    @param : key is the number to be searched for
    @param : *arr is the array to be searched
    @param : size is the number of elements to be searched
    Pre-condition: arguments passed to function are of proper type
*/
int Search(int key, int *arr, int size)
{
    int i, found;
    found = -1;

    for (i = 0; i < size; i++)
        if (arr[i] == key)
            found = i;

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
int checkCombo(Array2D arr) // improve
{
    int W[3][4] = {{11, 12, 13, 14}, 
                   {14, 23, 32, 41}, 
                   {41, 42, 43, 44}}; // Winning combinations
    int temp[16] = {0};
    int ctr = 0, i, j, k = 0;

    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            if (arr[i][j] == 1)
            {
                temp[k] = (i + 1) * 10 + (j + 1); // Converts (x, y) to a 2-digit integer
                k++;
            }

    for (i = 0; i < 3 && ctr < 4; i++)
    {
        ctr = 0;
        for (j = 0; j < MAX; j++)
            if (Search(W[i][j], temp, k) >= 0)
                ctr++;
    }

    if (ctr == 4)
        return 1;
    else return 0;
}

/*
    Purpose: This function accepts a number and prints its corresponding player name.
    Returns: either (a) 1 if all elements of a row in W is found in the 2D array (b) else 0
    @param : num specifies which player's turn it is
    Pre-condition: num is either 0, 1, or 2
*/
void playerName(int num)
{
    printf("\n");

    switch (num)
    {
    case 0:
        printf("\033[31m%17s\033[0m", "Player Uno");
        break;
    case 1:
        printf("\033[32m%17s\033[0m", "Player Dos");
        break;
    case 2:
        printf("\033[33m%17s\033[0m", "Player Tres"); 
        break;
    }
}

void
randPlayer (Array2D arr, int *x, int *y)
{
    do
    {
        *x = rand() % 4 + 1;
        *y = rand() % 4 + 1;

    } while (arr[*x - 1][*y - 1]);
}

/*
    Purpose: This function starts the going through each player's turn (Uno, Dos, and Tres) and
             repeats it until a player wins according to either:
                (a) a winning combination is found or
                (b) all elements in the 2d matrix F are 0

             The player turn order starts with Uno, Dos, then Tres. Uno and Tres can occupy an
             an unoccupied position in board F by entering its row and column index. While Dos can
             unoccupy a position occupied by Tres or Uno in the same fashion.

             An occupied position is marked as 1 while an occupied one is 0.
                
    Returns: 1 once the game is over
    @param : Uno stores the board of occupied/unoccupied spaces of player Uno
    @param : Dos stores the board of occupied/unoccupied spaces of player Dos
    @param : Tres stores the board of occupied/unoccupied spaces of player Tres
    @param : F is the 2d array where the coordinates will be marked
    Pre-condition: number of elements of the arrays match MAX
*/
int
NextPlayerMove(Array2D Uno, Array2D Dos, Array2D Tres, Array2D F, char playerChars[], int playerMode)
{
    int turn = TRUE, go = FALSE, over = FALSE;
    int totalF = 16, player = 0;
    int x, y;

    while (!over)
    {
        if (!(playerMode == 1 && player % 3 == 1)) // default is three players
        {
        clrscr();
        playerName(player % 3);

        printBoard(Uno, Tres, playerChars, player % 3 != 1);

        if (player % 3 == 2)
            printf("\n    Dos removed %d %d\n", x, y);

        getCoordinates(&x, &y, F, player);
        } else randPlayer(F, &x, &y);

        if (turn)
        {
            if (!go && F[x - 1][y - 1])
            {
                Uno[x - 1][y - 1] = 1;
                F[x - 1][y - 1] = 0;
                turn = !turn;
                go = !go;
                totalF--;
            }
            else if (go && F[x - 1][y - 1])
            {
                Tres[x - 1][y - 1] = 1;
                F[x - 1][y - 1] = 0;
                go = !go;
                totalF--;
            }
        }
        else if (!turn && !F[x - 1][y - 1])
        {
            Uno[x - 1][y - 1] = 0;
            Tres[x - 1][y - 1] = 0;
            F[x - 1][y - 1] = 1;
            turn = !turn;
            totalF++;
        }
        over = checkCombo(Uno) || checkCombo(Tres) || totalF == 0;
        player++;
    }

    return over;
}

/*
    Purpose: This function signifies the end of the game by printing the winning
             player's name and the final board
    Returns: void
    @param : over is status of the game (1 if over, 0 if not)
    @param : Uno stores the board of occupied/unoccupied spaces of player Uno
    @param : Dos stores the board of occupied/unoccupied spaces of player Dos
    @param : Tres stores the board of occupied/unoccupied spaces of player Tres
    @param : F is the 2d array where the coordinates will be marked
    Pre-condition: number of elements of the arrays match MAX
*/
void GameOver(int over, char playerChars[], Array2D Uno, Array2D Dos, Array2D Tres, Array2D F)
{
    int i, j, totalF = 0;
    
    clrscr();
    
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            if (F[i][j] == 1)
                totalF++;

    if (over && totalF == 0)
        printf("\n--------Dos Wins--------\n");
    else if (over && checkCombo(Uno))
        printf("\n--------Uno Wins--------\n");
    else if (over && checkCombo(Tres))
        printf("\n--------Tres Wins--------\n");
    
    // Print final board
    printBoard(Uno, Tres, playerChars, 1);
}
int main()
{
    Array2D Uno, Dos, Tres, F; 
    int over, playerMode = 0, play = 1;
    char playerChars[2] = {'1', '3'};

    srand(time(0));
    
    while (play)
    {
        initializeArray(Uno, 0);
        initializeArray(Dos, 0);
        initializeArray(Tres, 0);
        initializeArray(F, 1);

        startMenu(playerChars, &playerMode);
        over = NextPlayerMove(Uno, Dos, Tres, F, playerChars, playerMode);
        GameOver(over, playerChars, Uno, Dos, Tres, F);

        printf("\nPlay again? (1 for yes, 0 for no): ");
        scanf("%d", &play);
    }
    return 0;
}

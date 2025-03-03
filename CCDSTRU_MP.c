#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define TRUE 1
#define FALSE 0

typedef int Array2D[MAX][MAX];

/*
    Purpose: This function clears the screen
    Returns: void
*/
void clrscr()
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
void printBoard(Array2D arr)
{
    int i, j;

    printf("\n     1   2   3   4\n");
    printf("   +---+---+---+---+\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d  |", i + 1);
        for (j = 0; j < MAX; j++)
        {
            printf(" %d |", arr[i][j]);
        }
        printf("\n");
    }
    printf("   +---+---+---+---+\n");
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
        while (!isValidInput(*x))
        {
            printf("Invalid input. Enter row: ");
            scanf("%d", x);
        }

        printf("Enter column: ");
        scanf("%d", y);
        while (!isValidInput(*y))
        {
            printf("Invalid input. Enter column: ");
            scanf("%d", y);
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
    switch (num)
    {
    case 0:
        printf("%17s", "Player Uno");
        break;
    case 1:
        printf("%17s", "Player Dos");
        break;
    case 2:
        printf("%17s", "Player Tres"); 
        break;
    }
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
int NextPlayerMove(Array2D Uno, Array2D Dos, Array2D Tres, Array2D F)
{
    int turn = TRUE, go = FALSE, over = FALSE;
    int totalF = 16, player = 0;
    int x, y;

    while (!over)
    {
        clrscr();
        playerName(player % 3);
        printBoard(F);
        getCoordinates(&x, &y, F, player);
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
void GameOver(int over, Array2D Uno, Array2D Dos, Array2D Tres, Array2D F)
{
    int i, j, totalF = 0;
    
    clrscr();
    
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            if (F[i][j] == 1)
                totalF++;

    if (over && totalF == 0)
        printf("\n-------Dos Wins-------\n");
    else if (over && checkCombo(Uno))
        printf("\n-------Uno Wins-------\n");
    else if (over && checkCombo(Tres))
        printf("\n-------Tres Wins-------\n");
    
    // Print final board
    printf("\n     1   2   3   4\n");
    printf("   +---+---+---+---+\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d  |", i + 1);
        for (j = 0; j < MAX; j++)
        {
            if (Uno[i][j] == 1)
                printf(" U |");
            else if (Tres[i][j] == 1)
                printf(" T |");
            else printf(" X |");
        }
        printf("\n");
    }
    printf("   +---+---+---+---+\n");
}

int main()
{
    Array2D Uno, Dos, Tres, F; 
    int over;

    initializeArray(Uno, 0);
    initializeArray(Dos, 0);
    initializeArray(Tres, 0);
    initializeArray(F, 1);
    
    over = NextPlayerMove(Uno, Dos, Tres, F);
    GameOver(over, Uno, Dos, Tres, F);

    return 0;
}

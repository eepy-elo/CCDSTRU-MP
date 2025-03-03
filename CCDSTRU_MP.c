#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define TRUE 1
#define FALSE 0

typedef int Array2D[MAX][MAX];

void clrscr()
{
    system("@cls||clear");
}

/*
    Purpose: This function sets the value of each 2d array element to a number.
    Returns: void
    @param : arr is the 2d array to be initialized
    @param : num is the number the array is initialized to
    Pre-condition: 
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
    Pre-condition:
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
    @param : F 
    @param : player specifies which player turn it is 
    Pre-condition:
*/
void getCoordinates(int *x, int *y, Array2D F, int player)
{
    *x = 0;
    *y = 0;
    do
    {
        if (isValidInput(*x) && isValidInput(*y))
            if ((player % 3 == 1 && F[*x - 1][*y - 1]) || ((player % 3 == 0 || player % 3 == 2) && !F[*x - 1][*y - 1])))
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
    } while ((player % 3 == 1 && F[*x - 1][*y - 1]) || ((player % 3 == 0 || player % 3 == 2) && !F[*x - 1][*y - 1])));
}
/*
    Purpose: This function uses linear search to search for a key in an array. 
    Returns: either (a) index of found key or (b) -1 to signify key is not found
    @param : key is the number to be searched for
    @param : *arr is the array to be searched
    @param : size is the number of elements to be searched
    Pre-condition: 
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

// This function takes a 2D array and checks if it contains the winning combinations in W. 
// If an index in the 2D array contains 1, it stores the row and column indices in array temp
// as a 2-digit integer. 
//     Example: arr[1][2] => 12
// Once all the elements of a row in W is found in the 2D array, the function returns 1.  
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

// This function accepts a number and prints its corresponding player name.
void playerName(int num)
{
    switch (num)
    {
    case 0:
        printf("      Player Tres");
        break;
    case 1:
        printf("       Player Uno");
        break;
    case 2:
        printf("       Player Dos");
        break;
    }
}

// This function starts the game and loops it until a winning combination is found, 
// or if all elements in the 2D matrix F are 0. The order of turns starts with player 
// Tres, followed by Uno, then Dos. At each of their turns, players Uno and Tres can 
// occupy a position in board F by entering its row and column index. On the contrary
// player Dos inputs an occupied position by either Uno or Tres and makes it unoccupied.
// An unoccupied position is marked as 1 while an occupied one is 0. The function returns
// 1 if the game is over.
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

// This function prints the winning player's name and board.
void GameOver(int over, Array2D Uno, Array2D Dos, Array2D Tres, Array2D F)
{
    int i, j, totalF = 0;
    
    clrscr();
    
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            if (F[i][j] == 1)
                totalF++;

    if (over && totalF == 0)
    {
        printf("\n-------Dos Wins-------\n");
        printBoard(F);
    }
    else if (over && checkCombo(Uno))
    {
        printf("\n-------Uno Wins-------\n");
        printf("\n      Uno's Board");
        printBoard(Uno);
    }
    else if (over && checkCombo(Tres))
    {
        printf("\n-------Tres Wins-------\n");
        printf("\n      Tres' Board");
        printBoard(Tres);
    }
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

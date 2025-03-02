#include <stdio.h>
#define MAX 4
#define TRUE 1
#define FALSE 0

typedef int Array2D[MAX][MAX];

/*
	Purpose: This function sets the value of each 2d array element to a number.
	Returns: void
	@param : arr is the 2d array to be initialized
	Pre-condition: 
*/
void 
initializeArray(Array2D arr, int num)
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
void 
printBoard(Array2D arr)
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
int 
isValidInput(int input)
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
	@param *x: stores the x coordinate
    	@param *y: stores the y coordinate
	Pre-condition: 
*/
void 
getCoordinates(int *x, int *y)
{
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
}

int 
Search(int key, int *arr, int size)
{
    int i, found;
    found = -1;

    for (i = 0; i < size; i++)
        if (arr[i] == key)
            found = i;

    return found;
}

int
checkCombo(Array2D arr) // does not check correctly
{
    int W[3][4] = {{11, 12, 13, 14}, {14, 23, 32, 41}, {41, 42, 43, 44}}; // Winning combinations
    int temp[16] = {0};
    int ctr, i, j, k = 0;

    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            if (arr[i][j])
            {
                temp[k] = (i + 1) * 10 + (j + 1); // Converts (x, y) to a 2-digit integer
                k++;
            }

    for (i = 0; i < 3 && ctr != 4; i++)
    {
        ctr = 0;
        for (j = 0; j < MAX; j++)
            if (Search(W[i][j], temp, k) >= 0)
            {
                //printf{"%d ", W[i][j]}; // Debugging
                ctr++;
                printf{"%d ", ctr}; // Debugging
            }
    }

    if (ctr == 4)
        return 1;
    else return 0;
}

void
playerName(int num)
{
    switch (num)
    {
        case 0: printf("\n      Player Tres"); break;
        case 1: printf("\n       Player Uno"); break;
        case 2: printf("\n       Player Dos"); break;
    }
}

void
startGame(Array2D arr1, Array2D arr2, Array2D arr3, Array2D board)
{
	int go = FALSE, turn = TRUE, over = FALSE;
    int i, j, totalF = 16, player = 0;
    int x, y;

	while (!over) {
        playerName(player % 3);
		printBoard(F);
        getCoordinates(&x, &y);
		if (turn)
			if (go && F[x - 1][y - 1])
			{
				Uno[x - 1][y - 1] = 1;
            	F[x - 1][y - 1] = 0;
				turn = !turn;
				go = !go;
                totalF--;
			}
			else (!go && F[x - 1][y - 1])
			{
				Tres[x - 1][y - 1] = 1;
            	F[x - 1][y - 1] = 0;
				go = !go;
                totalF--;
			}
		else (!turn && !F[x - 1][y - 1])
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

    initializeArray(Uno, 0);
    initializeArray(Dos, 0);
    initializeArray(Tres, 0);
    initializeArray(F, 1);

    printf("\n%d", checkCombo(Dos));
	startGame(Uno, Dos, Tres, F);

    return 0;
}

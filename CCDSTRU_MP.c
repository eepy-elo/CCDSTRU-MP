#include <stdio.h>
#define MAX 4
#define TRUE 1
#define FALSE 0

typedef int Array2D[MAX][MAX];

/*
	Purpose: This function sets the value of each 2d array element to 0
	Returns: void
	@param : arr is the 2d array to be initialized
	Pre-condition: 
*/
void
initializeArray(Array2D arr)
{
    int i, j;

    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            arr[i][j] = 0; 
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
    printf("    1   2   3   4\n");
    printf(" +---+---+---+---+\n");
    for (int i = 0; i < MAX; i++){
        printf("%d  |", i+1);
        for (int j = 0; j < MAX; j++){
            printf(" %d ", arr[i][j]);
        }
        printf("|\n");
    }
    printf(" +---+---+---+---+\n");
}


/*
	Purpose: This function checks the validity of an integer input.
	Returns: 1 if the input is between 1 and 4 inclusive,
             	 otherwise it returns 0
	@param : input is the integer to be evaluated
	Pre-condition: 
*/
int
isValidInput(int input);

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
getCoordinates(int *x, int *y);

//int
//gameOver(Array2D arr1, Array2D arr2, Array2D F, Array2D W);

//kita m pa ba or nope dstru mp folder lng ok nice or not >:)!!!!!!!
int
main()
{
    Array2D Uno, Dos, Tres, F;
    int go = FALSE, turn = TRUE, over = FALSE;
    
    initializeArray(Uno);
    initializeArray(Dos);
    initializeArray(Tres); //maglist lang muna ak functions
    initializeArray(F); //SAN KA MORC //gawin bang pointer ung arr @shelo joke nde pla LOL gumagana sha
    printBoard(F);

    //printf("%d", Uno[0][0]);
    return 0;
}

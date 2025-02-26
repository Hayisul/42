#include <stdlib.h>
#include <unistd.h>

/*
PROTOTYPES
*/
void	print_grid(int **grid);
int		*error_check(int argc, char *args, int value);
int		is_valid(int **grid, int *input);
int		is_okay(int **grid, int row, int col, int num);

/*
Used in 'main.c/int main()'
TO GET THE NEXT ROW AND COLUMN.
It moves to the next column or, if at the end of the row,
moves to the start of the next row.
*/
void	get_next_position(int row, int col, int *next_row, int *next_col) //Takes the current row index, the current column index, the next row index, and the next column index
{
	if (col == 3) //Checks if the current column is the last in the row for a 4x4 grid
	{
		*next_row = row + 1; //Increments the row index
		*next_col = 0; //Sets the next column index to 0
	}
	else //If the current cell is not at the end of the row
	{
		*next_row = row; //Leaves the next row index unchanged
		*next_col = col + 1; //Increments the column index
	}
}

/*
Used in 'main.c/main()'
TO SOLVE THE PUZZLE WITH BACKTRACKING.
It tries to place each number in the current cell,
recursively attempts to solve the rest of the grid,
and backtracks if necessary.
*/
int	solve(int **grid, int *input, int row, int col) //Takes the 2D array grid where the solution is to be filled, an array containing visibility constraints for each row and column, and current row and column indices where the function tries to place a number
{
	int	next_row; //Stores the coordinates of the next cell in the row
	int	next_col; //Stores the coordinates of the next cell in the column
	int	num; //Used to try placing each number (1 to 4) in the current cell

	if (row == 4) //Checks if the recursion has filled all rows (from 0 to 3)
    {
		return (is_valid(grid, input)); //Based on the results of is_valid, returns true or false, in the second case propagating the result of the validation back through the recursive call stack
    }
	get_next_position(row, col, &next_row, &next_col); //Determines the next cell in the grid to attempt to fill, adjusting row and column indices accordingly
	num = 1; //Initializes num to 1
	while (num <= 4) //Iterates over each number (1 to 4)
	{
		if (is_okay(grid, row, col, num)) //Checks if placing num in the current cell is okay
		{
			grid[row][col] = num; //Places number in the grid
			if (solve(grid, input, next_row, next_col)) //Recursively calls solve for the next position
			{
				return (1); //Propagates the success back up the recursion stack (call stack = each function call is stacked on top of the previous one until a base condition is reached or the function returns)
			}
			grid[row][col] = 0; //Resets the current cell
		}
		num++; //Moves to the next number
	}
	return (0); //Prompts backtracking in the recursion when no number can be placed in the current cell
}

/*
Used in 'main.c/main()'
TO ALLOCATE MEMORY FOR THE GRID.
It creates a 2D array (4 rows, each with 4 columns)
and initializes all cells to 0.
*/
int	**allocate_memory(void)
{
	int	i; //Loop counter for iterating over the rows of the grid
	int	j; //Loop counter for iterating over the columns of the grid
	int	**grid; //Pointer to a pointer that will be used to create a 2D array (grid)

	grid = malloc(4 * sizeof(int *)); //Allocates memory for the grid's rows (4 times the size of a pointer to an integer)
	i = 0; //Initializes rows to 0
	while (i < 4) //Iterates over each row (0 to 3)
	{
		grid[i] = malloc(4 * sizeof(int)); //Allocates memory for a row of 4 integers
		j = 0; //Initializes columns to 0
		while (j < 4) //Iterates over each column (0 to 3)
		{
			grid[i][j] = 0; //Initializes each cell in the grid to 0
			j++; //Moves to next column
		}
		i++; //Moves to next row
	}
	return (grid); //Starting address of the entire 2D grid structure
    /*
    The returned structure is a 4x4 grid, each cell initialized to 0. The memory layout can be visualized as a list of pointers, where each pointer directs to a separate array representing a row of the grid.
    */
}

/*
ENTRY POINT OF THE PROGRAM.
It allocates memory for the grid,
parses and checks the input,
solves the puzzle,
prints the grid if solved,
or prints "Error" if there is an issue.
*/
int	main(int argc, char *argv[])
{
	int	*input; //Pointer to an array that will hold the visibility constraints
	int	**grid; //Pointer to a 2D arry representing the grid
	int	i; //Loop counter for cleaning up allocated memory

	grid = allocate_memory(); //Calls the allocate_memory function to create a 4x4 grid and initialize all cells to 0
	input = error_check(argc, argv[1], 4); //Calls the error_check function to validate the number of command-line arguments and parses the input string into an integer array
	if (!input) //there was an error in parsing or validation
	{
		write(1, "Error\n", 6); //Print “Error” to the standard output
		return (0); //Exit the program
	}
	if (solve(grid, input, 0, 0)) //Indicates the puzzle is solved successfully
    {
		print_grid(grid); //Displays the grid
    }
	else //Indicates the puzzle isn't solved 
    {
		write(1, "Error\n", 6);
    }
	i = 0; //Initializes the loop counter to zero
	while (i < 4) //Iterates over each sub-array of the grid
	{
		free(grid[i]); //Frees the memory allocated for the row (i) of the grid
		i++; //MOves to the next row
	}
	free(input); //Frees the input array
	free(grid); //Frees the grid array
	return (0); //Exits the program
}

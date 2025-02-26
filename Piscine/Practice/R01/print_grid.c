#include <unistd.h>

/*
Used in 'main.c/main()'
TO PRINT THE SOLUTION.
It loops through each cell of the 4x4 grid,
converting each integer to a character, and prints it.
It separates numbers with spaces and rows with newlines.
*/
void	print_grid(int **grid) //Take a 2D array grid
{
	int		i; //Loop counter iterating trhough the rows
	int		j; //Loop counter iterating trhough the column
	char	c; //Character representation of the integer values in the grid

	i = 0; //Initializes rows to 0
	while (i < 4) //Iterates through the rows of the grid 
	{
		j = 0; //Initializes columns to 0
		while (j < 4) //Iterates through the columns of the grid 
		{
			c = grid[i][j] + '0'; //Converts the integer value to its corresponding ASCII character
			write(1, &c, 1); //Prints the character c to the standard output
			if (j < 3) //After each number except for the last number in a row
				write(1, " ", 1); //Prints a space character
			j++; //Moves to the next column
		}
		write(1, "\n", 1); //Prints a newline character
		i++; //Moves to the next row
	}
}

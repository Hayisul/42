/*
Used in 'main.c/solve()'. It's job is
TO CHECK IF THE NUMBER IS NOT A DUPLICATE.
It ensures that num is not already present in the same row or column.
*/
int	is_okay(int **grid, int row, int col, int num) //Takes a 2D grid array grid, a row, a column, and a number
{
	int	i; //Loop counter to iterate over the rows and columns of the grid 

	i = 0; //Initializes the loop counter to zero
	while (i < 4) //Iterates through elements in the specified row or column
	{
		if (grid[row][i] == num || grid[i][col] == num) //Checks whether the number num already exists anywhere else in the same row or column
		{
			return (0); //Exits the function
		}
		i++; ////Moves to the next row or column
	}
	return (1); //Returns that there's no conflict between numbers
}

/*
Used in 'solver.c/check visibility()'
TO UPDATE THE MAX HEIGHT SEEN SO FAR AND THE VISIBILITY COUNT.
It compares the current height with the max height encountered so far
and updates the visibility count accordingly.
*/
int	check_height(int height, int max_height, int *vis_count) //Takes the height of the current skyscraper being checked, the maximum height observed up to this point, and the count of visible skyscrapers
{
	if (height > max_height) //Compares the current skyscraper’s height with the maximum height recorded so far
	{
		max_height = height; //Updates max_height to this new value
		*vis_count = *vis_count + 1; //Increments the count of visible skyscrapers
	}
	return (max_height); //Returns the updated maximum height

/*
Used in 'solver.c/is_valid()'
TO CHECK THE VISIBILITY FROM ONE DIRECTION.
It scans the grid in the specified direction
and counts the number of visible skyscrapers based on their heights.
*/
int	check_visibility(int **grid, int index, int row_or_col, int direction) //Takes a 2D array grid, the row or column number, a flag to check a row (1) or a cloumn (0), and a flag to specify the direction to look from: end to start (1) or start to end (0)
{
	int	max_height; //Tracks the highest skyscraper seen so far as you move along the row or column
	int	vis_count; //Counts the number of skyscrapers visible from the perspective point
	int	i; //Loop counter used to traverse the grid
	int	height; //Sets the current building’s height based on the specified row/column and direction

	max_height = 0; //Initializes the height tracker to zero
	vis_count = 0; //Initializes the loop counter to zero
	i = 0; //Initializes the loop counter to zero
	while (i < 4) //Iterates through elements in the specified row or column
	{
		if (row_or_col && direction) //For rows, looking from right to left
		{
			height = grid[index][3 - i]; //Accesses the grid at the specified row (index) and column (3 - i), reversing the column index as i increases, to observe the skyscrapers from right to left
		}
		else if (row_or_col && !direction) //For rows, looking from left to right
		{
			height = grid[index][i]; //Accesses the grid at the specified row (index) and columns (i), to observe the skyscrapers from left to right
		}
		else if (!row_or_col && direction) //For columns, looking from bottom to top
		{
			height = grid[3 - i][index]; //Accesses the grid at the specified column (index) and row (3 - i), reversing the row index as i increases, to observe the skyscrapers from buttom to top
		}
		else //For columns, looking from top to bottom
		{
			height = grid[i][index]; //Accesses the grid at the specified column (index) and row (i), to observe the skyscrapers from top to bottom
		}
		max_height = check_height(height, max_height, &vis_count); //Updates max_height to this new value and increments vis_count based on the comparison between height and max_height
		i++; //moves to the next element
	}
	return (vis_count); //Returns the total number of skyscrapers visible from the starting point in the given direction for the specified row or column
}

/*
Used in 'main.c/solve()'
TO CHECK IF THE GRID IS VALID.
It checks the visibility constraints for all rows and columns,
ensuring that the grid matches the provided constraints.
*/
int	is_valid(int **grid, int *input) //Takes a 2D array grid where each value represents a skyscraper's height, and an array containing the visibility constraints for each row and column
{
	int	i; //Loop counter to iterate over the rows and columns of the grid

	i = 0; //Initializes the loop counter to zero
	while (i < 4) //Iterates over each line of the grid (4 lines total, since the grid is 4x4), 
	{
		if (check_visibility(grid, i, 0, 0) != input[i]) //Compares the visible buildings from the left of a row (i) with the corresponding constraint in the input array
		{
			return (0); //Returns false if there's a mismatch
		}
		if (check_visibility(grid, i, 0, 1) != input[4 + i]) //Compares the visible buildings from the right of a row (i) with the corresponding constraint in the input array
		{
			return (0); //Returns false if there's a mismatch
		}
		if (check_visibility(grid, i, 1, 0) != input[2 * 4 + i]) //Compares the visible buildings from the top of a column (i) with the corresponding constraint in the input array
		{
			return (0); //Returns false if there's a mismatch
		}
		if (check_visibility(grid, i, 1, 1) != input[3 * 4 + i]) //Compares the visible buildings from the buttom of a column (i) with the corresponding constraint in the input array
		{
			return (0); //Returns false if there's a mismatch
		}
		i++; //Moves to the next row or column
	}
	return (1); //Returns true if all visibility checks pass for all rows and columns, indicating the grid configuration is valid according to all input constraints
}

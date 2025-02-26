#include <stdlib.h>
#include <unistd.h>

/*
Used in 'check.c/input_parsing()'
TO DETERMINE THE NUMBER OF INTEGERS IN THE DEST ARRAY.
It iterates through the array and counts the number of non-zero elements.
 */
int	array_length(int *array) //Takes an array whose length is to be calculated
{
	int	i; //Loop counter to track the number of elements in the array until a zero is encountered

	i = 0; //Initializes the element counter to zero
	while (array[i]) //Iterates through the array until a zero is found
	{
		i++; //Counts the number of non-zero integers by incrementing at each iteration
	}
	return (i); //Returns the count of non-zero elements in the array up to the first zero
}

/*
Used in 'check.c/error_check()'. It's job is
TO CONVERT THE INPUT STRING INTO AN ARRAY OF INTEGERS.
It converts valid characters to integers
and stores them in the dest array.
It ensures that no invalid characters are present
and that the parsed length matches the expected size.
*/
int	*input_parsing(char *str, int *dest, int value) //Takes a string containing the visibility constraints, a destination array to store parsed integers, and the maximum value for any single digit in the input
{
	int	i; //Index for populating the dest array

	value = value + '0'; //Converts value from an integer to its ASCII character equivalent 
	i = 0; //Initializes the index i used to store numbers into the dest array to zero
	if (!(*str >= '1' && *str <= value)) //Checks if the first character of str is a valid digit within the range
	{
		return (NULL);
	}
	while (*str != '\0') //Loop that continues until the end of the string
	{
		if (*str == ' ') // If the current character is a space 
		{
			str++; //Increments the pointer to skip over the space, moving to the next character
		}
		if (*str >= '1' && *str <= value) //If the current character is a digit within the valid range
		{
			dest[i] = *str - '0'; //Converts the character digit to its integer equivalent by subtracting '0', by exploiting the layout of the ASCII table where digits are sequential, and stores the converted integer into dest[i]
			i++; //Moves to next position in the dest array
			str++; //Moves the str pointer to the next character in the input string
		}
		else //If any character in the string is not a space and is not a valid digit within the specified range
		{
			return (NULL); //Indicates an invalid input
		}
	}
	return (dest); //Returns the pointer to the array dest that now contains the parsed and validated integer values from the input string
}

/*
Used in 'main.c/main()'
TO VALIDATE THE COMMAND-LINE INPUT.
It validates the number of arguments,
parses the input string into an integer array,
and ensures that the array length matches the expected number of values.
It returns a pointer to the array or NULL on failure.
*/
int	*error_check(int argc, char *args, int value) //Takes the number of command-line arguments, the string containing the visibility constraints, and the grid size (4)
{
	int	size; //Variable used to compute the total number of visibility constraints expected
	int	*dest; //Pointer to an array of integers, that will store the parsed input values which are the visibility constraints

	size = value * value; //Calculates the total number of visibility constraints expected (computation)
	if (argc != 2) //Ensures the correct number of command-line arguments is provided
	{
		return (NULL); //Indicates incorrect input
	}
	dest = malloc(sizeof(int) * (size/*+ 1*/)); //Allocates memory for storing the parsed visibility constraints.(The size + 1 is typically to accommodate the exact number of visibility numbers expected plus an extra space for a terminating zero or safety margin, though in this context the “+1” might be superfluous or a safety measure.)
	if (!dest) //Ensures that malloc is successful before proceeding
	{
		return (NULL); //Indicates an error in memory allocation
	}
	if (!input_parsing(args, dest, value)) //Calls the input_parsing function to convert the input string into integers stored in dest
	{
		return (NULL); //If input_parsing returns NULL, error_check also returns NULL
	}
	if (array_length(dest) != (size)) //Compares the length of the parsed data in dest against the expected size
	{
		free(dest); //Frees the allocated memory to avoid memory leaks (orphaned memory blocks that have no pointer pointing to it)
		return (NULL); //Indicates an incorrect input length
	}
	return (dest); //If all checks are passed, dest is returned containing the parsed and validated input
}

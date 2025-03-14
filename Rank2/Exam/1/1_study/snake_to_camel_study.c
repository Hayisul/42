// Expected files   : snake_to_camel.c
// Allowed functions: malloc, free, realloc, write
// --------------------------------------------------------------------------------

// Write a program that takes a single string in snake_case format
// and converts it into a string in lowerCamelCase format.
//
// A snake_case string is a string where each word is in lower case,
// separated by an underscore "_".

// A lowerCamelCase string is a string where each word begins with a capital letter
// except for the first one.

#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		for (int i = 0; argv[1][i]; i += 1)
		{
			if (argv[1][i] == '_')
			{
				i += 1;
				argv[1][i] -= 32;
			}
			write(STDOUT_FILENO, &argv[1][i], 1);
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return EXIT_SUCCESS;
}

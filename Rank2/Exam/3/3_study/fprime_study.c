// Expected files   : fprime.c
// Allowed functions: printf, atoi
// --------------------------------------------------------------------------------
//
// Write a program that takes a positive int
// and displays its prime factors on the standard output,
// followed by a newline.
//
// Factors must be displayed in ascending order and separated by '*',
// so that the expression in the output gives the right result.
//
// If the number of parameters is not 1, simply display a newline.
//
// The input, when there is one, will be valid.

#include <stdio.h>
#include <stdlib.h>

int		is_prime(int n)
{
	int i = 2;

	while (i < n)
	{
		if (n % i == 0)
			return (0);
		++i;
	}
	return (1);
}

void	fprime(char *str)
{
	int n = atoi(str);
	int factor = 2;
	int first = 1;

	if (n == 1)
		printf("1");

	while (factor <= n)
	{
		if (n % factor == 0 && is_prime(factor))
		{
			if (first == 1)
				printf("%d", factor);
			else
				printf("*%d", factor);
			first = 0;
			n = n / factor;
		}
		else
			++factor;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		fprime(argv[1]);

	printf("\n");
	return (0);
}
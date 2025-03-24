// Expected files   : pgcd.c
// Allowed functions: printf, atoi, malloc, free
// --------------------------------------------------------------------------------
//
// Write a program that takes two strings
// representing two strictly positive integers that fit in an int.
//
// Display their highest common denominator followed by a newline
// (It's always a strictly positive integer).
//
// If the number of parameters is not 2, display a newline.

#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	int n = a;

	while (n > 0)
	{
		if (a % n == 0 && b % n == 0)
		{
			printf("%d", n);
			return;
		}
		--n;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));

	printf("\n");
	return (0);
}
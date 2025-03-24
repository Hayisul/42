// Expected files   : paramsum.c
// Allowed functions: write
// --------------------------------------------------------------------------------
//
// Write a program that displays the number of arguments passed to it,
// followed by a newline.
//
// If there are no arguments, just display a 0 followed by a newline.

#include <unistd.h>

void	ft_putnbr(int n)
{
	char digit;

	if (n >= 10)
		ft_putnbr(n / 10);

	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int		main(int argc, char **argv)
{
	(void)argv;		// Silence 'unused parameter' error

	ft_putnbr(argc - 1);
	write(1, "\n", 1);

	return (0);
}
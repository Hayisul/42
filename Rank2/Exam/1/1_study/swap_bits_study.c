// Expected files   : swap_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------
//
// Write a function that takes a byte, swaps its halves
// and returns the result.

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

/*
#include <unistd.h>

int	main(int argc, char **argv)
{
	unsigned char c;

	c = argv[1][0];
	write(1, &c, 1);
	write(1, "\n", 1);
	c = swap_bits(c);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}
*/
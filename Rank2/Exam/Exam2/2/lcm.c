/* ********************************************************** */
/*                                                            */
/*                              LCM                           */
/*                                                            */
/*   Computes the Lowest Common Multiple (LCM) of two         */
/*   non-zero unsigned integers. If either is 0, returns 0.   */
/*                                                            */
/*   LCM(a, b) = (a / GCD(a, b)) * b                          */
/*                                                            */
/* ********************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Computes the Greatest Common Divisor (GCD) of two unsigned integers
unsigned int	gcd(unsigned int a, unsigned int b) {
	unsigned int	tmp;

	while (b != 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}

// Computes the Lowest Common Multiple (LCM) of two unsigned integers
unsigned int	lcm(unsigned int a, unsigned int b) {
	if (a == 0 || b == 0)
		return (0);
	return ((a * b) / gcd(a, b));
	// return (a / gcd(a, b) * b); // Equivalent
}

int	main(int argc, char **argv)
{
    if (argc == 3)
    {
        unsigned int a = atoi(argv[1]);
        unsigned int b = atoi(argv[2]);
        printf("%d\n", lcm(a, b));
    }
    return (0);
}
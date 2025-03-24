// Expected files   : lcm.c
// Allowed functions:
// --------------------------------------------------------------------------------
//
// Write a function who takes two unsigned int as parameters and  
// returns the computed LCM of those parameters.
//
// LCM (Lowest Common Multiple) of two non-zero integers is 
// the smallest postive integer divisible by the both integers.

// Bruteforce solution
unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);

	unsigned int n;
	if (a > b)
		n = a;
	else
		n = b;

	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		++n;
	}
}

// HCF (Highest Common Factor) solution
unsigned int	hcf(unsigned int a, unsigned int b)
{
	unsigned int	tmp;

	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}

unsigned int	lcm_hcf(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return ((a * b) / ft_hcf(a, b));
}

/*
#include <stdio.h>

int main(void)
{
    printf("%u\n", lcm(0, 5));
	printf("%u\n", lcm_hcf(0, 5));
}
*/

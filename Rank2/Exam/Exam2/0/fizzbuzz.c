/* ******************************************************** */
/*                                                          */
/*                    FIZZBUZZ                              */
/*                                                          */
/*   Prints numbers from 1 to 100 to standard output.       */
/*   Multiples of 3 are replaced by "fizz", multiples       */
/*   of 5 by "buzz", and multiples of both by "fizzbuzz".   */
/*                                                          */
/*   Usage:                                                 */
/*       ./fizzbuzz                                         */
/*                                                          */
/*   Output:                                                */
/*       1                                                  */
/*       2                                                  */
/*       fizz                                               */
/*       ...                                                */
/*                                                          */
/* ******************************************************** */

#include <unistd.h>

// Outputs a single digit character.
void    ft_putchar(char c) {
    write(1, &c, 1);
}

// Recursively prints an integer to standard output.
void    ft_putnbr(int n) {
    if (n > 9)
        ft_putnbr(n / 10);
    ft_putchar(n % 10 + '0');
}

// Program entry point.
int main(void) {
    int n = 1;
    while (n <= 100) {
        if (n % 3 == 0 && n % 5 == 0)
            write(1, "fizzbuzz\n", 9);
        else if (n % 3 == 0)
            write(1, "fizz\n", 5);
        else if (n % 5 == 0)
            write(1, "buzz\n", 5);
        else {
            ft_putnbr(n);
            ft_putchar('\n');
        }
        n++;
    }
    return (0);
}

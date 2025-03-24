/* ************************************************************** */
/*                                                                */
/*                           TAB_MULT                             */
/*                                                                */
/*   Displays the multiplication table for a given number.        */
/*   The table shows multiplication results for numbers 1 to 9,   */
/*   in the format: "i x n = result".                             */
/*                                                                */
/*   Usage:                                                       */
/*       ./tab_mult 5                                             */
/*                                                                */
/*   Example Output:                                              */
/*       1 x 5 = 5                                                */
/*       2 x 5 = 10                                               */
/*       ...                                                      */
/*       9 x 5 = 45                                               */
/*                                                                */
/* ************************************************************** */

#include <unistd.h>

// Converts a string to an integer.
int ft_atoi(char *str) {
    int n = 0;
    // Process each digit in the string.
    while (*str >= '0' && *str <= '9') {
        n *= 10;
        n += *str - '0';
        str++;
    }
    return (n);
}

// Recursively prints an integer to standard output.
void ft_putnbr(int n) {
    if (n >= 10)
        ft_putnbr(n / 10);
    char c = (n % 10) + '0';
    write(1, &c, 1);
}

// Displays the multiplication table for the given number.
void tab_mult(char *str) {
    int n = ft_atoi(str);
    // Loop from 1 to 9.
    for (int i = 1; i <= 9; i++) {
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(n);
        write(1, " = ", 3);
        ft_putnbr(i * n);
        write(1, "\n", 1);
    }
}

int main(int argc, char **argv) {
    // If exactly one argument is provided, display the multiplication table.
    if (argc == 2)
        tab_mult(argv[1]);
    else
        write(1, "\n", 1);
    return (0);
}
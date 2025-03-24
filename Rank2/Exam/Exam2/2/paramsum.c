/* ********************************************************** */
/*                                                            */
/*                         PARAMSUM                           */
/*                                                            */
/*   Prints the number of parameters passed to the program,   */
/*   excluding the program name.                              */
/*                                                            */
/*   Usage:                                                   */
/*       ./paramsum "Hello" "world"                           */
/*                                                            */
/*   Example Output:                                          */
/*       2                                                    */
/*                                                            */
/* ********************************************************** */

#include <unistd.h>

void ft_putnbr(int n) {
    // Recursively print digits if n has more than one digit.
    if (n >= 10)
        ft_putnbr(n / 10);
    
    // Calculate the current digit and print it.
    char digit = (n % 10) + '0';
    write(1, &digit, 1);
}

int main(int argc, char **argv) {
    (void)argv; // Silence unused parameter warning.
    
    // Print (argc - 1), which represents the number of arguments provided.
    ft_putnbr(argc - 1);
    write(1, "\n", 1);
    
    return (0);
}
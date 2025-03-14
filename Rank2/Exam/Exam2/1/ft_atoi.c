/* ********************************************************** */
/*                                                            */
/*                          FT_ATOI                           */
/*                                                            */
/*   Converts a string to an integer.                         */
/*   Ignores leading whitespace characters and                */
/*   handles an optional '+' or '-' sign.                     */
/*   The conversion stops at the first non-digit character.   */
/*                                                            */
/*   Usage:                                                   */
/*       ./ft_atoi "  -12345"                                 */
/*                                                            */
/*   Example Output:                                          */
/*       ft_atoi("  -12345") = -12345                         */
/*                                                            */
/* ********************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Converts a string to an integer.
int ft_atoi(const char *str) {
    int i = 0;
    int sig = 1;
    int res = 0;

    // Skip all leading whitespace characters.
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
           str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;

    // Check for an optional sign.
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sig= -1;
        i++;
    }

    // Convert numeric characters into an integer value.
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sig);
}

int main(int argc, char **argv) {
    // Assume that an argument is provided and print the conversion result.
    printf("ft_atoi(\"%s\") = %d\n", argv[1], ft_atoi(argv[1]));
    // Compare the result with the standard library atoi function.
    printf("atoi(\"%s\") = %d\n", argv[1], atoi(argv[1]));
    return (0);
}
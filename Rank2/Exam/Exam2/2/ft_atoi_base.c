/* *********************************************************** */
/*                                                             */
/*                        FT_ATOI_BASE                         */
/*                                                             */
/*   Converts a string representing a number in a given base   */
/*   to an integer. Handles optional leading whitespace,       */
/*   a sign, and valid digits for the given base.              */
/*                                                             */
/*   Usage:                                                    */
/*       ./ft_atoi_base "1010" 2                               */
/*                                                             */
/*   Example Output:                                           */
/*       10                                                    */
/*                                                             */
/* *********************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Returns 1 if the character is a whitespace (ASCII <= 32), 0 otherwise.
int is_blank(char c) {
    if (c <= 32)
        return (1);
    return (0);
}

// Returns 1 if the character c is a valid digit for the given base, 0 otherwise.
int is_valid(char c, int base) {
    char digits[17] = "0123456789abcdef";
    char digits2[17] = "0123456789ABCDEF";
    
    while (base--)
        if (digits[base] == c || digits2[base] == c)
            return (1);
    return (0);
}

// Returns the numeric value of the character c.
int value_of(char c) {
    if (c >= '0' && c <= '9')
        return (c - '0');
    else if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    else if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (0);
}

// Converts a string in a given base to an integer.
int ft_atoi_base(const char *str, int str_base) {
    int result = 0;
    
    // Skip leading whitespace.
    while (is_blank(*str))
        str++;
    // Set sign.
    int sign = (*str == '-') ? -1 : 1;
    if (*str == '-' || *str == '+')
        ++str;
    // Convert valid digits.
    while (is_valid(*str, str_base))
        result = result * str_base + value_of(*str++);
    return (result * sign);
}

int main(int argc, char **argv) {
    if (argc == 3)
        printf("%d\n", ft_atoi_base(argv[1], atoi(argv[2])));
    return (0);
}
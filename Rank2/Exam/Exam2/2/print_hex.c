/* **************************************************************** */
/*                                                                  */
/*                           PRINT_HEX                              */
/*                                                                  */
/*   Converts a decimal number (provided as a string) to its        */
/*   hexadecimal representation and prints it to standard output.   */
/*                                                                  */
/*   Usage:                                                         */
/*       ./print_hex 255                                            */
/*                                                                  */
/*   Example Output:                                                */
/*       ff                                                         */
/*                                                                  */
/* **************************************************************** */

#include <unistd.h>

int ft_atoi(char *str) {
    int n = 0;
    
    // Convert the string to an integer.
    while (*str) {
        n *= 10;
        n += *str - '0';
        str++;
    }
    return n;
}

void print_hex(int n) {
    char hex_digits[] = "0123456789abcdef";
    
    // Recursively print the hexadecimal representation.
    if (n >= 16)
        print_hex(n / 16);
    write(1, &hex_digits[n % 16], 1);
}

int main(int argc, char **argv) {
    if (argc == 2)
        print_hex(ft_atoi(argv[1]));
    write(1, "\n", 1);
    return (0);
}
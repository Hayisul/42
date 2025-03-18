/* **************************************************************** */
/*                                                                  */
/*                              FPRIME                              */
/*                                                                  */
/*   Displays the prime factorization of a given positive number.   */
/*   The factors are printed in increasing order,                   */
/*   with a '*' character between factors.                          */
/*   If the input is 1, prints "1".                                 */
/*                                                                  */
/*   Usage:                                                         */
/*       ./fprime 12                                                */
/*                                                                  */
/*   Example Output:                                                */
/*       2*2*3                                                      */
/*                                                                  */
/* **************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void fprime(char *str) {
    int n = atoi(str);
    int factor = 2;
    int first = 1;  // Flag to indicate if it's the first factor printed.

    // If the number is 1, print 1 and return.
    if (n == 1) {
        printf("1");
        return;
    }
    
    // Iterate over potential factors.
    while (factor <= n) {
        // If factor divides n evenly, print it.
        if (n % factor == 0) {
            // Print a '*' separator if this isn't the first factor.
            if (!first)
                printf("*");
            printf("%d", factor);
            first = 0;
            // Divide n by the current factor.
            n /= factor;
        }
        else
            factor++;
    }
}

int main(int argc, char **argv) {
    // Proceed only if exactly one argument is provided.
    if (argc == 2)
        fprime(argv[1]);

    // Print a newline at the end.
    printf("\n");
    return (0);
}
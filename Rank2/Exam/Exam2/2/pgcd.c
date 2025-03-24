/* *************************************************************** */
/*                                                                 */
/*                              PGCD                               */
/*                                                                 */
/*   Computes the greatest common divisor (GCD) of two integers.   */
/*   The GCD is printed to standard output.                        */
/*                                                                 */
/*   Usage:                                                        */
/*       ./pgcd 15 20                                              */
/*                                                                 */
/*   Example Output:                                               */
/*       5                                                         */
/*                                                                 */
/* *************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Computes the greatest common divisor (GCD) of two integers.
void pgcd(int a, int b) {
    int n = (a < b) ? a : b;  // Set n to the smaller of a and b.
    
    while (n > 0) {
        if (a % n == 0 && b % n == 0) {
            printf("%d", n);
            return;
        }
        n--;
    }
}

int main(int argc, char **argv) {
    if (argc == 3)
        pgcd(atoi(argv[1]), atoi(argv[2]));
    printf("\n");
    return (0);
}
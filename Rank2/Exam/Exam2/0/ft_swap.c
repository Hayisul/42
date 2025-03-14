/* ************************************************** */
/*                                                    */
/*                        FT_SWAP                     */
/*                                                    */
/*   Swaps the values of two integers.                */
/*   Demonstrates pointer usage in C by swapping      */
/*   two variables using a dedicated swap function.   */
/*                                                    */
/*   Usage:                                           */
/*       ./ft_swap                                    */
/*                                                    */
/*   Output:                                          */
/*       Before swap: n1 = 9 and n2 = 6.              */
/*       After swap: n1 = 6 and n2 = 9.               */
/*                                                    */
/* ************************************************** */

#include <stdio.h>

// Swaps the values of two integers pointed by a and b.
void ft_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int n1 = 9;
    int n2 = 6;

    // Print the initial values.
    printf("Before swap: n1 = %d and n2 = %d.\n", n1, n2);

    // Swap the values.
    ft_swap(&n1, &n2);

    // Print the swapped values.
    printf("After swap: n1 = %d and n2 = %d.\n", n1, n2);

    return 0;
}

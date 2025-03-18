/* ******************************************************* */
/*                                                         */
/*                      SORT_INT_TAB                       */
/*                                                         */
/*   Sorts an integer array using bubble sort algorithm.   */
/*   The array is sorted in increasing order.              */
/*                                                         */
/*   Usage:                                                */
/*       ./sort_int_tab                                    */
/*                                                         */
/*   Example Output:                                       */
/*       Before sorting: 5 3 8 1 9 2 7 4 6                 */
/*       After sorting:  1 2 3 4 5 6 7 8 9                 */
/*                                                         */
/* ******************************************************* */

#include <stdio.h>

// Swaps the values of two integers.
void swap_values(int *a, int *b) {
    int swap = *a;
    *a = *b;
    *b = swap;
}

// Sorts the integer array 'tab' of size 'size' using bubble sort.
void sort_int_tab(int *tab, unsigned int size) {
    int swapped; // Flag to indicate if a swap occurred.
    
    do {
        swapped = 0;
        for (unsigned int i = 0; i < size - 1; i++) {
            if (tab[i] > tab[i + 1]) {
                swap_values(&tab[i], &tab[i + 1]);
                swapped = 1;
            }
        }
    } while (swapped);
}

int main(void) {
    int tab[] = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    unsigned int size = sizeof(tab) / sizeof(tab[0]);

    // Print array before sorting.
    printf("Before sorting: ");
    for (unsigned int i = 0; i < size; i++)
        printf("%d ", tab[i]);
    printf("\n");

    // Sort the array.
    sort_int_tab(tab, size);

    // Print array after sorting.
    printf("After sorting:  ");
    for (unsigned int i = 0; i < size; i++)
        printf("%d ", tab[i]);
    printf("\n");

    return (0);
}

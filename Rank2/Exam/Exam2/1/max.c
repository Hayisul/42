/* ************************************************************ */
/*                                                              */
/*                             MAX                              */
/*                                                              */
/*   Returns the maximum value found in an array of integers.   */
/*   If the array is empty (len == 0), returns 0.               */
/*                                                              */
/*   Usage:                                                     */
/*       ./max                                                  */
/*                                                              */
/*   Example Output:                                            */
/*       Max of arr1: 8                                         */
/*       Max of arr2: 50                                        */
/*       Max of arr3: -1                                        */
/*       Max of arr4: 42                                        */
/*       Max of arr5: 0                                         */
/*                                                              */
/* ************************************************************ */

#include <stdio.h>

// Returns max value in ‘tab’ of length ‘len’, or 0 if empty.
int max(int *tab, unsigned int len) {
    if (len == 0)
        return (0);
    int res = tab[0];
    // Find the maximum value.
    for (unsigned int i = 0; i < len; i++) {
        if (res < tab[i])
            res = tab[i];
    }
    return (res);
}

int main(void) {
    int arr1[] = {3, 5, 2, 8, 4};
    int arr2[] = {10, 20, 30, 40, 50};
    int arr3[] = {-3, -7, -2, -8, -1};
    int arr4[] = {42};
    int arr5[] = {};

    printf("Max of arr1: %d\n", max(arr1, 5));
    printf("Max of arr2: %d\n", max(arr2, 5));
    printf("Max of arr3: %d\n", max(arr3, 5));
    printf("Max of arr4: %d\n", max(arr4, 1));
    printf("Max of arr5: %d\n", max(arr5, 0));

    return (0);
}
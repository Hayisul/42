// Expected files   : max.c
// Allowed functions: None
//  --------------------------------------------------------------------------------
//
// Write a function with an array of int as first parameter
// and the number of elements as second parameter.
//
// The function returns the largest number found in the array.
//
// If the array is empty, the function returns 0.

int max(int* tab, unsigned int len)
{
    if (len == 0)
        return (0);
    int res = tab[0];
    for (unsigned int i = 0; i < len; i++)
    {
        if (res < tab[i])
            res = tab[i];
    }
    return (res);
}

/*
#include <stdio.h>

int main(void)
{
    int arr1[] = {3, 5, 2, 8, 4};
    int arr2[] = {10, 20, 30, 40, 50};
    int arr3[] = {-3, -7, -2, -8, -1};
    int arr4[] = {42};
    int arr5[] = {};  // Empty array

    printf("Max of arr1: %d\n", max(arr1, 5));  // Expected: 8
    printf("Max of arr2: %d\n", max(arr2, 5));  // Expected: 50
    printf("Max of arr3: %d\n", max(arr3, 5));  // Expected: -1
    printf("Max of arr4: %d\n", max(arr4, 1));  // Expected: 42
    printf("Max of arr5: %d\n", max(arr5, 0));  // Expected: 0

    return 0;
}
*/
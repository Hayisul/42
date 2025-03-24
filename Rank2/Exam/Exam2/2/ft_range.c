/* *********************************************************** */
/*                                                             */
/*                          FT_RANGE                           */
/*                                                             */
/*   Allocates an array of integers filled with consecutive    */
/*   values from start to end (inclusive), then returns a      */
/*   pointer to the first element of the array.                */
/*                                                             */
/*   Usage:                                                    */
/*       ./ft_range 5 10                                       */
/*                                                             */
/*   Example Output:                                           */
/*       5 6 7 8 9 10                                          */
/*                                                             */
/* *********************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Returns an array of values from start to end.
int *ft_range(int start, int end) {
    // Determine the size of the array.
    int size = ((end - start) < 0 ? (start - end) : (end - start)) + 1;
    int *res = malloc(size * sizeof(int));
    if (!res)
        return (NULL);
    int i = 0;
    // Fill the array with values from start to end.
    if (start <= end) {
        while (start <= end) {
            res[i] = start;
            start++;
            i++;
        }
    }
    // Fill the array with values from end to start.
    else {
        while (start >= end) {
            res[i] = start;
            start--;
            i++;
        }
    }
    return (res);
}

int main(int argc, char **argv) {
    if (argc == 3) {
        int start = atoi(argv[1]);
        int end = atoi(argv[2]);
        int *range = ft_range(start, end);
        if (range) {
            int size = ((end - start) < 0 ? (start - end) : (end - start)) + 1;
            for (int i = 0; i < size; i++)
                printf("%d ", range[i]);
            printf("\n");
            free(range);
        }
    }
    return (0);
}

/* ******************************************************** */
/*                                                          */
/*                        FT_RRANGE                         */
/*                                                          */
/*   Allocates an array of integers containing all values   */
/*   between start and end (inclusive), in reverse order.   */
/*                                                          */
/*   Usage:                                                 */
/*       ./ft_rrange 5 2                                    */
/*                                                          */
/*   Example Output:                                        */
/*       2 3 4 5                                            */
/*                                                          */
/* ******************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Returns the absolute value of an integer.
int absolute_value(int n) {
    return (n < 0 ? -n : n);
}

// Returns an array of values from start to end, in reverse order.
int *ft_rrange(int start, int end) {
    int step;
    int size = 1 + absolute_value(end - start);
    int *array = malloc(sizeof(int) * size);
    
    if (!array)
        return NULL;
    
    // If start is greater than end, count up; else, count down.
    if (start > end)
        step = 1;
    else
        step = -1;
    
    int i = 0;
	// Fill the array with values from end to start.
    while (i < size) {
        array[i] = end;
        end += step;
        i++;
    }
    return array;
}

int main(int argc, char **argv) {
    if (argc == 3) {
        int start = atoi(argv[1]);
        int end = atoi(argv[2]);
        int size = 1 + absolute_value(end - start);
        int *range = ft_rrange(start, end);
        if (!range)
            return 1;
        // Print the resulting array with spaces between numbers.
        for (int i = 0; i < size; i++) {
            printf("%d", range[i]);
            if (i < size - 1)
                printf(" ");
        }
        printf("\n");
        free(range);
    }
    return (0);
}
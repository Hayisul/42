/* *************************************************************** */
/*                                                                 */
/*                             FT_ITOA                             */
/*                                                                 */
/*   Converts an integer to its string representation.             */
/*   Handles negative numbers and zero.                            */
/*   Allocates memory for the resulting string dynamically;        */
/*   the caller is responsible for freeing the allocated memory.   */
/*                                                                 */
/*   Usage:                                                        */
/*       ./ft_itoa <number>                                        */
/*                                                                 */
/*   Example Output:                                               */
/*       Input: 123, Output: "123"                                 */
/*                                                                 */
/* *************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Returns the absolute value of an integer.
int absolute_value(int nbr) {
    if (nbr < 0)
        return (-nbr);
    return (nbr);
}

// Calculates the length of the string representation of an integer.
int get_len(int nbr) {
    int len = 0;
    // For negative numbers or zero, we need an extra space.
    if (nbr <= 0)
        len++;
    while (nbr) {
        len++;
        nbr /= 10;
    }
    return (len);
}

// Converts an integer to its string representation.
char *ft_itoa(int nbr) {
    long num = nbr;
    int len = get_len(nbr);
    // Allocate memory for the resulting string.
    char * result = malloc(sizeof(char) * (len + 1));

    // Handle allocation failure.
    if (!result)
        return (NULL);
    
    // Null-terminate the string.
    result[len] = '\0';
    
    // Handle negative numbers.
    if (nbr < 0) {
        result[0] = '-';
        num = -num;
    }
    // Handle zero explicitly.
    else if (nbr == 0) {
        result[0] = '0';
    }
    
    // Build the string representation from the end.
    while (num) {
        result[--len] = (num % 10) + '0';
        num /= 10;
    }
    return (result);
}

int main(int argc, char **argv) {
    if (argc == 2) {
        int num = atoi(argv[1]);
        char *str1 = ft_itoa(num);

        // Print the result from ft_itoa.
        printf("%s\n", str1);
        free(str1);
    }
    return (0);
}

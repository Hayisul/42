/* ********************************************************** */
/*                                                            */
/*                         FT_STRDUP                          */
/*                                                            */
/*   Duplicates a string by allocating memory for the copy,   */
/*   and returns a pointer to the newly allocated string,     */
/*   or NULL on failure.                                      */
/*                                                            */
/*   Usage:                                                   */
/*       ./ft_strdup "Hello"                                  */
/*                                                            */
/*   Example Output:                                          */
/*       ft_strdup("Hello") = Hello                           */
/*                                                            */
/* ********************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Allocates and returns a duplicate of the given string, or NULL on failure.
char *ft_strdup(char *src) {
    int i = 0;
    
    // Determine the length of the source string.
    while (src[i] != '\0')
        i++;
    
    // Allocate memory for the duplicate string, including the null terminator.
    char *dest = malloc(sizeof(char) * (i + 1));
    if (dest == NULL)
        return (NULL);
    
    i = 0;
    // Copy each character from the source string to the destination.
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    // Append the null terminator.
    dest[i] = src[i];
    return (dest);
}

int main(int argc, char **argv) {
    // If no argument is provided, duplicate an empty string.
    if (argc == 1) {
        printf("ft_strdup(\"\") = %s\n", ft_strdup(""));
        // Compare with the standard library strdup function.
        printf("strdup(\"\") = %s\n", strdup(""));
        return (0);
    }
    // Otherwise, duplicate the provided string.
    printf("ft_strdup(\"%s\") = %s\n", argv[1], ft_strdup(argv[1]));
    // Compare with the standard library strdup function.
    printf("strdup(\"%s\") = %s\n", argv[1], strdup(argv[1]));
    return (0);
}

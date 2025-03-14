/* ****************************************************** */
/*                                                        */
/*                       FT_STRCMP                        */
/*                                                        */
/*   Compares two strings lexicographically.              */
/*   Returns an integer less than, equal to,              */
/*   or greater than zero if s1 is found, respectively,   */
/*   to be less than, to match, or be greater than s2.    */
/*                                                        */
/*   Usage:                                               */
/*       ./ft_strcmp "string1" "string2"                  */
/*                                                        */
/*   Example Output:                                      */
/*       ft_strcmp("abc", "abd") = -1                     */
/*                                                        */
/* ****************************************************** */

#include <stdlib.h>
#include <stdio.h>

// Compares two strings and returns the difference between the first
// pair of differing characters (interpreted as unsigned char values).
int ft_strcmp(char *s1, char *s2) {
    int i = 0;
    
    // Iterate over both strings while characters match and neither string ends.
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    
    // Return the difference of the first mismatching characters.
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main(int argc, char **argv) {
    // Proceed only if exactly two arguments are provided.
    if (argc == 3)
        printf("ft_strcmp(\"%s\", \"%s\") = %d\n",
               argv[1], argv[2], ft_strcmp(argv[1], argv[2]));
    return (0);
}

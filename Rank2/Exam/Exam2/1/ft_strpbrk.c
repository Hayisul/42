/* ******************************************************* */
/*                                                         */
/*                       FT_STRPBRK                        */
/*                                                         */
/*   Locates the first occurrence in the string 's1'       */
/*   of any of the characters in the string 's2'.          */
/*   Returns a pointerto the matching character in 's1',   */
/*   or NULL if no match is found.                         */
/*                                                         */
/*   Usage:                                                */
/*       ./ft_strpbrk                                      */
/*                                                         */
/*   Example:                                              */
/*       Input: "hello, world", "aeiou"                    */
/*       Output: First matching character: e               */
/*                                                         */
/* ******************************************************* */

#include <stdio.h>

// Searches for the first occurrence in 's1' of any character from 's2'.
// Returns a pointer to the matching character in 's1', or NULL if no match is found.
char *ft_strpbrk(const char *s1, const char *s2) {
    int i = 0;

    if (!s1 || !s2)
        return (NULL);
    // Iterate over each character in s1.
    while (*s1) {
        i = 0;
        // Check each character in s2 against the current character in s1.
        while (s2[i]) {
            if (*s1 == s2[i])
                return ((char *)s1);
            i++;
        }
        s1++;
    }
    return (NULL);
}

int main(void) {
    char str[] = "hello, world";
    char chars[] = "aeiou";

    // Test ft_strpbrk using the sample strings.
    char *result = ft_strpbrk(str, chars);
    if (result)
        printf("First matching character: %c\n", *result);
    else
        printf("No matching character found.\n");
    
    return (0);
}
/* ********************************************************** */
/*                                                            */
/*                          FT_STRSPN                         */ 
/*                                                            */
/*   Computes the length of the initial segment of a string   */
/*   that consists entirely of accepted characters.           */
/*                                                            */
/*   Usage:                                                   */
/*       ./ft_strspn                                          */
/*                                                            */
/*   Example Output:                                          */
/*       ft_strspn("hello", "he") returns 2                   */
/*       ft_strspn("hello", "abc") returns 0                  */
/*       ft_strspn("hello", "lohe") returns 5                 */
/*       ft_strspn("hello", "") returns 0                     */
/*       ft_strspn("", "abc") returns 0                       */
/*                                                            */
/* ********************************************************** */

#include <stdio.h>
#include <stddef.h>

// Returns length of s’s initial segment containing only accepted characters.
size_t ft_strspn(const char *s, const char *accept) {
    size_t i = 0;
    size_t count = 0;

    // Iterate over each character in s.
    while (*s) {
        // Check if the current character in s is present in accept.
        while (accept[i] && *s != accept[i])
            i++;
        // If no matching character is found in accept, return the count.
        if (accept[i] == '\0')
            return (count);
        // Reset index for accept, increment count, and move to the next character in s.
        i = 0;
        count++;
        s++;
    }
    return (count);
}

// Main function for demonstrating ft_strspn usage.
int main(void) {
    printf("%zu\n", ft_strspn("hello", "he"));
    printf("%zu\n", ft_strspn("hello", "abc"));
    printf("%zu\n", ft_strspn("hello", "lohe"));
    printf("%zu\n", ft_strspn("hello", ""));
    printf("%zu\n", ft_strspn("", "abc"));
    return (0);
}
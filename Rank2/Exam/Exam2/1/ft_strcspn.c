/* ********************************************************** */
/*                                                            */
/*                      FT_STRCSPN                            */
/*                                                            */
/*   Computes the length of the initial segment of a string   */
/*   containing no reject characters.                         */
/*                                                            */
/*   Usage:                                                   */
/*       ./ft_strcspn                                         */
/*                                                            */
/*   Example Output:                                          */
/*       1                                                    */
/*       1                                                    */
/*       4                                                    */
/*       4                                                    */
/*                                                            */
/* ********************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

// Returns length of s’s initial segment containing no reject characters.
size_t ft_strcspn(const char *s, const char *reject) {
    size_t i = 0;
    size_t j;

    // Iterate through each character in 's'.
    while (s[i]) {
        j = 0;
        // Check if the current character s[i] is present in 'reject'.
        while (reject[j]) {
            if (s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}

int main(void) {
    // Compare ft_strcspn with the standard library strcspn.
    printf("%lu\n", ft_strcspn("test", "es"));
    printf("%lu\n", strcspn("test", "es"));
    printf("%lu\n", ft_strcspn("test", "f"));
    printf("%lu\n", strcspn("test", "f"));
    return (0);
}

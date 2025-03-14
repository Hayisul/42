/* *********************************************** */
/*                                                 */
/*                     FT_STRREV                   */
/*                                                 */
/*   Reverses the given string in-place.           */
/*   Swaps characters from the beginning and end   */
/*   until the entire string is reversed.          */
/*                                                 */
/*   Usage:                                        */
/*       ./ft_strrev                               */
/*                                                 */
/*   Example Output:                               */
/*       Original: hello | Reversed: olleh         */
/*       Original: world! | Reversed: !dlrow       */
/*       Original:  | Reversed:                    */
/*       Original: a | Reversed: a                 */
/*                                                 */
/* *********************************************** */

#include <stdio.h>

// Reverses the string 'str' in-place and returns it.
char *ft_strrev(char *str) {
    int i = 0;
    int len = 0;
    char temp;

    // Calculate the length of the string.
    while (str[len])
        len++;

    // Swap characters from the beginning and end until the middle is reached.
    while (i < len / 2) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
        i++;
    }
    return (str);
}

// Main function for demonstrating ft_strrev usage.
int main(void) {
    char str[] = "Hello, World!";

    printf("Original: %s\n", str);
    printf("Reversed: %s\n", ft_strrev(str));
    return (0);
}

/* ************************************************* */
/*                                                   */
/*                      INTER                        */
/*                                                   */
/*   Prints the characters from the first string     */
/*   that are present in the second string.          */
/*   Each character is printed only once,            */
/*   in the order they appear in the first string.   */
/*                                                   */
/*   Usage:                                          */
/*       ./inter "abcdef" "adafee"                   */
/*                                                   */
/*   Example Output:                                 */
/*       adef                                        */
/*                                                   */
/* ************************************************* */

#include <unistd.h>

// Returns 1 if ‘c’ appears in ‘str’ before ‘pos’, otherwise 0.
int already_printed(char *str, char c, int pos) {
    int i = 0;
    while (i < pos) {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int main(int argc, char **argv) {
    // Proceed only if exactly two arguments are provided.
    if (argc == 3) {
        char *s1 = argv[1];
        char *s2 = argv[2];
        int i = 0;

        // Iterate over each character in s1.
        while (s1[i]) {
            // Check if the character has not been printed before.
            if (!already_printed(s1, s1[i], i)) {
                int j = 0;
                // Check if the current character in s1 exists in s2.
                while (s2[j]) {
                    if (s1[i] == s2[j]) {
                        // Print the character once if a match is found.
                        write(1, &s1[i], 1);
                        break;
                    }
                    j++;
                }
            }
            i++;
        }
    }
    // Print a newline at the end.
    write(1, "\n", 1);
    return (0);
}
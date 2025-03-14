/* *********************************************************** */
/*                                                             */
/*                        ALPHA_MIRROR                         */
/*                                                             */
/*   Replaces each alphabetical character with its mirror      */
/*   in the alphabet. Lowercase letters are transformed so     */
/*   that 'a' becomes 'z', 'b' becomes 'y', etc. Uppercase     */
/*   letters are similarly transformed: 'A' becomes 'Z',       */
/*   'B' becomes 'Y', and so on. Non-alphabetical characters   */
/*   remain unchanged.                                         */
/*                                                             */
/*   Usage:                                                    */
/*       ./alpha_mirror "Hello, World!"                        */
/*                                                             */
/*   Example Output:                                           */
/*       Svool, Dliow!                                         */
/*                                                             */
/* *********************************************************** */

#include <unistd.h>

int main(int argc, char **argv) {
    // Proceed only if exactly one argument is provided.
    if (argc == 2) {
        int i = 0;
        char c;
        char *str = argv[1];

        // Iterate over each character in the input string.
        while (str[i]) {
            // If the character is a lowercase letter, mirror it.
            if (str[i] >= 'a' && str[i] <= 'z')
                c = 'z' - (str[i] - 'a');
            // Else if the character is an uppercase letter, mirror it.
            else if (str[i] >= 'A' && str[i] <= 'Z')
                c = 'Z' - (str[i] - 'A');
            // For all other characters, leave them unchanged.
            else
                c = str[i];
            // Write the transformed character to standard output.
            write(1, &c, 1);
            i++;
        }
    }
    // Print a newline at the end.
    write(1, "\n", 1);
    return (0);
}
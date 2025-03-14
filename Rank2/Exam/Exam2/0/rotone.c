/* ******************************************************** */
/*                                                          */
/*                         ROTONE                           */
/*                                                          */
/*   Shifts each alphabetical character by one position     */
/*   in the alphabet, wrapping 'z' to 'a' and 'Z' to 'A'.   */
/*   Non-alphabetical characters remain unchanged.          */
/*                                                          */
/*   Usage:                                                 */
/*       ./rotone "Hello, World!"                           */
/*                                                          */
/*   Example Output:                                        */
/*       Ifmmp, Xpsme!                                      */
/*                                                          */
/* ******************************************************** */

#include <unistd.h>

int main(int argc, char **argv) {
    // Proceed only if exactly one argument is provided.
    if (argc == 2) {
        int i = 0;
        char c;
        char *str = argv[1];

        // Iterate over each character in the string.
        while (str[i]) {
            // If character is between 'a' and 'y' or 'A' and 'Y', add 1.
            if ((str[i] >= 'a' && str[i] <= 'y') || (str[i] >= 'A' && str[i] <= 'Y'))
                c = str[i] + 1;
            // If character is 'z' or 'Z', subtract 25 to wrap around.
            else if (str[i] == 'z' || str[i] == 'Z')
                c = str[i] - 25;  // 'z' -> 'a', 'Z' -> 'A'
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

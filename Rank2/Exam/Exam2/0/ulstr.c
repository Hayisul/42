/* **************************************************** */
/*                                                      */
/*                         ULSTR                        */
/*                                                      */
/*   Converts each alphabetical character in a string   */
/*    to the opposite case: lowercase letters           */
/*   become uppercase and uppercase become lowercase.   */
/*   Non-alphabetical characters remain unchanged.      */
/*                                                      */
/*   Usage:                                             */
/*       ./ulstr "Hello, World!"                        */
/*                                                      */
/*   Example Output:                                    */
/*       hELLO, wORLD!                                  */
/*                                                      */
/* **************************************************** */

#include <unistd.h>

int main(int argc, char **argv) {
    // Proceed only if exactly one argument is provided.
    if (argc == 2) {
        int i = 0;
        char c;
        char *str = argv[1];

        // Iterate over each character in the string.
        while (str[i]) {
            // If character is a lowercase letter, convert to uppercase.
            if (str[i] >= 'a' && str[i] <= 'z')
                c = str[i] - 32;
            // Else if character is an uppercase letter, convert to lowercase.
            else if (str[i] >= 'A' && str[i] <= 'Z')
                c = str[i] + 32;
            // Otherwise, leave the character unchanged.
            else
                c = str[i];
            // Write the toggled character to standard output.
            write(1, &c, 1);
            i++;
        }
    }
    // Print a newline at the end.
    write(1, "\n", 1);
    return (0);
}
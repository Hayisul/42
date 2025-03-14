/* *********************************************************** */
/*                                                             */
/*                          ROT_13                             */
/*                                                             */
/*   Encodes a given string using the ROT13 cipher.            */
/*   Each alphabetical character is replaced by the            */
/*   character 13 positions ahead in the alphabet, wrapping    */
/*   around if necessary. Non-alphabetical characters remain   */
/*   unchanged.                                                */
/*                                                             */
/*   Usage:                                                    */
/*       ./rot_13 "Hello, World!"                              */
/*                                                             */
/*   Example Output:                                           */
/*       Uryyb, Jbeyq!                                         */
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
            // If character is between 'a' and 'm' or 'A' and 'M', add 13.
            if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
                c = str[i] + 13;
            // If character is between 'n' and 'z' or 'N' and 'Z', subtract 13.
            else if ((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' && str[i] <= 'Z'))
                c = str[i] - 13;
            // For all other characters, leave them unchanged.
            else
                c = str[i];

            // Output the transformed character.
            write(1, &c, 1);
            i++;
        }
    }
    // Print a newline character at the end of the output.
    write(1, "\n", 1);
    return (0);
}

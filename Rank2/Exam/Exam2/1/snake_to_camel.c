/* ******************************************************** */
/*                                                          */
/*                      SNAKE_TO_CAMEL                      */
/*                                                          */
/*   Converts an underscore-separated string to camelCase   */
/*   by replacing an underscore with the uppercase          */
/*   of the followingcharacter.                             */
/*                                                          */
/*   Usage:                                                 */
/*       ./snake_to_camel "hello_world"                     */
/*                                                          */
/*   Example Output:                                        */
/*       helloWorld                                         */
/*                                                          */
/* ******************************************************** */

#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    // Proceed only if exactly one argument is provided.
    if (argc == 2) {
        // Iterate over each character in the input string.
        for (int i = 0; argv[1][i]; i++) {
            if (argv[1][i] == '_') {
                // Skip the underscore.
                i++;
                // Convert the lowercase letter to uppercase.
                argv[1][i] -= 32;
            }
            // Write the current character to standard output.
            write(1, &argv[1][i], 1);
        }
    }
    // Write a newline at the end.
    write(1, "\n", 1);
    return (0);
}
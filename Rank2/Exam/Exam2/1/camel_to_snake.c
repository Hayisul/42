/* ************************************************************** */
/*                                                                */
/*                         CAMEL_TO_SNAKE                         */
/*                                                                */
/*   Converts a lowerCamelCase string to snake_case.              */
/*   For each uppercase letter in the input string,               */
/*   an underscore is printed before its lowercase counterpart.   */
/*   Other characters remain unchanged.                           */
/*                                                                */
/*   Usage:                                                       */
/*       ./camel_to_snake "HelloWorld"                            */
/*                                                                */
/*   Example Output:                                              */
/*       _hello_world                                             */
/*                                                                */
/* ************************************************************** */

#include <unistd.h>

int main(int argc, char **argv) {
    // Proceed only if exactly one argument is provided.
    if (argc == 2) {
        int i = 0;
        char c;
        char *str = argv[1];

        // Iterate over each character in the input string.
        while (str[i]) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                // Output an underscore.
                write(1, "_", 1);
                // Convert the uppercase letter to lowercase.
                c = str[i] + 32;
            }
            // Otherwise, leave the character unchanged.
            else
                c = str[i];
            // Write the character to standard output.
            write(1, &c, 1);
            i++;
        }
    }
    // Print a newline at the end.
    write(1, "\n", 1);
    return (0);
}
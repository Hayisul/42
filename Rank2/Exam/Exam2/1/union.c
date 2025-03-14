/* ************************************************************ */
/*                                                              */
/*                           UNION                              */
/*                                                              */
/*   Prints the union of the characters found in two strings.   */
/*   Each character is printed only once, in the order of its   */
/*   first appearance in the input arguments.                   */
/*                                                              */
/*   Usage:                                                     */
/*       ./union "hello" "world"                                */
/*                                                              */
/*   Example Output:                                            */
/*       helowrd                                                */
/*                                                              */
/* ************************************************************ */

#include <unistd.h>

int main(int argc, char **argv) {
    if (argc == 3) {
        int ascii[256] = {0};

        // Process both input strings.
        for (int i = 1; i < 3; i++) {
            int j = 0;
            while (argv[i][j]) {
                // If the character hasn't been printed yet, mark it and print it.
                if (ascii[(unsigned char)argv[i][j]] == 0) {
                    ascii[(unsigned char)argv[i][j]] = 1;
                    write(1, &argv[i][j], 1);
                }
                j++;
            }
        }
    }
    // Print a newline at the end.
    write(1, "\n", 1);
    return (0);
}
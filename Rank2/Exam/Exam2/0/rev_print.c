/* ************************************************************ */
/*                                                              */
/*                          REV_PRINT                           */
/*                                                              */
/*   Reverses a string provided as a command line argument.     */
/*   If exactly one argument is given, the program calculates   */
/*   its length and prints the string in reverse order,         */
/*   followed by a newline.                                     */
/*                                                              */
/*   Usage:                                                     */
/*       ./rev_print "Hello"                                    */
/*                                                              */
/*   Example Output:                                            */
/*       olleH                                                  */
/*                                                              */
/* ************************************************************ */

#include <unistd.h>

int main(int argc, char **argv) {
    // Proceed only if exactly one argument is provided.
    if (argc == 2) {
        int i = 0;
        char *str = argv[1];

        // Iterate over each character in the input string.
        while (str[i]) {
            int c = 1;  // Default count for non-alphabetical characters.
            
            // If the character is an uppercase letter, set count based on its position.
            if (str[i] >= 'A' && str[i] <= 'Z')
                c = str[i] - 'A' + 1;
            // Else if the character is a lowercase letter, set count based on its position.
            else if (str[i] >= 'a' && str[i] <= 'z')
                c = str[i] - 'a' + 1;
            
            // Print the current character 'c' times.
            while (c > 0) {
                write(1, &str[i], 1);
                c--;
            }
            i++;
        }
    }
    // Print a newline character after processing.
    write(1, "\n", 1);
    return (0);
}

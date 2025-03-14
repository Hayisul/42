/* ******************************************************** */
/*                                                          */
/*                    SEARCH_AND_REPLACE                    */
/*                                                          */
/*   Searches for a specific character in a string and      */
/*   replaces it with another. Each character of the        */
/*   resulting string is then written to standard output.   */
/*                                                          */
/*   Usage:                                                 */
/*       ./search_and_replace "Hello World" "o" "a"         */
/*                                                          */
/*   Example Output:                                        */
/*       "Hella Warld"                                      */
/*                                                          */
/* ******************************************************** */

#include <unistd.h>

// Replaces all occurrences of character 's' with 'r' in the string,
// and writes each character to standard output.
void search_and_replace(char *str, char s, char r) {
    int i = 0;
    
    // Iterate over each character in the string.
    while (str[i]) {
        // If current character matches the search character, replace it.
        if (str[i] == s)
            str[i] = r;
        // Write the current (possibly replaced) character to standard output.
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv) {
    // Proceed only if exactly three arguments are provided.
    if (argc == 4)
        search_and_replace(argv[1], argv[2][0], argv[3][0]);
    // Print a newline at the end.
    write(1, "\n", 1);
    return (0);
}

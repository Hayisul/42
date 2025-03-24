/* ****************************************************************** */
/*                                                                    */
/*                             EXPAND_STR                             */
/*                                                                    */
/*   Prints the string with exactly three spaces between words.       */
/*   Words are separated by one or more spaces or tabs in the input.  */
/*                                                                    */
/*   Usage:                                                           */
/*       ./expand_str "Hello  world example"                          */
/*                                                                    */
/*   Example Output:                                                  */
/*       Hello   world   example                                      */
/*                                                                    */
/* ****************************************************************** */

#include <unistd.h>

// Returns the length of the word (until a space, tab, or end-of-string).
int word_len(char *str) {
    int i = 0;
    while (str[i] && str[i] != ' ' && str[i] != '\t')
        i++;
    return (i);
}

// Prints the string with exactly three spaces between words.
void expand_str(char *str) {
    int len;
    int first_word = 1;
    
    while (*str) {
        // Skip any leading spaces or tabs.
        while (*str == ' ' || *str == '\t')
            str++;
        len = word_len(str);
        // If not the first word and a word was found, print three spaces.
        if (len > 0 && first_word == 0)
            write(1, "   ", 3);
        first_word = 0;
        // Print the word.
        write(1, str, len);
        // Advance the pointer by the length of the word.
        str += len;
    }
}

int main(int argc, char **argv) {
    if (argc == 2)
        expand_str(argv[1]);
    write(1, "\n", 1);
    return (0);
}
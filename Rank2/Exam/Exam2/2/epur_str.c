/* ***************************************************************** */
/*                                                                   */
/*                             EPUR_STR                              */
/*                                                                   */
/*   Prints the given string with exactly one space between words.   */
/*   Leading and trailing whitespace are removed,                    */
/*   and extra spaces between words are reduced to a single space.   */
/*                                                                   */
/*   Usage:                                                          */
/*       ./epur_str "  Hello   world  this  is   an example "        */
/*                                                                   */
/*   Example Output:                                                 */
/*       Hello world this is an example                              */
/*                                                                   */
/* ***************************************************************** */

#include <unistd.h>

// Skips spaces and tabs starting from index i.
int skip_whitespace(char *str, int i) {
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    return i;
}

// Returns the length of the word starting at index i.
int ft_wordlen(char *str, int i) {
    int len = 0;
    while (str[i] && str[i] != ' ' && str[i] != '\t') {
        len++;
        i++;
    }
    return len;
}

// Prints the string with exactly one space between words.
void epur_str(char *str) {
    int i = 0;
    int first_word = 1;
    
    i = skip_whitespace(str, i);
    while (str[i]) {
        int len = ft_wordlen(str, i);
        if (len > 0) {
            if (!first_word)
                write(1, " ", 1);
            write(1, str + i, len);
            first_word = 0;
        }
        i = skip_whitespace(str, i + len);
    }
}

int main(int argc, char **argv) {
    if (argc == 2)
        epur_str(argv[1]);
    write(1, "\n", 1);
    return 0;
}
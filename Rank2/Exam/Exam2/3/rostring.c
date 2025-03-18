/* ************************************************************* */
/*                                                               */
/*                            ROSTRING                           */
/*                                                               */
/*   Rotates the first word of the provided string to the end.   */
/*   Words are separated by spaces or tabs.                      */
/*   The output consists of the remaining words                  */
/*   followed by the first word.                                 */
/*                                                               */
/*   Usage:                                                      */
/*       ./rostring "  Hello world this is an example"           */
/*                                                               */
/*   Example Output:                                             */
/*       world this is an example Hello                          */
/*                                                               */
/* ************************************************************* */

#include <unistd.h>
#include <stdlib.h>

// Skips spaces and tabs starting at index i and returns the new index.
int skip_whitespace(char *str, int i) {
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    return i;
}

// Returns the length of the word starting at str.
int ft_wordlen(char *str) {
    int i = 0;
    while (str[i] && str[i] != ' ' && str[i] != '\t')
        i++;
    return i;
}

// Prints word starting at str[i]; updates is_first flag; returns index after word.
int print_word(char *str, int i, int *is_first) {
    int word_len;
    
    i = skip_whitespace(str, i);
    word_len = ft_wordlen(str + i);
    if (*is_first == 0)
        write(1, " ", 1);
    write(1, str + i, word_len);
    *is_first = 0;
    return (i + word_len);
}

// Prints all words from str; returns is_first flag (0 if any word printed).
int epur_str(char *str) {
    int i = 0;
    int is_first = 1; // Flag to check if the first word has been printed.
    
    i = skip_whitespace(str, i);
    while (str[i]) {
        i = print_word(str, i, &is_first);
        i = skip_whitespace(str, i);
    }
    return is_first;
}

int main(int argc, char **argv) {
    if (argc == 2) {
        char *str = argv[1];
        int index = 0;
        int first_word_flag;
        
        // Skip the first word.
        index = skip_whitespace(str, index);
        index = index + ft_wordlen(str + index);
        
        // Print the remainder of the string.
        first_word_flag = epur_str(str + index);
        
        // Then print the first word at the end.
        print_word(str, 0, &first_word_flag);
    }
    write(1, "\n", 1);
    return (0);
}

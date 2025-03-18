/* ********************************************* */
/*                                               */
/*                   REV_WSTR                    */
/*                                               */
/*   Prints the words of str in reverse order.   */
/*                                               */
/*   Usage:                                      */
/*       ./rev_wstr "example string"             */
/*                                               */
/*   Example Output:                             */
/*       string example                          */
/*                                               */
/* ********************************************* */

#include <unistd.h>
#include <stdlib.h>

void rev_wstr(char *str) {
    int end_index = 0; // Index of the null terminator.
    int word_start;
    int first_word = 1; // Flag for printing space between words.

    // Calculate the length of the string.
    while (str[end_index])
        end_index++;
    
    // Traverse the string backward.
    while (end_index >= 0) {
        // Skip trailing whitespace and the null terminator.
        while (end_index >= 0 && (str[end_index] == '\0' || str[end_index] == ' ' || str[end_index] == '\t'))
            end_index--;
        
        word_start = end_index;
        // Move backwards to find the beginning of the word.
        while (word_start >= 0 && str[word_start] != ' ' && str[word_start] != '\t')
            word_start--;
        
        // If a word is found, print it.
        if (end_index > word_start) {
            if (!first_word)
                write(1, " ", 1);
            write(1, str + word_start + 1, end_index - word_start);
            first_word = 0;
        }
        // Move end_index to the position of the space we just passed.
        end_index = word_start;
    }
}

int main(int argc, char **argv) {
    if (argc == 2)
        rev_wstr(argv[1]);
    write(1, "\n", 1);
    return (0);
}

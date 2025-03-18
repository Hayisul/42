/* ***************************************************************** */
/*                                                                   */
/*                             FT_SPLIT                              */
/*                                                                   */
/*   Splits a string into an array of words.                         */
/*   A word is defined as a sequence of non-whitespace characters.   */
/*   The resulting array is terminated with a NULL pointer.          */
/*                                                                   */
/*   Usage:                                                          */
/*       ./ft_split "Hello   world! This is an example."             */
/*                                                                   */
/*   Example Output:                                                 */
/*       Hello                                                       */
/*       world!                                                      */
/*       This                                                        */
/*       is                                                          */
/*       an                                                          */
/*       example.                                                    */
/*                                                                   */
/* ***************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_wordlen(char *str) {
    int i = 0;
    // Count characters until whitespace or end-of-string.
    while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        i++;
    return i;
}

char *word_dup(char *str) {
    int len = ft_wordlen(str);
    char *word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return NULL;
    // Duplicate the word character by character.
    for (int i = 0; i < len; i++)
        word[i] = str[i];
    word[len] = '\0';
    return word;
}

static char *skip_whitespace(char *str) {
    // Skip spaces, tabs, and newlines.
    while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;
    return str;
}

int count_words(char *str) {
    int num_words = 0;
    str = skip_whitespace(str);
    // Count words until the end of the string.
    while (*str) {
        num_words++;
        // Skip the current word.
        while (*str && *str != ' ' && *str != '\t' && *str != '\n')
            str++;
        // Skip the whitespace after the word.
        str = skip_whitespace(str);
    }
    return num_words;
}

void fill_words(char **array, char *str) {
    int word_index = 0;
    // Skip leading whitespace.
    str = skip_whitespace(str);
    // Fill the array with words extracted from the string.
    while (*str) {
        array[word_index] = word_dup(str);
        if (!array[word_index])
            return; // Allocation error: in production, consider freeing previously allocated words.
        word_index++;
        // Skip the current word.
        while (*str && *str != ' ' && *str != '\t' && *str != '\n')
            str++;
        // Skip the whitespace after the word.
        str = skip_whitespace(str);
    }
}

// Split a string into an array of words.
char **ft_split(char *str) {
    int num_words = count_words(str);
    char **array = malloc(sizeof(char *) * (num_words + 1));
    if (!array)
        return NULL;
    array[num_words] = NULL;
    fill_words(array, str);
    return array;
}

int main(int argc, char **argv) {
    if (argc == 2) {
        char **split = ft_split(argv[1]);
        if (!split) {
            fprintf(stderr, "Allocation error\n");
            return 1;
        }
        // Print each word in the split array.
        for (int i = 0; split[i]; i++)
            printf("%s\n", split[i]);
        // Free each allocated word.
        for (int i = 0; split[i]; i++)
            free(split[i]);
        // Free the array itself.
        free(split);
    }
    else {
        printf("\n");
    }
    return 0;
}

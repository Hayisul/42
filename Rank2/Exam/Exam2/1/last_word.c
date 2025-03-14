/* ***************************************************** */
/*                                                       */
/*                        LAST_WORD                      */
/*                                                       */
/*   Displays the last word of the provided string.      */
/*   A word is a sequence of non-space/tab characters.   */
/*                                                       */
/*   Usage:                                              */
/*       ./last_word "  Hello World  "                   */
/*                                                       */
/*   Example Output:                                     */
/*       World                                           */
/*                                                       */
/* ***************************************************** */

#include <unistd.h>

int main(int ac, char **av) {
    if (ac == 2) {
        int i = 0;
        char *str = av[1];

        // Move to the end of the string.
        while (str[i])
            i++;
        i--;
        // Skip trailing spaces and tabs.
        while ((str[i] == ' ' || str[i] == '\t') && i)
            i--;
        // Move backward to find the beginning of the last word.
        while (i && str[i] != ' ' && str[i] != '\t')
            i--;
        // If stopped at a space/tab, move one position forward.
        if (str[i] == ' ' || str[i] == '\t')
            i++;
        // Write the last word.
        while (str[i] && str[i] != ' ' && str[i] != '\t') {
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

/* ******************************************************* */
/*                                                         */
/*                       FIRST_WORD                        */
/*                                                         */
/*   Prints the first word from a given string argument.   */
/*   A word is defined as a sequence of characters         */
/*   separated by spaces or tabs.                          */
/*                                                         */
/*   Usage:                                                */
/*     ./first_word "   hello world"                       */
/*     Output: hello                                       */
/*                                                         */
/* ******************************************************* */

#include <unistd.h>

// Prints a single character to the standard output.
void ft_putchar(char c) {
    write(1, &c, 1);
}

int main(int argc, char **argv) {
    if (argc == 2) {
        int i = 0;
        char *str = argv[1];

        // Skip any leading spaces or tabs.
        while (str[i] == ' ' || str[i] == '\t')
            i++;

        // Print characters until a space, tab, or end-of-string is encountered.
        while (str[i] && str[i] != ' ' && str[i] != '\t')
            ft_putchar(str[i++]);
    }
    
    // Print a newline character at the end.
    ft_putchar('\n');
    return (0);
}

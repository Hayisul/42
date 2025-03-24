/* ************************************************************ */
/*                                                              */
/*                        STR_CAPITALIZER                       */
/*                                                              */
/*   Capitalizes the first letter of each word and lowercases   */
/*   the remaining letters. Words are defined as sequences of   */
/*   non-space/tab characters.                                  */
/*                                                              */
/*   Usage:                                                     */
/*       ./str_capitalizer "hello WORLD"                        */
/*                                                              */
/*   Example Output:                                            */
/*       Hello World                                            */
/*                                                              */
/* ************************************************************ */

#include <unistd.h>

void str_capitalizer(char *str) {
    while (*str) {
        // Write any leading spaces or tabs.
        while (*str && (*str == ' ' || *str == '\t')) {
            write(1, str, 1);
            str++;
        }
        // If a non-space character is encountered.
        if (*str) {
            // Capitalize the first letter if it is lowercase.
            if (*str >= 'a' && *str <= 'z')
                *str -= 32;
            write(1, str, 1);
            str++;
        }
        // Lowercase the remaining letters of the word.
        while (*str && *str != ' ' && *str != '\t') {
            if (*str >= 'A' && *str <= 'Z')
                *str += 32;
            write(1, str, 1);
            str++;
        }
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv) {
    if (argc == 1)
        write(1, "\n", 1);
    else {
        for (int i = 1; i < argc; i++)
            str_capitalizer(argv[i]);
    }
    return (0);
}